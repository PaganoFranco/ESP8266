#define PULSADOR_1 D0  // Define PULSADOR_1 como el pin D0.

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Configura el pin LED_BUILTIN (LED integrado) como una salida.
  pinMode(PULSADOR_1, INPUT);    // Configura el pin PULSADOR_1 como una entrada.
}

void loop() {
  if (digitalRead(PULSADOR_1) == HIGH) {  // Lee el estado del pin PULSADOR_1. Si está en estado ALTO (presionado):
     digitalWrite(LED_BUILTIN, HIGH);  // Enciende el LED integrado (pone el pin en estado ALTO).
  } else {
    digitalWrite(LED_BUILTIN, LOW);   // Si el pin PULSADOR_1 no está en estado ALTO (no presionado), apaga el LED integrado (pone el pin en estado BAJO).
  }
}


