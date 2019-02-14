#include <EEPROM.h>
#define BAUD_RATE 9600

class Entity
{
  private:
    float mX, mY;
  public:
    Entity(float x=0, float y=0) {
      mX = x;
      mY = y;
    }
    inline void setX(float x) { mX = x; } 
    inline void setY(float y) { mY = y; }
    inline float getX() const { return mX; }  
    inline float getY() const { return mY; }
    void print() {
      Serial.print(F("<Entity> x: "));
      Serial.print(mX);
      Serial.print(F(" y:"));
      Serial.println(mY);
    }
};

void setup()
{
  Serial.begin(BAUD_RATE);
  Serial.println(sizeof(Entity));
  Entity e(10, 10);
  EEPROM.put(0, e);
  e.print();
  Entity e1;
  EEPROM.get(0, e1);
  e1.print();
}

void loop()
{
  
}

