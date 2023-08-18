// NOTE!!!!!!
// Don't assume the below API follows good coding or JCA conventions.
// Follow your own best judgement for your own code.
// Feel free to rework this API if you like (not required).

#pragma once

#include <stdint.h>
#include <stdbool.h> 

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    // pin A0
    TEMPERATURE_SENSOR,

    // pin A1
    TEMPERATURE_SENSOR_REFERENCE, // referred to as vref

    // pin 5
    DOOR_SENSOR,

    // pin 12
    GAS_VALVE_STATE,

} input_t;

typedef enum
{
    // pin D12
    // When true, the valve is open (gas flowing).
    // When false, the valve is closed (no gas flowing).
    GAS_VALVE,

    // pin D8
    // when on, it sparks to ignite gas
    IGNITER,
} output_t;

void setup_api();



// returns voltage in millivolts
uint16_t read_voltage(input_t input);

// returns true for high
bool read_digital(input_t input);

// true for on, false for off
void set_output(output_t output, bool output_state);

// note that float %f format is not supported
void serial_printf(const char * format, ...);

//returns floating value after mapping for floating type range
float mapf(float x, float in_min, float in_max, float out_min, float out_max);

//returns signed integer value after mapping for floating type range for 'temperature in C'
//seperate function for 'temperature in C' because the other function returns float which makes unit testing
// for 'temperature in C' difficult
int16_t mapTemp(float x, float in_min, float in_max, float out_min, float out_max);

//Unit Test function for 'temperature in C'
void testTemperature(float input, float from_low, float from_high, float to_low, float to_high, int16_t output);


#ifdef __cplusplus
}
#endif
