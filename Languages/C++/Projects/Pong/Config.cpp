#include "Vector.hpp"
#include "Config.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;

// constructor
Config::Config() {
    res = Vector(1300, 700);
    fps = 144, tickrate = 50;
    paddleWidth = 20, paddleHeight = 100, paddleSpeed = 20;
    ballRadius = 10, ballSpeed = 10;
    enableLeftBot = 0, enableRightBot = 1;
    botSkill = 3;
}

// set from args
void Config::getConfig(int argc, char *argv[]) {
    if(argc == 2 && strcmp(argv[1], "--help") == 0) {
        describeConfig();
        exit(EXIT_SUCCESS);
    }
    int val = 0;
    bool showConfig = false;
    for(int i = 1; i < argc; i++) {
        if (sscanf(argv[i], "res=%f,%f", &res.x, &res.y) == 2);
        else if(sscanf(argv[i], "fps=%d",      &val) == 1)     fps = val;
        else if(sscanf(argv[i], "tickrate=%d", &val) == 1)     tickrate = val;
        else if(sscanf(argv[i], "paddleWidth=%d",  &val) == 1) paddleWidth = val;
        else if(sscanf(argv[i], "paddleHeight=%d", &val) == 1) paddleHeight = val;
        else if(sscanf(argv[i], "paddleSpeed=%d",  &val) == 1) paddleSpeed = val;
        else if(sscanf(argv[i], "ballRadius=%d",   &val) == 1) ballRadius = val;
        else if(sscanf(argv[i], "ballSpeed=%d",    &val) == 1) ballSpeed = val;
        else if(sscanf(argv[i], "enableLeftBot=%d", &val) == 1)enableLeftBot = val;
        else if(sscanf(argv[i], "enableRightBot=%d",&val) == 1)enableRightBot = val;
        else if(sscanf(argv[i], "botSkill=%d", &val) == 1)     botSkill = val;
        else if(strcmp(argv[i], "--show") == 0) showConfig = true;
        else cout << "Option: " << argv[i] << " is not valid!\n";
    }
    if(showConfig) describeConfig();
}

// describe
void Config::describeConfig() {
    cout << "Settings chosen: \n" <<
            "res=" << res <<
            "fps=" << fps << endl <<
            "tickrate=" << tickrate << endl <<
            "paddleWidth=" << paddleWidth << endl <<
            "paddleHeight=" << paddleHeight << endl <<
            "paddleSpeed=" << paddleSpeed << endl <<
            "ballRadius=" << ballRadius << endl <<
            "ballSpeed=" << ballSpeed << endl <<
            "enableLeftBot=" << enableLeftBot << endl <<
            "enableRightBot=" << enableRightBot << endl <<
            "botSkill=" << botSkill << endl;
}