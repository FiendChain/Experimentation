#include <BasicComponents.h>
#include <BasicComponents/Button.hpp>
#include <BasicComponents/LED.hpp>

bc::Button button(10);
bc::LED led(13);

void setup()
{

}

void loop()
{
    if (button.GetState())
        led.SetValue(255);
    else
        led.SetValue(0);
    delay(10);
}