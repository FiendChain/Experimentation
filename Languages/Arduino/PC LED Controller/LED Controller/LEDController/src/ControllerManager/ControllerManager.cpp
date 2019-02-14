#include "ControllerManager.hpp"
#include <string.h>
#include <stdlib.h>
#include <EEPROM.h>
#include <Arduino.h>

ControllerManager::ControllerManager(int addr)
    : mAddr(addr),
      mCurrentModule(0),
      mModules(0)
{

}

void ControllerManager::AddModule(ControllerModule module)
{
    mModules.push_back(module);
}

ResponseType ControllerManager::ParseCommand(char *buffer, int len)
{
    // get help from selected
    if (strncmp(buffer, "helpsel", 7) == 0)
    {
        if (GetCurrentModule().CLI)
        {
            ResponseType resp = GetCurrentModule().CLI->ParseCommand("help", 4);
            switch (resp)
            {
            case REJECTED:
                Serial.print(GetCurrentModule().name);
                Serial.print(F(" module has no help guide!"));
                return ACCEPTED;
            }
            return resp;
        }
        Serial.print(GetCurrentModule().name);
        Serial.println(F(" module has no commands!")); 
        return ACCEPTED;
    }
    // show help
    if (strncmp(buffer, "help", 4) == 0)
    {
        Serial.println(F("list     \tLists available controllers"));
        Serial.println(F("select %d\tSelects a controller"));
        Serial.println(F("helpsel  \tGet help from selected controller"));
        Serial.println(F("help     \tGet help"));
        return ACCEPTED;
    }
    // list selectors
    if (strncmp(buffer, "list", 4) == 0) 
    {
        if (mModules.size() <= 0) {
            Serial.println(F("No controllers"));
            return ACCEPTED;
        }

        for (int i = 0; i < mModules.size(); i++)
        {
            if (i == mCurrentModule) Serial.print(F(">"));
            Serial.print(i);
            Serial.print(F(" "));
            Serial.println(mModules.at(i).name);
        }
        return ACCEPTED;
    }
    // select module
    int index;
    if (sscanf(buffer, "select %d", &index) == 1) 
    {
        if (SelectModule(index))
        {
            Serial.print(F("selected "));
            Serial.print(mModules.at(index).name);
            Serial.print(F("["));
            Serial.print(index);
            Serial.println(F("]"));
            return DATA_CHANGED;
        }

        Serial.print(F("invalid controller id: "));
        Serial.println(index);
        return ACCEPTED;
    }
    // defer command to selected controller
    if (GetCurrentModule().CLI)
    {
        ResponseType response = GetCurrentModule().CLI->ParseCommand(buffer, len);
        switch (response)
        {
        case DATA_CHANGED:
            if (GetCurrentModule().persistence)
            {
                GetCurrentModule().persistence->Save();
            }
            return ACCEPTED;
        case ACCEPTED:
        case REJECTED:
            return response;
        }
    }

    return REJECTED;
}

void ControllerManager::Update() 
{
    GetCurrentModule().controller->Update();
}

int ControllerManager::GetValue() const
{
    return GetCurrentModule().controller->GetValue();
}

void ControllerManager::Load()
{
    int index = 0;
    EEPROM.get(mAddr, index);
    if (!SelectModule(index))
    {
        mCurrentModule = 0;
    }
    Save();
    for (ControllerModule& module: mModules)
    {
        if (module.persistence)
            module.persistence->Load();
    }
}

void ControllerManager::Save()
{
    EEPROM.put(mAddr, mCurrentModule);
}

void ControllerManager::SaveAll()
{
    Save();
    for (ControllerModule& module: mModules)
    {
        if (module.persistence)
            module.persistence->Save();
    }
}

bool ControllerManager::SelectModule(int index)
{
    if (index < 0 || index >= mModules.size())
    {
        return false;
    } 
    mCurrentModule = index;
    return true;
}

ControllerModule& ControllerManager::GetCurrentModule()
{
    return mModules.at(mCurrentModule);
}