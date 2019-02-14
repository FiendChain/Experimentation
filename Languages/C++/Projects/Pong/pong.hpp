#ifndef PONG_H
#define PONG_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Vector.hpp"

using sf::RenderWindow;
using sf::Text;
using sf::Font;
using sf::Sound;
using sf::SoundBuffer;

namespace pong {

    class Paddle {
        public:
            Vector pos;     // Physics
            Vector vel;
            float dt;
            float width;    // Object props
            float height;
            float speed;
            static const int up;    // Control variables
            static const int down;
            Vector res;
            Paddle(float widthSet=20, float heightSet=100, float speedSet=10, 
                    Vector resSet=Vector(1300, 700));
            void draw(RenderWindow &app);
            void bound();
            void update();
            void move(int dir);
            void stop();
            bool checkYInside(float y);
            bool checkXInside(float x);
    };

    class Ball {
        public:
            Vector pos;     // Physics
            Vector vel;
            float dt;
            float radius;   // Properties
            float speed;
            float angleDeflection;
            Vector res;

            Ball(float radiusSet=10, float speedSet=10, Vector resSet=Vector(1300, 700));
            void update();
            void bounce(Paddle &p);
            void draw(RenderWindow &app);
            void showScore(RenderWindow &app);
        private:
            struct {
                int left, right;
                Text leftText, rightText;
                Font font;
            } score;
            struct {
                SoundBuffer buffer;
                Sound sound;
            } bounceSound;
        
            void bound();
            void reset();
            void setupScore();
            void playBounceSound();
            void setupSound();
    };

    class PaddleBot {
        public:
            PaddleBot(Ball &ballSet, Paddle &paddleSet, int skillSet=1);
            void movePaddle();

        private:
            Ball &ball;
            Paddle &paddle;
            int skill;
            bool inPosition;
            float predictCollision();
            bool checkDirection();
    };
};

#endif