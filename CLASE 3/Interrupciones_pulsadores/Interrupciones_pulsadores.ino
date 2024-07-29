#define LED_1 D4
#define LED_2 D8
#define SW_1 D0
#define SW_2 D3

void ICACHE_RAM_ATTR rutinaP2() {
  digitalWrite(LED_2, HIGH);

  // Mientras no suelte pulsador 2, espera.
  while(digitalRead(SW_2)==LOW);

  digitalWrite(LED_2, LOW);
}

void setup() {
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    // Se configuran las interruciones --> Estado o cambio de estado (LOW, HIGH)
    // Configuar, setear flanco, elegir pin
    // El SW1 tiene prioridad sobre SW2
    attachInterrupt(SW_2, rutinaP2, FALLING);
}

void loop() {
   // SW_1 hace CONSULTA. Puede perder eventos
  // 0 tardar hasta 3 segundos en detectar cambio
  if(digitalRead(SW_1)==HIGH) {
    digitalWrite(LED_1, HIGH);
  }
  else {
    digitalWrite(LED_1, LOW);
    delay(5000);
  }
}
