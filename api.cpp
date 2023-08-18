#include "api.h"
#include "Arduino.h"
#include <stdarg.h>
#include <stdio.h>
#include <math.h>

// NOTE!!!
// Don't assume the below API follows good coding or JCA conventions.
// Follow your own best judgement for your own code.
// Feel free to rework this API if you like (not required).

void setup_api()
{
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(5, INPUT_PULLUP);
}

// returns voltage in millivolts
uint16_t read_voltage(input_t input)
{
  if (input == TEMPERATURE_SENSOR)
  {
    return (uint32_t)analogRead(A0)* 5000 / 1023;
  }
  else if (input == TEMPERATURE_SENSOR_REFERENCE)
  {
    return (uint32_t)analogRead(A1)* 5000 / 1023;
  }
  else if (input == DOOR_SENSOR)
  {
    return (uint32_t)analogRead(A2);
  }
      else if (input == GAS_VALVE_STATE)
  {
    return (uint32_t)analogRead(A3);
  }

  return 0;
}

// returns true for high
bool read_digital(input_t input)
{
  if (input == TEMPERATURE_SENSOR)
  {
    return digitalRead(A0);
  }
  else if (input == TEMPERATURE_SENSOR_REFERENCE)
  {
    return digitalRead(A1);
  }
  else if (input == DOOR_SENSOR)
  {
    return digitalRead(5);
  }
  else if (input == GAS_VALVE_STATE)
  {
    return digitalRead(12);
  }

  return false;
}

// true for on, false for off
void set_output(output_t output, bool output_state)
{
  if (output == GAS_VALVE)
  {
    digitalWrite(12, output_state);
  }
  else if (output == IGNITER)
  {
    digitalWrite(8, output_state);
  }
}

void serial_printf(const char * format, ...)
{
  char buffer[256];
  va_list args;
  va_start(args, format);
  vsnprintf(buffer, 256, format, args);
  va_end (args);

  Serial.print(buffer);
}
//returns floating value after mapping for floating type range
float mapf(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//returns signed integer value after mapping for floating type range for 'temperature in C'
//seperate function for 'temperature in C' because the other function returns float which makes unit testing
// for 'temperature in C' difficult
int16_t mapTemp(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/*========================================================================*/
/*   Unit Test of mapf function used to calculate temperature in C                                                        */
/*========================================================================*/

void testTemperature(float input, float from_low, float from_high, float to_low, float to_high, int16_t output) 
{
    Serial.print("Testing temperature for different inputs from vref and sensor_voltage :"); 

    Serial.println((mapTemp(input, from_low, from_high, to_low, to_high) == output) ? "OK" : "ERROR");
}
/*========================================================================*/
/*                           End of Section                            */
/*========================================================================*/


