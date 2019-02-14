#include <BasicComponents.h>
#include <BasicComponents/Timer.hpp>
#include <BasicComponents/LED.hpp>

bc::Timer timer(100);
bc::LED led(13);

void setup()
{

}

void loop()
{
    if (timer.Check())
    {
        int value = led.GetValue() > 0 ? 0 : 255;
        led.SetValue(value);
    }
}