void setup() {
  // Inicializamos el pin LED_BUILTIN como salida.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Colocamos el pin en estado ALTO
  delay(1000);                      // Esperar 1 segundo
  digitalWrite(LED_BUILTIN, LOW);   // Colocamos el pun en estado BAJO
  delay(1000);                      // Esperar 1 segundo
}
