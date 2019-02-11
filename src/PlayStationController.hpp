#pragma once

#include <Arduino.h>

#define BUTTON_LEFT 0x0001
#define BUTTON_DOWN 0x0002
#define BUTTON_RIGHT 0x0004
#define BUTTON_UP 0x0008
#define BUTTON_START 0x0010
#define BUTTON_SELECT 0x0080
#define BUTTON_SQUARE 0x0100
#define BUTTON_CROSS 0x0200
#define BUTTON_CIRCLE 0x0400
#define BUTTON_TRIANGLE 0x0800
#define BUTTON_R1 0x1000
#define BUTTON_L1 0x2000
#define BUTTON_R2 0x4000
#define BUTTON_L2 0x8000

#define COMMAND_START 0x01
#define COMMAND_REQUEST 0x42
#define COMMAND_DELAY 1

class PlayStationController
{
  public:
    PlayStationController(byte dataPin, byte commandPin, byte attensionPin, byte clockPin);
    void setupPins();
    unsigned int read();
    byte send(byte out);

  private:
    byte _dataPin;
    byte _commandPin;
    byte _attensionPin;
    byte _clockPin;
    byte _response;
    byte _highByte;
    byte _lowByte;
};

// ref: https://gamesx.com/controldata/psxcont/psxcont.htm
