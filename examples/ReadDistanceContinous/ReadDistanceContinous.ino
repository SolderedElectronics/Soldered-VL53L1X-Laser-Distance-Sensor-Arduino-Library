/**
 **************************************************
 *
 * @file        ReadDistanceContinous.ino
 * @brief       Exmaple that shows how to use VL53_L1X library with VL53L1X sensor to read distance, best to use in low
 *              ambient light setting to get better results
 * @authors     @ soldered.com, Robert Peric
 * @link        www.solde.red/333064
 ***************************************************/

#include "VL53L1X-SOLDERED.h"

VL53_L1X sensor;

void setup()
{
    Serial.begin(115200);
    Serial.println("Serial Initialised");

    sensor.setTimeout(500);
    sensor.begin();

    // Use long distance mode and allow up to 50000 us (50 ms) for a measurement.
    // You can change these settings to adjust the performance of the sensor, but
    // the minimum timing budget is 20 ms for short distance mode and 33 ms for
    // medium and long distance modes. See the VL53L1X datasheet for more
    // information on range and timing limits.
    sensor.setDistanceMode(VL53L1X::Long);
    sensor.setMeasurementTimingBudget(50000);

    // Start continuous readings at a rate of one measurement every 50 ms (the
    // inter-measurement period). This period should be at least as long as the
    // timing budget.
    sensor.startContinuous(50);
}

void loop()
{
    Serial.print(String(sensor.read()) + "mm");  //Print reading
    if (sensor.timeoutOccurred()) //Check if sensor has been measuring longer than timeout period
    {
        Serial.print(" TIMEOUT");
    }

    Serial.println();
}
