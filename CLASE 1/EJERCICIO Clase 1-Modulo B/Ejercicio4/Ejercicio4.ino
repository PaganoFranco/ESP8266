/*
4) Mientras esté pulsado SW1, el LED verde está encendido. Mientras esté pulsado 
SW2, el LED verde está apagado. Se prioriza SW2 sobre SW1.
*/

#define LED_TR3BOL D8 // LED Verde
#define PULSADOR_1 D0 // SW1
#define PULSADOR_2 D3 // SW2

void setup() {
  pinMode(LED_TR3BOL, OUTPUT);
  pinMode(PULSADOR_1, INPUT);
  pinMode(PULSADOR_2, INPUT);

}

void loop() {
  // Condicionamos a presionar 
  if(digitalRead(PULSADOR_2) == LOW) {
    //pulsado SW2, el LED verde esta apagado.
    digitalWrite(LED_TR3BOL, LOW);
  }else if (digitalRead(PULSADOR_1)==LOW) {
    // pulsado SW1, el LED verde esta encendido
    digitalWrite(LED_TR3BOL, HIGH);
  }
}
