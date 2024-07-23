#define analogPIN   A0
#define LED_1       D4
#define LED_2       D8
#define PULSADOR_1  D0
#define PULSADOR_2  D3

void setup() {
  delay(400);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  Serial.begin(115200);
  Serial.println("\nPrueba Analog, PWM e Input");
}

float analog = 0;
int PWM = 0;

void loop() {
  // ----- Analógico -----
  analog = analogRead(analogPIN);
  Serial.println(analog);

  // ----- PWM -----
  if (analog < 20) analog = 0;
  PWM = 255 * analog / 1024.0;
  analogWrite(LED_1, PWM);
  analogWrite(LED_2, PWM);

  // ----- Inputs -----
  if (digitalRead(PULSADOR_1) == LOW) Serial.println("SW1!!");
  if (digitalRead(PULSADOR_2) == LOW) Serial.println("SW2!!");

  delay(250);
}
