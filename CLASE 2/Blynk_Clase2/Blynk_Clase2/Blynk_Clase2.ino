/* Clase 2
   Mi Primer Desarrollo IoT
   Segunda Edición
   TR3BOL Argentina
*/

//Credenciales del Dispositivo creado en Clase 2
//Reemplaza tus credenciales de tu proyecto propio
#define BLYNK_TEMPLATE_ID "TMPL2QogB2E41"
#define BLYNK_TEMPLATE_NAME "TEMPLATEESP"
#define BLYNK_AUTH_TOKEN "1a-IIquCSQwgkHzl_GfcKFYwD5RtQi60"

#define LED_TR3BOL D8

#include "miSondaTemperatura.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "EL_PROFESOR"; //Completa con tu red WiFi
char pass[] = "14654647"; //Completa con la contraseña de tu red WiFi

BLYNK_WRITE(V0){
  int pinValue = param.asInt();
  Serial.print("V0 es: ");
  Serial.println(pinValue);
  if(pinValue==0)       digitalWrite(LED_TR3BOL,LOW);
  else if(pinValue==1)  digitalWrite(LED_TR3BOL,HIGH);
}
void setup(){
  Serial.begin(115200);
  pinMode(LED_TR3BOL,OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  configuraSondaTemperatura();
}
void loop(){
  float temperatura = leeSondaTemperatura();
  Blynk.virtualWrite(V1, temperatura); //<-- Manda tus datos a la variable V(N°)
  delay(1000);
  Blynk.run();
}
