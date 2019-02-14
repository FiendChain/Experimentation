#include <StandardCplusplus.h>

#include <BasicComponents.h>
#include <BasicComponents/LED.hpp>
#include <BasicComponents/Timer.hpp>

#include <ILEDController.hpp>

#include <LEDControllers/Oscillator.hpp>
#include <CommandCLI/OscillatorCLI.hpp>
#include <PersistentObjects/OscillatorPersistence.hpp>

#include <LEDControllers/TextToLED/TextToLED.hpp>
#include <LEDControllers/TextToLED/TapCodeEncoder.hpp>
#include <LEDControllers/TextToLED/MorseCodeEncoder.hpp>
#include <CommandCLI/TextToLEDCLI.hpp>
#include <PersistentObjects/TextToLEDPersistence.hpp>

#include <LEDControllers/Slider.hpp>
#include <CommandCLI/SliderCLI.hpp>
#include <PersistentObjects/SliderPersistence.hpp>

#include <LEDControllers/SteadyState.hpp>

#include <ControllerManager/ControllerManager.hpp>

#define BAUD_RATE 9600
#define BUFFER_SIZE 256

#define MANAGER_ADDR 0
#define TOTAL_MORSE_CODES 36

const char* StandardMorseCodeTable[TOTAL_MORSE_CODES] = {
    // alphabet
    ".-",   // A: 0
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--..", // Z: 25
    // numbers
    "-----",// 0: 26
    ".----",// 1
    "..---",// 2
    "...--",// 3
    "....-",// 4
    ".....",// 5
    "-....",// 6
    "--...",// 7
    "---..",// 8
    "----.",// 9: 35
};

int TapCodeTable[26][2] = {
//  A      B      C      D      E    
  {1,1}, {1,2}, {1,3}, {1,4}, {1,5},
//  F      G      H      I      J     K/C
  {2,1}, {2,2}, {2,3}, {2,4}, {2,5}, {1,3},
//  L      M      N      O      P
  {3,1}, {3,2}, {3,3}, {3,4}, {3,5},
//  Q      R      S      T      U
  {4,1}, {4,2}, {4,3}, {4,4}, {4,5},
//  V      W      X      Y      Z
  {5,1}, {5,2}, {5,3}, {5,4}, {5,5},
};

char serialBuffer[BUFFER_SIZE] = {0};

bc::LED led(11);
bc::Timer controllerTimer(10);

// module manager
ControllerManager manager(MANAGER_ADDR); // oscillator
// oscillator
Oscillator            *oscillator            = new Oscillator();
OscillatorCLI         *oscillatorCLI         = new OscillatorCLI(oscillator);
OscillatorPersistence *oscillatorPersistence = new OscillatorPersistence(oscillator, manager.GetAddrEnd());
// slider
Slider            *slider            = new Slider();
SliderCLI         *sliderCLI         = new SliderCLI(slider);
SliderPersistence *sliderPersistence = new SliderPersistence(slider, oscillatorPersistence->GetAddrEnd());
// morse code
MorseCodeEncoder     *morseCodeEncoder     = new MorseCodeEncoder(StandardMorseCodeTable);
TextToLED            *morseCode            = new TextToLED(morseCodeEncoder);
TextToLEDCLI         *morseCodeCLI         = new TextToLEDCLI(morseCode);
TextToLEDPersistence *morseCodePersistence = new TextToLEDPersistence(morseCode, sliderPersistence->GetAddrEnd());
// tap code
TapCodeEncoder       *tapCodeEncoder     = new TapCodeEncoder(&TapCodeTable);
TextToLED            *tapCode            = new TextToLED(tapCodeEncoder);
TextToLEDCLI         *tapCodeCLI         = new TextToLEDCLI(tapCode);
TextToLEDPersistence *tapCodePersistence = new TextToLEDPersistence(tapCode, morseCodePersistence->GetAddrEnd());
// off
SteadyState *off = new SteadyState(0);
// on
SteadyState *on = new SteadyState(255);

void setup()
{
    Serial.begin(BAUD_RATE);
    manager.AddModule((ControllerModule){ off,        nullptr,       nullptr,               "off" });
    manager.AddModule((ControllerModule){ on,         nullptr,       nullptr,               "on" });
    manager.AddModule((ControllerModule){ slider,     sliderCLI,     sliderPersistence,     "slider" });
    manager.AddModule((ControllerModule){ morseCode,  morseCodeCLI,  morseCodePersistence,  "morse code" });
    manager.AddModule((ControllerModule){ tapCode,    tapCodeCLI,    tapCodePersistence,    "tap code" });
    manager.AddModule((ControllerModule){ oscillator, oscillatorCLI, oscillatorPersistence, "oscillator" });
    manager.Load();
}

void loop()
{
    // check CLI
    if (Serial.available() > 0)
    {
        int totalBytes = Serial.readBytes(serialBuffer, sizeof(serialBuffer));
        if (totalBytes > 0) {
            serialBuffer[totalBytes] = 0;
            ResponseType response = manager.ParseCommand(serialBuffer, totalBytes);
            switch (response)
            {
            case ACCEPTED:
            case DATA_CHANGED:
                manager.Save();
                break;
            case REJECTED:
                Serial.println(F("Invalid command"));
                break;
            }
        }
    }
    // update led
    if (controllerTimer.Check())
    {
        int value = manager.GetValue();
        led.SetValue(255-value);
        manager.Update();
    }
}
