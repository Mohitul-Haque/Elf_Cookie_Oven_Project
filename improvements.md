1. Included "pinMode(5, INPUT_PULLUP)" in setup_api() which would perform internal pullup of 
the pin 5 which is needed for digital input reading.

2. Added 'GAS_VALVE_STATE' value in the input_t enumeration. This was necessary to get the state
of the gas valve to include in the conditional statement of the main program for turning oven on 
or off and the 5sec timer  of igniter

3. Added some other functions, such as, mapf() which returns floating value after mapping input 
temperature sensor values for floating type range, testTemperature() which is a unit test function 
for testing temperature

4. Added a seperate header file timer.h which contains three timer classes that was used to 
implement different functionalities in the main program
