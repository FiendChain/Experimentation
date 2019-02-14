#ifndef SERIALPORT_H
#define SERIALPORT_H

#define ARDUINO_WAIT_TIME 2000
#define MAX_DATA_LENGTH 255

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

class SerialPort
{
private:
    HANDLE handler;
    bool connected;
    COMSTAT status;
    DWORD errors;
public:
    SerialPort(const char *portName, unsigned baudRate, bool reset=false); 
    ~SerialPort();

    int readSerialPort(void *buffer, unsigned int buf_size);
    bool writeSerialPort(void *buffer, unsigned int buf_size);
    bool isConnected() const;
};

#endif // SERIALPORT_H