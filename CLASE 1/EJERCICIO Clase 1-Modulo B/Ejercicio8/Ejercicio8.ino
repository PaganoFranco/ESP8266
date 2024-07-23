/*
8) LED verde parpadea con PWM: Ton es igual a la lectura del potenciómetro RV1 
en ms. Tpwm es fijo de 1024 ms.
*/

#define LED_TR3BOL D8 // LED Verde
#define Pote_TR3 A0 // Potenciómetro
int TiempoPrendido;

void setup() {
  pinMode(LED_TR3BOL, OUTPUT);
}

void loop() {
  TiempoPrendido = analogRead(Pote_TR3); // Lee el valor del potenciómetro

  digitalWrite(LED_TR3BOL, HIGH);
  delay(TiempoPrendido); // Encendido por TiempoPrendido ms
  digitalWrite(LED_TR3BOL, LOW);
  delay(1024 - TiempoPrendido); // Apagado por el tiempo restante para completar 1024 ms
}

