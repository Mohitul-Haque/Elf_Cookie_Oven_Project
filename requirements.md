You are designing the control system for an oven that hard working elves 
will use to bake tasty cookies. Mmm cookies.

The controller should try to maintain an oven temperature of 180 Celsius.
For this example code, the oven should simply be turned on if the 
temperature is too low, and turned off if the temperature is too high.

# Elves' fancy clothes are highly combustible
A number of elves have had their clothes set a blaze while reaching into ovens to 
remove cookies. To make matters worse, the tastiest cookies are all baked in tall
dry Oak trees. While this makes for funny movies, the elf union requires that all
ovens must automatically shut off whenever the oven door is open. They can resume
operation as soon as the door is closed again. Santa is currently being sued by
the B.C. government for starting many forest fires. He also hasn't read many 
management books and has threatened to put you on the naughty list unless your
design can operate safely and reliably.

# System I/O
## Inputs to your system
- oven temperature sensor
- oven door sensor

## Outputs of your system
- gas valve control
- gas igniter control

# Input Details
## Temperature Sensor
The temperature sensor is capable of sensing from -10 Celsius to 300 Celsius.

The temperature sensor outputs two voltages:
* a reference voltage called `vref`. See `TEMPERATURE_SENSOR_REFERENCE` in api.h.
* a signal voltage that is relative to `vref`. See `TEMPERATURE_SENSOR` in api.h.

When operating properly, the temperature sensor will output a `vref` between 4.5 and 5.5 volts.
It is normal for `vref` to fluctuate within this range.

The below table shows how to calculate the temperature based on the sensor signal and `vref`.

| Sensor Output Signal |     Temperature      |
|----------------------|----------------------|
|    < 10% of vref     |        ??????        |
|      10% of vref     | -10 °C (or lower)    |
|      90% of vref     | 300 °C (or higher)   |
|    > 90% of vref     |        ??????        |

The sensor output signal varies linearly between -10 °C and 300 °C.

This type of sensor output is common for analog voltage sensors that are transmitted
more than a few feet.

## Door Sensor
The door sensor outputs a logic low when the door is closed, and logic high (5 volts) when open.
You can use the `read_digital()` api.h function for the door sensor.

# Output Details
To heat the oven, the gas valve should be opened and the igniter turned on.
The igniter should be automatically turned off after 5 seconds.

# Verification
For easier verification, please print the following info periodically:
* oven temperature sensor `vref` voltage
* oven temperature sensor signal voltage
* oven temperature in degrees Celsius

You can print more info if you like as well.

# Notes
Don't forget to check `notes.md`