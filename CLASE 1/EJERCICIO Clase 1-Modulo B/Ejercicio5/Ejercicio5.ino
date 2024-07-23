/*
5) Al pulsar y soltar SW1, el led verde cambia de estado.
*/

#define LED_TR3BOL D8 // LED Verde
#define PULSADOR_1 D0 // SW1
#define PULSADOR_2 D3 // SW2
int ledState = LOW; // Estado inicial del LED
int lastButtonState = HIGH; // Estado anterior del botón
int currentButtonState; // Estado actual del botón

void setup() {
  pinMode(LED_TR3BOL, OUTPUT);
  pinMode(PULSADOR_1, INPUT_PULLUP); // Se recomienda usar INPUT_PULLUP para botones
  pinMode(PULSADOR_2, INPUT_PULLUP); // Se recomienda usar INPUT_PULLUP para botones
  Serial.begin(115200); // Inicia la comunicación serie para mostrar los resultados
}

void loop() {
  currentButtonState = digitalRead(PULSADOR_1);

  if (currentButtonState == LOW && lastButtonState == HIGH) {
    // El botón ha sido pulsado
    ledState = !ledState; // Cambia el estado del LED
    digitalWrite(LED_TR3BOL, ledState); // Escribe el nuevo estado del LED
    delay(50); // Pequeño retardo para debouncing
  }

  lastButtonState = currentButtonState; // Guarda el estado actual del botón para la próxima iteración
}

