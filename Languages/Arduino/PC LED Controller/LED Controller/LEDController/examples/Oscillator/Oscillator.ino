#include <BasicComponents.h>
#include <BasicComponents/LED.hpp>
#include <BasicComponents/Timer.hpp>
#include <ILEDController.hpp>
#include <LEDControllers/Oscillator.hpp>

bc::LED led(13);
bc::Timer timer(5);
Oscillator oscillator(100, 255, 1);

void setup()
{

}

void loop()
{
    if (timer.Check())
    {
        int value = oscillator.GetValue();
        led.SetValue(value);
        oscillator.Update();
    }
}
