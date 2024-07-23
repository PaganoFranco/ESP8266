//PWM con funcion de libreria y Senoidal
#define LED_1 D4
#define LED_2 D8

void setup() {
 pinMode(LED_1, OUTPUT);
 pinMode(LED_2, OUTPUT);
}

void lineal(){
    //Variacion lineal
  for(int pwm = 0; pwm<255; pwm ++){
    analogWrite(LED_1,pwm);
    analogWrite(LED_2,pwm);
    delay(10);
  }
  delay(2000);

  for(int pwm = 255; pwm >= 0 ; pwm --){
    analogWrite(LED_1,pwm);
    analogWrite(LED_2,pwm);
    delay(10);
  }
    delay(2000);
}

void senoidal(){
  // Variación senoidal ascendente
  for (int angle = 0; angle < 180; angle++) {
    float radian = radians(angle);
    int pwm = (sin(radian) * 255.0);
    analogWrite(LED_1, pwm);
    analogWrite(LED_2, pwm);
    delay(10);
  }
  delay(2000);

  // Variación senoidal descendente
  for (int angle = 180; angle >= 0; angle--) {
    float radian = radians(angle);
    int pwm = (sin(radian) * 255.0);
    analogWrite(LED_1, pwm);
    analogWrite(LED_2, pwm);
    delay(10);
  }
  delay(2000);
}

void loop() {
  senoidal();
}
