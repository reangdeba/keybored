#include <Keyboard.h>
#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */
 
CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2,5);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_2_6 = CapacitiveSensor(2,6);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_2_7 = CapacitiveSensor(2,7);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_2_8 = CapacitiveSensor(2,8);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_2_9 = CapacitiveSensor(2,9);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

int Threshold = 500;        // Set the threshold, differs in different machines, use it wisely


void setup()                    
{
   cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example

  pinMode(A0, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  
   Serial.begin(9600);
   Keyboard.begin();
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_2_3.capacitiveSensor(30);
    long total2 =  cs_2_4.capacitiveSensor(30);
    long total3 =  cs_2_5.capacitiveSensor(30);
    long total4 =  cs_2_6.capacitiveSensor(30);
    long total5 =  cs_2_7.capacitiveSensor(30);
    long total6 =  cs_2_8.capacitiveSensor(30);
    long total7 =  cs_2_9.capacitiveSensor(30);
   
    if(total1 > Threshold){total1=1; digitalWrite(12, HIGH);releaseAll(); Keyboard.press('z'); delay(500);  }
    else{total1=0;  digitalWrite(12, LOW);}

    if(total2 > Threshold){total2=1;  digitalWrite(10, HIGH);releaseAll();Keyboard.press('x');delay(500);}
    else{total2=0;  digitalWrite(10, LOW);}

    if(total3 > Threshold){total3=1; digitalWrite(13, HIGH);releaseAll();Keyboard.press('c');delay(500);}
    else{total3=0;  digitalWrite(13, LOW);}
    
    if(total4 > Threshold){total4=1; digitalWrite(A0, HIGH);releaseAll();Keyboard.press('v');delay(500);}
    else{total4=0;  digitalWrite(A0, LOW);}
    
    if(total5 > Threshold){total5=1;  digitalWrite(A1, HIGH);releaseAll();Keyboard.press('b');delay(500);}
    else{total5=0;  digitalWrite(A1, LOW);}
    
    if(total6 > Threshold){total6=1;  digitalWrite(A2, HIGH);releaseAll();Keyboard.press('n');delay(500);}
    else{total6=0;  digitalWrite(A2, LOW);}
    
    if(total7 > Threshold){total7=1;  digitalWrite(A3, HIGH);releaseAll();Keyboard.press('m');delay(500);}
    else{total7=0;  digitalWrite(A3, LOW);}
    delay(10);                            
}
