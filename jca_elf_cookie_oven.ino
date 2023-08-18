/*
We need your help to stop forest fires and bake tasty cookies!

See `requirements.md` for how to help.

Then check `notes.md`.
*/
#include "api.h"
#include "timer.h"


////////////setting up timer objects/instances of their classes/////////////
timer_debounce_switch debounce_timer;//non blocking timer to debounce slide switch
timer_igniter igniter_timer;// timer for turning on igniter for a set time
timer_periodical_print print_timer;//timer to print inputs periodically



//Function to call when timer for turning off igniter is activated
void igniter_off() 
{
 set_output(IGNITER, false); 
}

void setup() {
  Serial.begin(115200);
  setup_api();

  Serial.println("Elf oven 2000 starting up.");
  serial_printf("Days without fire incident: %i\n", 0);


//Function call for Unit Test of mapf funtion used to calculate temperature in C
  testTemperature(0.45, 0.45, 4.05, -10, 300, -10);//test successful
  testTemperature(4.95, 0.55, 4.95, -10, 300, 300);//test successful
  testTemperature(1.84, 0.45, 4.05, -10, 300, 109);//test successful  
  testTemperature(1.70, 0.55, 4.95, -10, 300, 71);//test successful  

}


void loop() {
//setting up 1ms timer to implement debouncing for sider switch
  debounce_timer.SetTimeout(1, main_operation);

//setting up 1sec timer for printing inputs periodically
  print_timer.SetTimeout(1000, print_periodical);

//activating all 3 timers
  debounce_timer.run();
  print_timer.run();
  igniter_timer.run();

}


//Function to call for 1ms timer to implement debouncing for sider switch 
void main_operation() {

//mapping inputs
  float vref = mapf(read_voltage(TEMPERATURE_SENSOR_REFERENCE), 0, 5000, 4.5, 5.5);
  float sensor_voltage = mapf(read_voltage(TEMPERATURE_SENSOR), 0, 5000, vref*10/100, vref*90/100);
  float temperature = mapf(sensor_voltage, vref*10/100, vref*90/100, -10, 300);

// sample the state of the door and gas valve
  bool door_state = read_digital(DOOR_SENSOR);
  bool gas_valve_state = read_digital(GAS_VALVE_STATE);

//setting up required conditions for turning the oven on or off
  if (door_state == false && temperature < 180  && gas_valve_state == false)
  {
  //Turning on the oven
    set_output(GAS_VALVE, true);
    set_output(IGNITER, true);
    Serial.println("oven is turned on");

  //Setting up 5sec timer to turn off igniter
    igniter_timer.SetTimeout(5000, igniter_off);
  }
  else if (door_state == true || temperature >= 180)
  {
  //Turning off the oven
    set_output(GAS_VALVE, false);
      
  }
}

//Function to call when 1 sec timer for printing inputs is activated
void print_periodical() {

//mapping inputs
  float vref = mapf(read_voltage(TEMPERATURE_SENSOR_REFERENCE), 0, 5000, 4.5, 5.5);
  float sensor_voltage = mapf(read_voltage(TEMPERATURE_SENSOR), 0, 5000, vref*10/100, vref*90/100);
  float temperature = mapf(sensor_voltage, vref*10/100, vref*90/100, -10, 300);

  Serial.print("sensor_voltage_ref :");
  Serial.println(vref);

  Serial.print("sensor_voltage :");
  Serial.println(sensor_voltage);


  Serial.print("Temperature in C:");
  Serial.println(temperature);

// sample the state of the door
  bool door_state = read_digital(DOOR_SENSOR);

  if (door_state == true)
  {
    Serial.println("Door is open");
  }
  else if (door_state == false)
  {
    Serial.println("Door is closed");
  }
}

