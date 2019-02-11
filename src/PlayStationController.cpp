#include "PlayStationController.hpp"

PlayStationController::PlayStationController(byte dataPin, byte commandPin, byte attensionPin, byte clockPin)
{
    _dataPin = dataPin;
    _commandPin = commandPin;
    _attensionPin = attensionPin;
    _clockPin = clockPin;
}

void PlayStationController::setupPins()
{
    pinMode(_dataPin, INPUT);
    digitalWrite(_dataPin, HIGH);

    pinMode(_commandPin, OUTPUT);
    digitalWrite(_commandPin, HIGH);

    pinMode(_attensionPin, OUTPUT);
    digitalWrite(_attensionPin, HIGH);

    pinMode(_clockPin, OUTPUT);
    digitalWrite(_clockPin, HIGH);
}

unsigned int PlayStationController::read()
{
    digitalWrite(_attensionPin, LOW);

    send(COMMAND_START);
    send(COMMAND_REQUEST);
    send(0x0);

    _lowByte = ~send(0x0);
    _highByte = ~send(0x0);

    digitalWrite(_attensionPin, HIGH);

    return ((_highByte << 8) | _lowByte);
}

byte PlayStationController::send(byte data)
{
    _response = 0;

    digitalWrite(_commandPin, (data & B00000001) ? HIGH : LOW);
    digitalWrite(_clockPin, LOW);
    delayMicroseconds(COMMAND_DELAY);
    if (digitalRead(_dataPin))
    {
        _response |= B10000000;
    }
    digitalWrite(_clockPin, HIGH);
    delayMicroseconds(COMMAND_DELAY);

    digitalWrite(_commandPin, (data & B00000010) ? HIGH : LOW);
    digitalWrite(_clockPin, LOW);
    delayMicroseconds(COMMAND_DELAY);
    if (digitalRead(_dataPin))
    {
        _response |= B01000000;
    }
    digitalWrite(_clockPin, HIGH);
    delayMicroseconds(COMMAND_DELAY);

    digitalWrite(_commandPin, (data & B00000100) ? HIGH : LOW);
    digitalWrite(_clockPin, LOW);
    delayMicroseconds(COMMAND_DELAY);
    if (digitalRead(_dataPin))
    {
        _response |= B00100000;
    }
    digitalWrite(_clockPin, HIGH);
    delayMicroseconds(COMMAND_DELAY);

    digitalWrite(_commandPin, (data & B00001000) ? HIGH : LOW);
    digitalWrite(_clockPin, LOW);
    delayMicroseconds(COMMAND_DELAY);
    if (digitalRead(_dataPin))
    {
        _response |= B00010000;
    }
    digitalWrite(_clockPin, HIGH);
    delayMicroseconds(COMMAND_DELAY);

    digitalWrite(_commandPin, (data & B00010000) ? HIGH : LOW);
    digitalWrite(_clockPin, LOW);
    delayMicroseconds(COMMAND_DELAY);
    if (digitalRead(_dataPin))
    {
        _response |= B00001000;
    }
    digitalWrite(_clockPin, HIGH);
    delayMicroseconds(COMMAND_DELAY);

    digitalWrite(_commandPin, (data & B00100000) ? HIGH : LOW);
    digitalWrite(_clockPin, LOW);
    delayMicroseconds(COMMAND_DELAY);
    if (digitalRead(_dataPin))
    {
        _response |= B00000100;
    }
    digitalWrite(_clockPin, HIGH);
    delayMicroseconds(COMMAND_DELAY);

    digitalWrite(_commandPin, (data & B01000000) ? HIGH : LOW);
    digitalWrite(_clockPin, LOW);
    delayMicroseconds(COMMAND_DELAY);
    if (digitalRead(_dataPin))
    {
        _response |= B00000010;
    }
    digitalWrite(_clockPin, HIGH);
    delayMicroseconds(COMMAND_DELAY);

    digitalWrite(_commandPin, (data & B10000000) ? HIGH : LOW);
    digitalWrite(_clockPin, LOW);
    delayMicroseconds(COMMAND_DELAY);
    if (digitalRead(_dataPin))
    {
        _response |= B00000001;
    }
    digitalWrite(_clockPin, HIGH);
    delayMicroseconds(COMMAND_DELAY);

    return _response;
}
