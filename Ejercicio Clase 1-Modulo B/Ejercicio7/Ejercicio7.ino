/*
7) Mientras esté pulsado SW1, el LED verde parpadea con PWM: Ton=20us, 
Tpwm=100us. Mientras esté pulsado SW2, el LED verde parpadea con PWM: 
Ton=80us, Tpwm=100us. Se prioriza SW1 sobre SW2
*/

#define LED_TR3BOL D8 // LED Verde
#define PULSADOR_1 D0 // SW1
#define PULSADOR_2 D3 // SW2

int TiempoPrendido1 = 20;
int TiempoApagano1 = 100;
int TiempoPrendido2 = 80;
int TiempoApagano2 = 100;


void setup() {
  pinMode(LED_TR3BOL, OUTPUT);
  pinMode(PULSADOR_1, INPUT_PULLUP); // Se recomienda usar INPUT_PULLUP para botones
  pinMode(PULSADOR_2, INPUT_PULLUP); // Se recomienda usar INPUT_PULLUP para botones
}

void loop() {
  if(digitalRead(PULSADOR_1)==LOW){
    // Al presionar SW1:
    digitalWrite(LED_TR3BOL, HIGH);
    delay(TiempoPrendido1);
      // El led verde prendera por 20us
    digitalWrite(LED_TR3BOL, LOW);
    delay(TiempoApagano1);
      // El led verde se apagara por 100us
  } else if(digitalRead(PULSADOR_2)==LOW){
    // Al presionar SW2:
    digitalWrite(LED_TR3BOL, HIGH);
    delay(TiempoPrendido2);
      // El led verde prendera por 80us
    digitalWrite(LED_TR3BOL, LOW);
    delay(TiempoApagano2);
      // El led verde se apagara por 100us
  } else{
    // En caso que no se presione ningun pulsador el led verde se mantiene apagado.
    digitalWrite(LED_TR3BOL, LOW);
  }

}
