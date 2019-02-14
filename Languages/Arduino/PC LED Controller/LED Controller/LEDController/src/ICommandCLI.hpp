#pragma once

enum ResponseType { ACCEPTED, DATA_CHANGED, REJECTED };

class ICommandCLI
{
    public:
        virtual ResponseType ParseCommand(char *buffer, int len) = 0;    
};