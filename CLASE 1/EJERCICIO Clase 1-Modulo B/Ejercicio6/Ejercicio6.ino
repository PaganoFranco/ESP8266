/*
6) Al pulsar SW1, el led verde permanece encendido aunque se suelte SW1.
Al pulsar SW2, el led verde permanece apagado aunque se suelte SW2.
*/

#define LED_TR3BOL D8 // LED Verde
#define PULSADOR_1 D0 // SW1
#define PULSADOR_2 D3 // SW2


void setup() {
  pinMode(LED_TR3BOL, OUTPUT);
  pinMode(PULSADOR_1, INPUT_PULLUP); // Se recomienda usar INPUT_PULLUP para botones
  pinMode(PULSADOR_2, INPUT_PULLUP); // Se recomienda usar INPUT_PULLUP para botones
}

void loop() {
  
  if(digitalRead(PULSADOR_1) == LOW){
    //Al presionar SW1 prende el led verde
    digitalWrite(LED_TR3BOL, HIGH);
  } else if (digitalRead(PULSADOR_2) == LOW){
    //Al presionar SW1 apaga el led verde
    digitalWrite(LED_TR3BOL, LOW);
  }

}
