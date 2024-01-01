#include <Arduino.h>

//Variables definitions
const int red_Led = 2;
const int green_Led = 3;
const int yellow_Led = 4;
int heart_rate= 150;

//Functions setup
void setup(){
    pinMode(red_Led, OUTPUT);
    pinMode(green_Led, OUTPUT);
    pinMode(yellow_Led, OUTPUT);
}

//Functions loop
void loop(){

    //Heart rate High
    while (heart_rate >= 150){
        digitalWrite(red_Led, HIGH);
        delay(500);
        digitalWrite(red_Led, LOW);
        delay(500);
    }

    //Heart rate Normal
    while (heart_rate < 150 && heart_rate > 50){
        digitalWrite(green_Led, HIGH);
        delay(500);
        digitalWrite(green_Led, LOW);
        delay(500);
    }

    //Heart rate Low
    while (heart_rate <= 50){
        digitalWrite(yellow_Led, HIGH);
        delay(500);
        digitalWrite(yellow_Led, LOW);
        delay(500);
    }
}
