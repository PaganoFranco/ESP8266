//Ejemplo de TRANSMISION y RECEPCION

void setup() {
  delay(400);
  Serial.begin(115200);
  Serial.println("\n");
  Serial.println("Hola Equipo IoT !");
  Serial.println("Prueba de RECEPCION de comandos");
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  if(Serial.available() > 0){
    char letra = Serial.read();
    Serial.println(letra);
    if(letra == 'A') digitalWrite(LED_BUILTIN, LOW);
    else if(letra == 'B') digitalWrite(LED_BUILTIN, HIGH);
  }
  delay(1000);
}
