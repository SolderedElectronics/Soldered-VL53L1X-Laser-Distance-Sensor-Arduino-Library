/**
 **************************************************
 *
 * @file        VL53L1X-SOLDERED.cpp
 * @brief       Soldered VL53L1X Arduino Library for controling VL53L1X Sensor.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     @ soldered.com, Robert Peric
 ***************************************************/


#include "VL53L1X-SOLDERED.h"

/**
 * @brief                   Sensor specific native constructor.
 *
 * @param int _pin          Example parameter.
 */
VL53_L1X::VL53_L1X(int _pin)
{
    pin = _pin;
    native = 1;
}

/**
 * @brief                   Sensor specific native constructor.
 *
 */
VL53_L1X::VL53_L1X()
{
}

/**
 * @brief                   Overloaded function for virtual in base class to initialize sensor specific.
 */
void VL53_L1X::initializeNative()
{
    pinMode(pin, INPUT);
}
