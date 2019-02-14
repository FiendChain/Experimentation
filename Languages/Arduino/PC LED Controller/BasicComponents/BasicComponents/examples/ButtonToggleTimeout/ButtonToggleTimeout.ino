// button that indicates change
// time between changes is a minimum of the timeout duration
#include <BasicComponents.h>
#include <BasicComponents/Button.hpp>
#include <BasicComponents/Timer.hpp>
#include <BasicComponents/LED.hpp>

bc::Button button(10);
bc::LED led(13);
bc::Timer timer(500);

void setup()
{

}

void loop()
{
    if (button.GetState() && timer.Check())
    {
        int value = led.GetValue() > 0 ? 0 : 255;
        led.SetValue(value);
    }
}