#define PULSADOR_1 D0  // Define PULSADOR_1 como el pin D0.
#define PULSADOR_2 D3  // Define PULSADOR_2 como el pin D3.
#define LED_TR3BOL D8  // Define LED_TR3BOL como el pin D8.

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Configura el pin LED_BUILTIN (LED integrado) como una salida.
  pinMode(PULSADOR_1, INPUT);    // Configura el pin PULSADOR_1 como una entrada.
  pinMode(LED_TR3BOL, OUTPUT);   // Configura el pin LED_TR3BOL como una salida.
  pinMode(PULSADOR_2, INPUT);    // Configura el pin PULSADOR_2 como una entrada.
}

void loop() {
  if (digitalRead(PULSADOR_1) == HIGH)  // Lee el estado del pin PULSADOR_1. Si está en estado ALTO (presionado):
    digitalWrite(LED_BUILTIN, HIGH);    // Enciende el LED integrado (pone el pin en estado ALTO).
  else
    digitalWrite(LED_BUILTIN, LOW);     // Si el pin PULSADOR_1 no está en estado ALTO (no presionado), apaga el LED integrado (pone el pin en estado BAJO).

  if (digitalRead(PULSADOR_2) == HIGH)  // Lee el estado del pin PULSADOR_2. Si está en estado ALTO (presionado):
    digitalWrite(LED_TR3BOL, HIGH);     // Enciende el LED TR3BOL (pone el pin en estado ALTO).
  else
    digitalWrite(LED_TR3BOL, LOW);      // Si el pin PULSADOR_2 no está en estado ALTO (no presionado), apaga el LED TR3BOL (pone el pin en estado BAJO).
}


