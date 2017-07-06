#ifndef H_BRIDGE_H
#define H_BRIDGE_H
#include "errors.h"
#include "mbed.h"

#define MAX_HB 2

ReturnCode HB_init(int index, PinName in1, PinName in2, PinName nsleep);
ReturnCode HB_coast(int index);
ReturnCode HB_reverse(int index, float speed);
ReturnCode HB_forward(int index, float speed);
ReturnCode HB_brake(int index);
ReturnCode HB_BIT(int index);

#endif // H_BRIDGE_H