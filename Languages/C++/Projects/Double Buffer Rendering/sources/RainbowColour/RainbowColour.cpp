#include "RainbowColour.hpp"

RainbowColour::RainbowColour(float _rate) 
    :rate(_rate),
     channelStates(3)
{
    r = 255, g = 0, b = 0, a = 200;
    channelStates[0] = IDLE;
    channelStates[1] = RISING;
    channelStates[2] = IDLE;
}

void RainbowColour::setRate(float _rate) {
    rate = _rate;
}

void RainbowColour::update() {
    for (int i = 0; i < channelStates.size(); i++) {
        ColourState &channel = channelStates.at(i);
        sf::Uint8 &curr = getColourByIndex(i);
        if (channel == RISING) {
            curr += rate;
            // if max reached, start decreasing previous channel
            if (curr >= MAX_RGB_CHANNEL) {
                curr = MAX_RGB_CHANNEL;
                channel = IDLE;
                getChannelStateByIndex(i-1) = FALLING;
            }
        // if falling and finished falling
        } else if (channel == FALLING) {
            curr -= rate;
            if (curr <= MIN_RGB_CHANNEL) {
                curr = MIN_RGB_CHANNEL;
                channel = IDLE;
                getChannelStateByIndex(i+2) = RISING;
            }
        }
    }
}

int RainbowColour::getWrappedIndex(int index, int size) {
    if (index < 0) {
        int multiplier = (-index/(float)size) + 1;
        index += multiplier*size;
    }
    // if overflow, get modulus
    if (index >= size) {
        index %= size;
    }
    return index;
}

sf::Uint8 &RainbowColour::getColourByIndex(int index) {
    // get colour
    index = getWrappedIndex(index, channelStates.size());
    switch(index) {
    case 0:
        return r;
    case 1:
        return g;
    case 2:
        return b;
    default:
        throw "Invalid colour channel";
    };
}

ColourState &RainbowColour::getChannelStateByIndex(int index) {
    index = getWrappedIndex(index, channelStates.size());
    return channelStates.at(index);
}