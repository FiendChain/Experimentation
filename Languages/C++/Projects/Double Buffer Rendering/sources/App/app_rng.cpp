#include "App.hpp"

void App::initRngEngine() {
    std::random_device rng_source;
    std::mt19937 engine(time(NULL));
    rng_engine = engine;
}