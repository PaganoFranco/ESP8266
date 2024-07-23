/*
    Este sketch demuestra cómo escanear redes WiFi.
    La API es casi la misma que con la biblioteca WiFi Shield,
    la diferencia más obvia es el archivo diferente que necesitas incluir:
*/

#include <ESP8266WiFi.h>  // Incluye la biblioteca necesaria para usar WiFi con el ESP8266.

void setup() {
  Serial.begin(115200);  // Inicializa la comunicación serie a 115200 baudios.
  Serial.println(F("\nESP8266 WiFi scan example"));  // Imprime un mensaje inicial en la consola serie.

  // Configura el WiFi en modo estación (cliente).
  WiFi.mode(WIFI_STA);

  // Desconéctate de cualquier punto de acceso al que estuviera conectado previamente.
  WiFi.disconnect();
  delay(100);  // Espera 100 milisegundos para asegurarse de que la desconexión se complete.
}

void loop() {
  String ssid;  // Variable para almacenar el SSID de la red.
  int32_t rssi;  // Variable para almacenar la intensidad de la señal (RSSI).
  uint8_t encryptionType;  // Variable para almacenar el tipo de encriptación de la red.
  uint8_t *bssid;  // Puntero para almacenar la dirección MAC del punto de acceso.
  int32_t channel;  // Variable para almacenar el canal de la red.
  bool hidden;  // Variable para indicar si la red está oculta.
  int scanResult;  // Variable para almacenar el resultado del escaneo.

  Serial.println(F("Starting WiFi scan..."));  // Imprime un mensaje indicando que se va a iniciar el escaneo.

  // Escanea las redes WiFi disponibles. El primer parámetro indica que el escaneo es síncrono, 
  // el segundo parámetro indica que también se buscarán redes ocultas.
  scanResult = WiFi.scanNetworks(/*async=*/false, /*hidden=*/true);

  if (scanResult == 0) {
    Serial.println(F("No networks found"));  // Si no se encuentran redes, imprime un mensaje indicando esto.
  } else if (scanResult > 0) {
    Serial.printf(PSTR("%d networks found:\n"), scanResult);  // Imprime la cantidad de redes encontradas.

    // Imprime los resultados del escaneo sin ordenar.
    for (int8_t i = 0; i < scanResult; i++) {
      WiFi.getNetworkInfo(i, ssid, encryptionType, rssi, bssid, channel, hidden);  // Obtiene la información de la red.

      // Obtiene información adicional sobre la red.
      const bss_info *bssInfo = WiFi.getScanInfoByIndex(i);
      String phyMode;
      const char *wps = "";
      if (bssInfo) {
        phyMode.reserve(12);
        phyMode = F("802.11");
        String slash;
        if (bssInfo->phy_11b) {
          phyMode += 'b';
          slash = '/';
        }
        if (bssInfo->phy_11g) {
          phyMode += slash + 'g';
          slash = '/';
        }
        if (bssInfo->phy_11n) {
          phyMode += slash + 'n';
        }
        if (bssInfo->wps) {
          wps = PSTR("WPS");
        }
      }
      Serial.printf(PSTR("  %02d: [CH %02d] [%02X:%02X:%02X:%02X:%02X:%02X] %ddBm %c %c %-11s %3S %s\n"), 
                    i, channel, bssid[0], bssid[1], bssid[2], bssid[3], bssid[4], bssid[5], 
                    rssi, (encryptionType == ENC_TYPE_NONE) ? ' ' : '*', hidden ? 'H' : 'V', 
                    phyMode.c_str(), wps, ssid.c_str());
      yield();  // Permite que el sistema operativo realice tareas de mantenimiento.
    }
  } else {
    Serial.printf(PSTR("WiFi scan error %d"), scanResult);  // Si hay un error en el escaneo, imprime un mensaje con el código de error.
  }

  // Espera un poco antes de escanear de nuevo.
  delay(5000);
}

