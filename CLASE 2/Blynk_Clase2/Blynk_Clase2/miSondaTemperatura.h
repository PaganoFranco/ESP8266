#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS D6 // Pin donde está conectado el sensor DS18B20
OneWire oneWire(ONE_WIRE_BUS); // Inicializa instancia de clase OneWire para comunicarse con el sensor
DallasTemperature sensors(&oneWire); // Ídem con DallasTemperature para interactuar con el sensor

void configuraSondaTemperatura()
{
  Serial.println("Iniciando DS18B20...");
  sensors.begin(); // Inicializa la comunicación con los sensores DS18B20
}

float leeSondaTemperatura()
{
  sensors.requestTemperatures(); // Solicita lectura de T° a todos los sensores conectados
  float temperatureCelsius = sensors.getTempCByIndex(0);   // Lee T° del primer sensor encontrado
  if (temperatureCelsius == -127.00){ // Verifica si la lectura fue exitosa
    Serial.println("Error al leer la temperatura.");
  } 
  return temperatureCelsius;
}