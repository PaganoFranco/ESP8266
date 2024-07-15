#define LED_TR3BOL D8

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Configura el pin LED_BUILTIN (LED integrado) como una salida.
  pinMode(LED_TR3BOL, OUTPUT);   // Configura el pin LED_TR3BOL (D8) como una salida.
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Enciende el LED integrado (pone el pin en estado ALTO).
  digitalWrite(LED_TR3BOL, HIGH);   // Enciende el LED conectado al pin D8 (pone el pin en estado ALTO).
  delay(1000);                      // Espera 1 segundo (1000 milisegundos).
  digitalWrite(LED_BUILTIN, LOW);   // Apaga el LED integrado (pone el pin en estado BAJO).
  digitalWrite(LED_TR3BOL, LOW);    // Apaga el LED conectado al pin D8 (pone el pin en estado BAJO).
  delay(1000);                      // Espera 1 segundo (1000 milisegundos).
}

