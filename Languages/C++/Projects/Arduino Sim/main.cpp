#include "Arduino.hpp"
#include <SFML/Graphics.hpp>

#include <vector>

int main(int argc, char *argv[]) 
{
    Arduino a(sf::Vector2f(1300, 700));
    std::vector<float> millis(a.TOTAL_PINS, 0);
    std::vector<float> cooldown(a.TOTAL_PINS, 0);
    std::vector<bool> state(a.TOTAL_PINS, true);
    for(int i = 0; i < a.TOTAL_PINS; i++)
    {
        cooldown[i] = 0.5f+i*0.25f;
    }
    while(a.run()) 
    {
        if(a.canExecute())
        {
            for(int i = 0; i < a.TOTAL_PINS; i++)
            {   
                if(a.getTime() - millis.at(i) >= cooldown.at(i))
                {
                    millis.at(i) = a.getTime();
                    state.at(i) = !state.at(i);
                }
                a.digitalWrite(i, state.at(i));
            }
        }
    }

    return 0;
}
