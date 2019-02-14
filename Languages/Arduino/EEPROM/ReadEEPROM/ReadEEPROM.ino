#include <EEPROM.h>
#define BAUD_RATE 9600

void readEEPROM(int rowLength=16)
{
  int len = EEPROM.length();
  Serial.print("Total bytes: ");
  Serial.println(len);
  for (int addr = 0; addr < len; addr++)
  {
    if (addr % rowLength == 0)
    {
      Serial.print(F("\n0x"));
      Serial.print(addr, HEX);
      Serial.print(F("\t"));
    }
    Serial.print(F("0x"));
    Serial.print(EEPROM.read(addr), HEX);
    Serial.print(F(" "));
  }
  
}

void setup()
{
  Serial.begin(BAUD_RATE);
  readEEPROM();
}

void loop()
{
  delay(1000);
}

