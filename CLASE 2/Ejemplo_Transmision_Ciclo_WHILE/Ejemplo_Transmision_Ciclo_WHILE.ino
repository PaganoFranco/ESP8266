// Ejemplo Transmision Ciclo WHILE
#define SW1 D0
#define SW2 D3

void setup() {
  delay(400);
  Serial.begin(115200);
  Serial.println("\n");
  Serial.println("Hola Equipo IoT !");
}

int i = 0;
void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(SW1)==LOW){
    Serial.println(i++);
    delay(50);
  }
  while(digitalRead(SW2)==LOW){
    Serial.println(i--);
    delay(50);
  }
}
