#ifndef _FADING_RENDER_WINDOW_H_
#define _FADING_RENDER_WINDOW_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class FadingRenderWindow: public sf::RenderTexture {
    public:
        FadingRenderWindow(int _fadeRate=10);
        void updateFade();
        void reset();
        bool create(int x, int y);
    private:
        sf::RectangleShape alphamask;
        int fadeRate;
        bool awaitReset;
};

#endif