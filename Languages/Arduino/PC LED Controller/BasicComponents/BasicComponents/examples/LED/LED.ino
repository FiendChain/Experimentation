#include <BasicComponents/LED.hpp>

bc::LED led;

void setup()
{
    led.SetPin(13);
}

void loop()
{
    if (led.GetValue())
        led.SetValue(0);
    else
        led.SetValue(255);
    delay(1000);
}