/*
3) LED verde parpadea como en ejercicio 2. Mientras se pulse SW1, el LED verde se 
mantiene encendido. Al soltar SW1, vuelve a su ciclo normal.
*/

#define LED_TR3BOL D8
#define PULSADOR_1 D0

void setup() {
  pinMode(LED_TR3BOL, OUTPUT);
  pinMode(PULSADOR_1, INPUT);
}

void loop() {
  //Como el pulsador manda un estado bajo al ser pusaldor, su programacion sera: 
  if(digitalRead(PULSADOR_1) == LOW){
    digitalWrite(LED_TR3BOL, HIGH);
  }else {
    //ejercicio2
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_TR3BOL, HIGH);
    delay(150);
    // 150 milisegundo encendido 
    digitalWrite(LED_TR3BOL, LOW);
    delay(150);
    // 150 milisegundos apagados
  }

  delay(2000);
  // esperar 2 segundos antes de repetir
  }
  
}
