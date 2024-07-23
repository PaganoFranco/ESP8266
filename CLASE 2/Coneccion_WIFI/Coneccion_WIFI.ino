#include <ESP8266WiFi.h>

const char* ssid = "CTNET-PAGANO";       // Red WiFi
const char* password = "39834579"; // Contraseña Red WiFi

void setup() {
  delay(400);
  Serial.begin(115200);
  Serial.println("\n");
  
  WiFi.begin(ssid, password);
  delay(10);
  Serial.print("Intentando conectar a red ");
  Serial.println(ssid);
  
  while (WiFi.status() != WL_CONNECTED) { // Mientras no esté conectado
    Serial.print(".");
    delay(500);
  }
  
  Serial.println("");
  Serial.println("WiFi CONECTADO!!! :)");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  delay(2000);
  Serial.println("\nLISTO PARA SUBIR A LA NUBE!!");
}
