#pragma once
#include "ControllerModule.hpp"
#include "../ICommandCLI.hpp"
#include "../ILEDController.hpp"
#include "../IPersistentObject.hpp"
#include <vector>

class ControllerManager: public ICommandCLI, public ILEDController, public IPersistentObject
{
    private:
        std::vector<ControllerModule> mModules;
        int mCurrentModule;
        const int mAddr;
    public:
        ControllerManager(int addr);
        void AddModule(ControllerModule module);
        ResponseType ParseCommand(char *buffer, int len);
        void Update();
        int GetValue() const;
        void Load();
        void Save();
        int GetSize() const { return sizeof(mCurrentModule); }
        int GetAddrStart() const { return mAddr; }
        int GetAddrEnd() const { return mAddr+GetSize(); }
    private:
        bool SelectModule(int index);
        void SaveAll();
        ControllerModule& GetCurrentModule();
};