/*
9) LED verde parpadea como en ejercicio 6. LED azul parpadea de manera 
complementaria al LED verde. Esto significa, ambos tienen el mismo Tpwm pero el 
Ton de uno es igual al Toff del otro.
*/

/*
6) Al pulsar SW1, el led verde permanece encendido aunque se suelte SW1.
Al pulsar SW2, el led verde permanece apagado aunque se suelte SW2.
*/

#define LED_TR3BOL D8 // LED Verde
#define LED_AZUL D4 // LED Azul
#define PULSADOR_1 D0 // SW1
#define PULSADOR_2 D3 // SW2


void setup() {
  pinMode(LED_TR3BOL, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(PULSADOR_1, INPUT_PULLUP); // Se recomienda usar INPUT_PULLUP para botones
  pinMode(PULSADOR_2, INPUT_PULLUP); // Se recomienda usar INPUT_PULLUP para botones
}

void loop() {
  if(digitalRead(PULSADOR_1)==LOW){
    while(digitalRead(PULSADOR_2)==HIGH){
      digitalWrite(LED_TR3BOL, HIGH);
      digitalWrite(LED_AZUL, HIGH);
      delay(200);
      digitalWrite(LED_TR3BOL, LOW);
      digitalWrite(LED_AZUL, LOW);
      delay(200);
    }
  } else if (digitalRead(PULSADOR_2)==LOW){
      digitalWrite(LED_AZUL, HIGH);
      digitalWrite(LED_TR3BOL, LOW);
    }

}
