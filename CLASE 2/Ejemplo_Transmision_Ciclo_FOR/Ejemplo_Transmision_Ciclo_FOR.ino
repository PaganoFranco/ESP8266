// Ejemplo Transmision ciclo FOR
void setup() {
  delay(400);
  Serial.begin(115200);
  Serial.println("\n");
  Serial.println("Hola Equipo IoT !");
}

void loop() {
  for(int i=0; i<100; i++){
    Serial.println(i);
    delay(50);
  }
  delay(2000);
  for(int i = 100; i >= 0; i--){
    Serial.println(i);
    delay(50);
  }
  delay(2000);
}
