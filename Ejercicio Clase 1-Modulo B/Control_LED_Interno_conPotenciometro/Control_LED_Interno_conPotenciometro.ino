int sensorPin = A0;   // Selecciona el pin de entrada para el potenciómetro (sensor analógico).
int ledPin = D4;      // Selecciona el pin para el LED.
int sensorValue = 0;  // Variable para almacenar el valor proveniente del sensor.

void setup() {
  // Declara el ledPin como una salida:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Lee el valor del sensor:
  sensorValue = analogRead(sensorPin);
  // Enciende el ledPin:
  digitalWrite(ledPin, HIGH);
  // Detiene el programa por <sensorValue> milisegundos:
  delay(sensorValue);
  // Apaga el ledPin:
  digitalWrite(ledPin, LOW);
  // Detiene el programa por <sensorValue> milisegundos:
  delay(sensorValue);
}
