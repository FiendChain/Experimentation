#pragma once

class IPersistentObject
{
    public:
        virtual void Load() = 0;
        virtual void Save() = 0;
        virtual int GetAddrStart() const = 0;
        virtual int GetAddrEnd() const = 0;
        virtual int GetSize() const = 0;
};