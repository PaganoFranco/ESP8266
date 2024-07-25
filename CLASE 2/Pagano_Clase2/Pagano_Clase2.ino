// Credenciales del proyecto
#define BLYNK_TEMPLATE_ID "TMPL2QogB2E41"
#define BLYNK_TEMPLATE_NAME "TEMPLATEESP"
#define BLYNK_AUTH_TOKEN "1a-IIquCSQwgkHzl_GfcKFYwD5RtQi60"

#define Pot A0
#define LED_VERDE D8
#define BUZZER D5
#define SW1 D0
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS D6 // Pin donde está conectado el sensor DS18B20
OneWire oneWire(ONE_WIRE_BUS); // Inicializa instancia de clase OneWire para comunicarse con el sensor
DallasTemperature sensors(&oneWire); // Ídem con DallasTemperature para interactuar con el sensor

float lecturaPotenciometro = 0;
float conversion = 0;
unsigned long tiempoInicio;
char ssid[] = "EL_PROFESOR"; // Red WiFi
char pass[] = "14654647"; // Contraseña red WiFi

void setup() {
  pinMode(Pot, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(SW1, INPUT_PULLUP); // Configura el pulsador SW1 con resistencia pull-up interna
  tiempoInicio = millis(); // Almacena el tiempo de inicio en milisegundos
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); // Conecta a la red WiFi y a Blynk
  sensors.begin(); // Inicializa la comunicación con los sensores DS18B20
}

/*
1) Imprimir por puerto serie un número decimal que varíe entre 0 y 1, proporcional a la posición 
del potenciómetro (RV1).
*/
void Ejercicio1() {
  lecturaPotenciometro = analogRead(Pot);
  conversion = lecturaPotenciometro / 1024.0; // Mapea de 0 a 1
  Serial.println(conversion);

  delay(1); // Espera 1 ms
}

/*
2) Imprimir por puerto serie un número decimal que varíe entre 100 y 200, proporcional a la 
posición del potenciómetro (RV1). Cuando sea mayor a 150 que se prenda el LED azul y 
cuando sea menor o igual a 150 que se apague
*/
void Ejercicio2(){
  lecturaPotenciometro = analogRead(Pot);
  conversion = lecturaPotenciometro * (100.0 / 1024.0) + 100.0; // Mapea de 100 a 200
  Serial.println(conversion);
  
  if (conversion > 150.0) {
    digitalWrite(LED_BUILTIN, HIGH); // Enciende el LED azul
  } else {
    digitalWrite(LED_BUILTIN, LOW); // Apaga el LED azul
  }

  delay(1); // Espera 1 ms antes de repetir el ciclo
}

/*
3) Lograr una variación lineal en la intensidad de brillo del LED verde. Usar Tpwm= 1 ms y 
tiempo de ciclo de 2 segundos (1 segundo desde el apagado hasta el brillo máximo y 1 
segundo más hasta el apagado completo).
*/
void Ejercicio3(){
  // Calculamos el tiempo transcurrido desde el inicio del ciclo, para que el mismo dure 2 segundos (2000 ms) 
  unsigned long tiempoActual = millis();
  unsigned long tiempoTranscurrido = (tiempoActual - tiempoInicio) % 2000; // % 2000 asegura que el tiempo se reinicie cada 2 segundos

  float PWM;

  if (tiempoTranscurrido < 1000) { // Primer segundo: de apagado a brillo máximo
    PWM = (tiempoTranscurrido / 1000.0) * 255; // Calcula el brillo de 0 a 255
  } else { // Segundo segundo: de brillo máximo a apagado
    PWM = ((2000 - tiempoTranscurrido) / 1000.0) * 255; // Calcula el brillo de 255 a 0
  }

  analogWrite(LED_VERDE, (int)PWM); // Ajusta el brillo del LED verde

  delay(1); // Espera 1 ms antes de repetir el ciclo
}

/*
4) Lograr una variación senoidal en la intensidad de brillo del LED verde. Usar mismos tiempos 
que en ejercicio 3.
*/
void Ejercicio4() {
  // Calculamos el tiempo transcurrido desde el inicio del ciclo, para que el mismo dure 2 segundos (2000 ms) 
  unsigned long tiempoActual = millis();
  unsigned long tiempoTranscurrido = (tiempoActual - tiempoInicio) % 2000; // % 2000 asegura que el tiempo se reinicie cada 2 segundos

  // Convertimos el tiempo transcurrido a radianes para la función seno
  float radianes = (2 * PI * tiempoTranscurrido) / 2000.0;

  // Calculamos el brillo usando la función seno
  // La función sin devuelve valores entre -1 y 1, así que ajustamos para obtener valores entre 0 y 1
  float sinValue = (sin(radianes) + 1) / 2;

  // Convertimos el valor a un rango entre 0 y 255
  int PWM = (int)(sinValue * 255);

  // Ajustamos el brillo del LED verde
  analogWrite(LED_VERDE, PWM);

  delay(1); // Espera 1 ms antes de repetir el ciclo
}

/*
5) Si recibo una letra A por puerto serie prendo el buzzer. El buzzer solo se apaga cuando recibo 
una letra B
*/
void Ejercicio5() {
  // Verifica si hay datos disponibles en el puerto serie
  if (Serial.available() > 0) {
    // Lee el carácter recibido por el puerto serie
    char letra = Serial.read();
    // Imprime el carácter recibido en el monitor serie para depuración
    Serial.println(letra);

    // Si la letra recibida es 'A', enciende el buzzer
    if (letra == 'A') {
      digitalWrite(BUZZER, HIGH);  // Enciende el buzzer
    } 
    // Si la letra recibida es 'B', apaga el buzzer
    else if (letra == 'B') {
      digitalWrite(BUZZER, LOW);  // Apaga el buzzer
    }
  }
}

/*
6) Si activo un Switch (V0) desde Blynk, prendo el buzzer. El buzzer solo se apaga cuando 
desactivo el Switch
*/
BLYNK_WRITE(V0) {
  int pinValue = param.asInt(); // Obtiene el valor del switch desde Blynk
  Serial.print("V0 es: ");
  Serial.println(pinValue);
  
  if (pinValue == 0) {
    digitalWrite(BUZZER, LOW);  // Apaga el buzzer
  } else if (pinValue == 1) {
    digitalWrite(BUZZER, HIGH);  // Enciende el buzzer
  }
}

/*
7) Un widget tipo Gauge (V1) muestra la T° de tu sonda DS18B20. El gradiente de colores 
va de AZUL para la temperatura mínima (-55°C) hasta ROJO para la T° máxima (125°C).
*/
float leeSondaTemperatura()
{
  sensors.requestTemperatures(); // Solicita lectura de T° a todos los sensores conectados
  float temperatureCelsius = sensors.getTempCByIndex(0);   // Lee T° del primer sensor encontrado
  if (temperatureCelsius == -127.00){ // Verifica si la lectura fue exitosa
    Serial.println("Error al leer la temperatura.");
  } 
  return temperatureCelsius;
}

void Ejercicio7(){
  float temperatura = leeSondaTemperatura();
  Blynk.virtualWrite(V1, temperatura); // Envia datos a la variable V(N°)
  delay(1000);
}

/*
8) El LED verde oscila con PWM. Twpm es fijo de 255us. Ton es proporcional al valor de un 
widget tipo Slider (V2) de Blynk. Es decir, la intensidad del led varía de cero a máximo en 
función del Slide
*/
BLYNK_WRITE(V2) {
  int value = param.asInt(); // Obtiene el valor del Slider desde Blynk
  analogWrite(LED_VERDE, value); // Ajusta el brillo del LED verde
}

/*
9) Al pulsar y soltar el pulsador SW1, cambia de estado un LED virtual en Blynk, con un 
widget tipo LED (V3)
*/
void Ejercicio9() {
  static bool estadoPulsadorAnterior = HIGH; // Estado previo del pulsador (se inicializa como HIGH)
  static bool estadoLED = false;             // Estado del LED virtual en Blynk

  bool estadoPulsadorActual = digitalRead(SW1); // Lee el estado actual del pulsador

  // Detecta un cambio de estado del pulsador de HIGH a LOW (pulsado)
  if (estadoPulsadorAnterior == HIGH && estadoPulsadorActual == LOW) {
    estadoLED = !estadoLED; // Cambia el estado del LED virtual
    Blynk.virtualWrite(V3, estadoLED ? 255 : 0); // Enciende o apaga el LED virtual en Blynk
  }

  estadoPulsadorAnterior = estadoPulsadorActual; // Actualiza el estado previo del pulsador

  delay(50); // Espera 50 ms para evitar rebotes del pulsador
}


void loop() {
  Ejercicio9();
}

