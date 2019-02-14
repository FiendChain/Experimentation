#ifndef _RAINBOW_COLOUR_H_
#define _RAINBOW_COLOUR_H_

#include <SFML/Graphics.hpp>
#include <vector>

#define MAX_RGB_CHANNEL 255
#define MIN_RGB_CHANNEL 0

enum ColourState {
    RISING,
    FALLING,
    IDLE
};

class RainbowColour: public sf::Color {
    public:
        RainbowColour(float _rate=1);
        void setRate(float _rate);
        void update();
    private:
        float rate;
        std::vector<ColourState> channelStates;
        int getWrappedIndex(int index, int size);
        sf::Uint8 &getColourByIndex(int index);
        ColourState &getChannelStateByIndex(int index);
};

#endif