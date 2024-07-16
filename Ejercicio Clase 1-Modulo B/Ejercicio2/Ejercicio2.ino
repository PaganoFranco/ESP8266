/*
 2) LED verde parpadea 3 veces rápido: 150ms encendido y 150ms apagado. 
 Luego está 2 segundos apagado. Esto se repite cíclicamente.
*/
#define LED_TR3BOL D8
void setup() {
  pinMode(LED_TR3BOL, OUTPUT);
}

// Implementacion de ciclo FOR
void loop() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_TR3BOL, HIGH);
    delay(150);
    // 150 milisegundo encendido 
    digitalWrite(LED_TR3BOL, LOW);
    delay(150);
    // 150 milisegundos apagados
  }

  delay(2000);
  // esperar 2 segundos antes de repetir
}

/*
// Implementacion sin ciclos
void loop() {
  digitalWrite(LED_TR3BOL, HIGH);
  delay(150);
  // 150 milisegundo encendido 
  digitalWrite(LED_TR3BOL, LOW);
  delay(150);
  // 150 milisegundos apagados
    digitalWrite(LED_TR3BOL, HIGH);
  delay(150);
  // 150 milisegundo encendido 
  digitalWrite(LED_TR3BOL, LOW);
  delay(150);
  // 150 milisegundos apagados
    digitalWrite(LED_TR3BOL, HIGH);
  delay(150);
  // 150 milisegundo encendido 
  digitalWrite(LED_TR3BOL, LOW);
  delay(150);
  // 150 milisegundos apagados

  delay(2000);
  // esperar 2 segundos antes de repetir
}
*/