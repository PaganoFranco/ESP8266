//PWM con funcion de libreria
#define LED_1 D4
#define LED_2 D8

void setup() {
 pinMode(LED_1, OUTPUT);
 pinMode(LED_2, OUTPUT);
}

void loop() {
  analogWrite(LED_1,75);
  analogWrite(LED_2,75);
  delay(2000);
  analogWrite(LED_1,125);
  analogWrite(LED_2,125);
  delay(2000);
  analogWrite(LED_1,255);
  analogWrite(LED_2,255);
  delay(2000);

}
