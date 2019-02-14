#ifndef _ARDUINO_H_
#define _ARDUINO_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

typedef std::vector<sf::Vertex> VertexArray;

typedef struct {
    VertexArray points;
    float xScale;
    float yScale;
    int xOffset;
    int yOffset;
} Graph;

class Arduino 
{
    public:
        // variables / consts
        const int HIGH;               
        const int LOW;
        const int TOTAL_PINS;           
        // methods
        Arduino(sf::Vector2f res, int fps = 30);
        ~Arduino();
        bool run();                 // Execution
        bool canExecute();  
        void delay(float seconds);  // Modification
        void digitalWrite(int pin, bool state);
        bool digitalRead(int pin);
        void analogWrite(int pin, int val);
        int analogRead(int pin);
        float getTime();        // millis equivalent
    private:  
        sf::RenderWindow app;   // window
        sf::Vector2f res;
        const int fps;          // time
        const float dt;
        float time;
        float delayRemain;
        struct {                // pausing
            bool state;
            float delay;
            float cooldown;
        } pause;
        const int fontSize;     // text
        sf::Font font;          
        sf::Text timeText;
        struct {                    // pin info
            std::vector<sf::Text> text;
            std::vector<sf::RectangleShape> led;
            std::vector<Graph> graph;
            std::vector<int> val;
        } pins;  
        struct {                // info about the graph to display
           int currentGraph;
           float changeDelay;   // delay remaining for changing pins
           float scaleDelay;    // delay remaining for changing x-scale
           float cooldown; 
           sf::Text text;
        } graphInfo;
        // methods
        void initFont();        // font used by text
        void initTime();        // time elapsed
        void initPins();        // pin rendering
        void initGraphText();   // graph text
        void initGraphs();      // graphs
        void updateGraph(Graph& g, float val);
        void transformGraph(Graph& g, float xScale, float yScale, float xOffset = 0, float yOffset = 0);     
        void update();          // updates everything
        void show();            // displays all elements
        bool checkPin(int pin); // checks a pin
        void handleInputs();    // handles keypresses
};


#endif
