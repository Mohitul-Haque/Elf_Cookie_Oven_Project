#include <Wire.h>
int OFFSET = 70;

int val;


#define LED1 9

void setup(){   
    pinMode(LED1,OUTPUT);
    Serial.begin(9600);
    Serial.println("Voltage: ");   
    
}

void loop(){       
    float voltage;       
    val = analogRead(A0);
    voltage = map(val,0,1023,0,2500) - OFFSET; //mV
//    temp=val_1/4.092;
//    val_1=(int)temp;  
//    val_2=((val_1%100)/10);
    Serial.print(voltage/100);
    Serial.println(" V");
    delay(1000); 
}
