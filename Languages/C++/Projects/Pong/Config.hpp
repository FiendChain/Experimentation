#include "Vector.hpp"

class Config {
    public:
        // options
        Vector res;
        int fps, tickrate;
        int paddleWidth, paddleHeight, paddleSpeed;
        int ballRadius, ballSpeed;
        bool enableLeftBot, enableRightBot;
        int botSkill;
        // constructor
        Config();
        // set from args
        void getConfig(int argc, char *argv[]);
        // describe
        void describeConfig();
};