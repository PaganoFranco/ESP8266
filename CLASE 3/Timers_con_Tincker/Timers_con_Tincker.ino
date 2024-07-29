#include "Ticker.h"

Ticker t1, t2, t3;

#define LED_1 D4
#define LED_2 D8

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  t1.attach(1, loop1);
  t2.attach(0.5, loop2);
  t3.attach(3, loop3);
  Serial.begin(115200);
}

void loop1() {
    digitalWrite(LED_1, !digitalRead(LED_1));
}

void loop2() {
    digitalWrite(LED_2, !digitalRead(LED_2));
}

void loop3(){
  Serial.println("HOLA");
}

void loop() {
  

}
