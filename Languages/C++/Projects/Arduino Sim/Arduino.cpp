#include "Arduino.hpp"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <sstream>
#include <string>
#include <vector> 

Arduino::Arduino(sf::Vector2f res, int fps) 
: app(sf::VideoMode(res.x, res.y), "Arduino"),
  res(res),
  HIGH(255), LOW(0),    // Constants
  TOTAL_PINS(15),       // pins
  pins(),
  time(0),              // time
  fps(fps),
  dt(1/(float)fps),
  delayRemain(0),
  fontSize(20)          // font size
{
    app.setFramerateLimit(fps);
    pause = {
        false, 
        0,
        0.5f,
    };
    initFont();
    initTime();
    initPins();
    initGraphs();
    initGraphText();
}  

Arduino::~Arduino() 
{
    if(app.isOpen())
    {
        app.close();
    }
}

// executing
bool Arduino::run()  
{
    if(app.isOpen()) 
    {
        app.clear(sf::Color::Black);
        sf::Event event;
        while(app.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed) 
            {
                app.close();
                return false;
            }
        }
        if(canExecute())
        {
            update();
        }
        handleInputs(); 
        show();
        app.display();
        return true;
    }
    else 
    {
        return false;
    }
}

bool Arduino::canExecute()
{
    if(delayRemain > 0)     return false;
    else if(pause.state)    return false;
    return true;
}

// auduino commands
void Arduino::digitalWrite(int pin, bool state)
{
    if(checkPin(pin)) 
    {
        pins.val.at(pin) = state ? HIGH : LOW;
    }
}

bool Arduino::digitalRead(int pin)
{
    if(checkPin(pin)) 
    {   
        return pins.val.at(pin);
    }
    return false;
}

void Arduino::analogWrite(int pin, int val)
{
    if(checkPin(pin)) 
    {
        pins.val.at(pin) = val;
    }
}

int Arduino::analogRead(int pin)
{
    if(checkPin(pin)) 
    {
        return pins.val.at(pin);
    }
    return 0;
}

void Arduino::delay(float seconds)
{
    delayRemain = seconds;
}

// get the current time
float Arduino::getTime() 
{
    return time; 
}

// pin checking
bool Arduino::checkPin(int pin)
{
    if(pin < 0 || pin >= TOTAL_PINS)
    {
        std::cerr << "pin: " << pin << " is not a valid pin" << std::endl;
        return false;
    }
    return true;
}

// text elements
void Arduino::initFont()
{
    font.loadFromFile("Arial.ttf");
}

// time text
void Arduino::initTime() 
{
    timeText.setCharacterSize(fontSize); 
    timeText.setColor(sf::Color::White); 
    timeText.setFont(font);
}

// pins
void Arduino::initPins()
{
    // all pin info
    pins.val = std::vector<int>(TOTAL_PINS, 0);
    pins.text = std::vector<sf::Text>(TOTAL_PINS);
    pins.led = std::vector<sf::RectangleShape>(TOTAL_PINS);
    // properties of text
    int offset = 5*fontSize;
    int spacing = fontSize;
    // make pin text
    for(int i = 0; i < TOTAL_PINS; i++) 
    {
        sf::Text& text = pins.text[i];
        sf::RectangleShape& led = pins.led[i];
        int height = (fontSize+spacing)*i + offset;
        text.setCharacterSize(fontSize);    // text
        text.setColor(sf::Color::White);
        text.setFont(font);
        text.setPosition(0, height);
        text.setString(std::to_string(i));
        led.setFillColor(sf::Color::Red);   // led
        led.setSize(sf::Vector2f(fontSize, fontSize));
        led.setPosition(50, height+fontSize/10.0f);
    }
}
 
// graph text
void Arduino::initGraphText()
{
    // Setup graph info
    graphInfo.currentGraph = 0;
    graphInfo.cooldown = 0.1;
    graphInfo.changeDelay = 0;
    graphInfo.scaleDelay = 0;
    // Setup graph text
    sf::Text& text = graphInfo.text;
    text.setColor(sf::Color::White);
    text.setCharacterSize(fontSize);
    text.setPosition(res.x/2.0f, res.y/10.0f);
    text.setFont(font);
}

// graphs
void Arduino::initGraphs()
{
    // add info to graphInfo
    float xOffset = 10*fontSize;
    float yOffset = res.y/1.5f;
    // graph properties
    int totalRes = res.x - xOffset;
    float timeWindow = 100;  // time of preview
    int totalPoints = fps * timeWindow; // each tick renders one  point
    float xScale = totalRes / (float)totalPoints;
    float yScale = (res.y/HIGH)/4.0f;
    
    // initialise the graphs
    pins.graph = std::vector<Graph>(TOTAL_PINS);
    for(auto& g: pins.graph)            // load graphs
    {
        g.points = VertexArray(totalPoints);
        g.xScale = xScale;
        g.yScale = yScale;
        g.xOffset = xOffset;
        g.yOffset = yOffset;
        for(int i = 0; i < totalPoints; i++)
        {
            sf::Vertex& v = g.points[i];
            float x = g.xScale*i + g.xOffset;
            v.position = sf::Vector2f(x, g.yOffset);
            v.color = sf::Color::White;
        }
    }
}

void Arduino::updateGraph(Graph& g, float val)
{
    g.points.erase(g.points.begin());
    for(auto& v: g.points) 
    {
        v.position.x -= g.xScale;
    }
    sf::Vertex v(sf::Vector2f((g.xScale*(g.points.size()+1))+g.xOffset, -(g.yScale*val)+g.yOffset), sf::Color::White);
    g.points.push_back(v);
}

void Arduino::transformGraph(Graph& g, float xScale, float yScale, float xOffset, float yOffset)
{
    for(auto& v: g.points) 
    {
        v.position.x = (v.position.x-g.xOffset)*xScale + (g.xOffset + xOffset);
        v.position.y = (v.position.y-g.yOffset)*yScale + (g.yOffset + yOffset);
    }
    g.xScale *= xScale;
    g.yScale *= yScale;
    g.xOffset += xOffset;
    g.yOffset += yOffset;
}

// update function
void Arduino::update()
{   
    // update delay
    if(delayRemain > 0) 
    {
        delayRemain -= dt;
    }
    // update time only if there is no delay and no pause
    else if(!pause.state)    
    {
        time += dt;
        std::ostringstream str;
        str << "Time: " << std::to_string(time);
        timeText.setString(str.str());
    }
    // update the pin leds and graph
    for(int i = 0; i < TOTAL_PINS; i++)
    {
        pins.led[i].setFillColor(sf::Color(50,205,50,pins.val[i]));
        updateGraph(pins.graph[i], pins.val[i]);
    }
}

// show function
void Arduino::show()
{
    // time
    app.draw(timeText); 
    // pin leds
    for(int i = 0; i < TOTAL_PINS; i++) 
    {
        app.draw(pins.text[i]);
        app.draw(pins.led[i]);
    }
    // graph text
    app.draw(graphInfo.text);   
    // graph pin
    VertexArray& plot = pins.graph[graphInfo.currentGraph].points;
    app.draw(plot.data(), plot.size(), sf::LinesStrip);
    
}

// handle inputs
void Arduino::handleInputs()
{
    // update graph to show
    if(graphInfo.changeDelay <= 0)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket))
        {
            graphInfo.currentGraph++;
            graphInfo.changeDelay = graphInfo.cooldown;
            if(graphInfo.currentGraph >= TOTAL_PINS)
            {
                graphInfo.currentGraph = 0;
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket))
        {   
            graphInfo.currentGraph--;
            graphInfo.changeDelay = graphInfo.cooldown;
            if(graphInfo.currentGraph < 0)
            {
                graphInfo.currentGraph = TOTAL_PINS-1;
            }
        }
    }
    else
    {
        graphInfo.changeDelay -= dt;
    }
    // update graph text
    std::ostringstream str;
    str << "Graphing pin: " << graphInfo.currentGraph;
    graphInfo.text.setString(str.str());
    // update graph scale
    if(graphInfo.scaleDelay <= 0)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            graphInfo.scaleDelay = graphInfo.cooldown;
            for(auto& g: pins.graph)
            {
                transformGraph(g, 0.5f, 1);
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            graphInfo.scaleDelay = graphInfo.cooldown;
            for(auto& g: pins.graph)
            {
                transformGraph(g, 2.0f, 1);
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            graphInfo.scaleDelay = graphInfo.cooldown;
            for(auto& g: pins.graph)
            {
                transformGraph(g, 1, 0.5f);
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            graphInfo.scaleDelay = graphInfo.cooldown;
            for(auto& g: pins.graph)
            {
                transformGraph(g, 1, 2.0f);
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            graphInfo.scaleDelay = graphInfo.cooldown;
            for(auto& g: pins.graph)
            {
                transformGraph(g, 1, 1, 0, -HIGH*g.yScale*0.25f);
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            graphInfo.scaleDelay = graphInfo.cooldown;
            for(auto& g: pins.graph)
            {
                transformGraph(g, 1, 1, 0, HIGH*g.yScale*0.25f);
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            graphInfo.scaleDelay = graphInfo.cooldown;
            for(auto& g: pins.graph)
            {
                transformGraph(g, 1, 1, -res.x*g.xScale*0.25f, 0);
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            graphInfo.scaleDelay = graphInfo.cooldown;
            for(auto& g: pins.graph)
            {
                transformGraph(g, 1, 1, res.x*g.xScale*0.25f, 0);
            }
        }
    }
    else
    {
        graphInfo.scaleDelay -= dt;
    }
    // pause the arduino
    if(pause.delay <= 0)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            pause.state = !pause.state;
            pause.delay = pause.cooldown;
        }
    }
    else
    {
        pause.delay -= dt;
    }
}




