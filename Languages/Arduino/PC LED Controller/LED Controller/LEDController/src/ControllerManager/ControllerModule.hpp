#pragma once
#include "../ICommandCLI.hpp"
#include "../ILEDController.hpp"
#include "../IPersistentObject.hpp"

struct ControllerModule
{
    ILEDController *controller;
    ICommandCLI *CLI;
    IPersistentObject *persistence;
    const char *name;
};