#include "entrypoint.hpp"
#include <HID-Project.h>

#include "PlayStationController.hpp"

#define REVERSE 1

#ifndef REVERSE
#define SCRATCH_1 KEY_LEFT_SHIFT
#define SCRATCH_2 KEY_LEFT_CTRL
#else
#define SCRATCH_1 KEY_LEFT_CTRL
#define SCRATCH_2 KEY_LEFT_SHIFT
#endif

#define KEY_1 'z'
#define KEY_2 's'
#define KEY_3 'x'
#define KEY_4 'd'
#define KEY_5 'c'
#define KEY_6 'f'
#define KEY_7 'v'
#define KEY_SELECT 'q'
#define KEY_START KEY_ENTER

PlayStationController controller(7, 6, 5, 4);

void setup()
{
    TIMSK0 = 0;

    NKROKeyboard.begin();
    controller.setupPins();
}

void loop()
{
    unsigned int data;

    while (1)
    {
        data = controller.read();

        if (data & BUTTON_DOWN)
        {
            NKROKeyboard.add(SCRATCH_1);
        }
        else
        {
            NKROKeyboard.remove(SCRATCH_1);
        }
        if (data & BUTTON_UP)
        {
            NKROKeyboard.add(SCRATCH_2);
        }
        else
        {
            NKROKeyboard.remove(SCRATCH_2);
        }
        if (data & BUTTON_SQUARE)
        {
            NKROKeyboard.add(KEY_1);
        }
        else
        {
            NKROKeyboard.remove(KEY_1);
        }
        if (data & BUTTON_L1)
        {
            NKROKeyboard.add(KEY_2);
        }
        else
        {
            NKROKeyboard.remove(KEY_2);
        }
        if (data & BUTTON_CROSS)
        {
            NKROKeyboard.add(KEY_3);
        }
        else
        {
            NKROKeyboard.remove(KEY_3);
        }
        if (data & BUTTON_R1)
        {
            NKROKeyboard.add(KEY_4);
        }
        else
        {
            NKROKeyboard.remove(KEY_4);
        }
        if (data & BUTTON_CIRCLE)
        {
            NKROKeyboard.add(KEY_5);
        }
        else
        {
            NKROKeyboard.remove(KEY_5);
        }
        if (data & BUTTON_L2)
        {
            NKROKeyboard.add(KEY_6);
        }
        else
        {
            NKROKeyboard.remove(KEY_6);
        }
        if (data & BUTTON_LEFT)
        {
            NKROKeyboard.add(KEY_7);
        }
        else
        {
            NKROKeyboard.remove(KEY_7);
        }
        if (data & BUTTON_SELECT)
        {
            NKROKeyboard.add(KEY_SELECT);
        }
        else
        {
            NKROKeyboard.remove(KEY_SELECT);
        }
        if (data & BUTTON_START)
        {
            NKROKeyboard.add(KEY_START);
        }
        else
        {
            NKROKeyboard.remove(KEY_START);
        }
        NKROKeyboard.send();
    }
}
