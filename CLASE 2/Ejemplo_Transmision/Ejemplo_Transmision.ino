char letra = 'a';

void setup() {
  delay(400);
  Serial.begin(115200);
  Serial.println("\n");
  Serial.println("Hola Equipo IoT !");
}

void loop() {
  Serial.println(letra++);
  delay(1000);
}
