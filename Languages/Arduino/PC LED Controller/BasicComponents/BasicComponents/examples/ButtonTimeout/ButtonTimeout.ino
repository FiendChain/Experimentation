#include <BasicComponents.h>
#include <BasicComponents/ButtonTimeout.hpp>
#include <BasicComponents/LED.hpp>

bc::ButtonTimeout button(10, 500);
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
}