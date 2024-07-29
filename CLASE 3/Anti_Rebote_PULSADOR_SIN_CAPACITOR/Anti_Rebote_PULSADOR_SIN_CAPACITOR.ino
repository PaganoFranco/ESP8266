int contador = 0;

void ICACHE_RAM_ATTR rutinaP2() {
  contador++;
}

void setup() {
  delay(400);
  Serial.begin(115200);
  Serial.println("\n\nPrueba anti Rebote");
  attachInterrupt(SW_2, rutinaP2, FALLING);
}

void loop() {
  Serial.println(contador);
  delay(500);
}
