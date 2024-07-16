// 1) LED verde parpadea cíclicamente: medio segundo encendido y 3 segundos apagado
#define LED_TR3BOL D8
void setup() {
  pinMode(LED_TR3BOL, OUTPUT);
}

void loop() {
  digitalWrite(LED_TR3BOL, HIGH);
  delay(500);
  // Medio segundo encendido 
  digitalWrite(LED_TR3BOL, LOW);
  delay(3000);
  // Tres segundos apagados
}
