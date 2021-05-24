/*
 * Este es el código de muestra para Gravity: Kit de sensor / medidor de conductividad eléctrica analógica V2 (K = 1.0), SKU: DFR0300.
 * Para garantizar la precisión, se necesita un sensor de temperatura como DS18B20, para ejecutar la compensación automática de temperatura.
 * Puede enviar comandos en el monitor en serie para ejecutar la calibración.
 * Serial Commands:
 *   enterec -> Entrar en modo calibración
 *   calec -> calibre con la solución tampón estándar, se reconocerán automáticamente dos soluciones tampón (1413 us / cm y 12,88 ms / cm)
 *   exitec -> guardar los parámetros calibrados y salir del modo de calibración
 */

#include "DFRobot_EC.h"
#include <EEPROM.h>

#define EC_PIN I0_12;
float voltage,ecValue,temperature = 25;
DFRobot_EC ec;

void setup()
{
  Serial.begin(115200);  
  ec.begin();
}

void loop()
{
    static unsigned long timepoint = millis();
    if(millis()-timepoint>1000U)  //intervalo de tiempo: 1s
    {
      timepoint = millis();
      voltage = analogRead(EC_PIN)/1024.0*5000;   // lee el voltage
      //temperature = readTemperature();          // lee tu sensor de temperatura para ejecutar una compensación de temperatura
      ecValue =  ec.readEC(voltage,temperature);  // convertir voltaje a EC con compensación de temperatura
      Serial.print("temperatura:");
      Serial.print(temperature,1);
      Serial.print("^C  EC:");
      Serial.print(ecValue,2);
      Serial.println("ms/cm");
    }
    ec.calibration(voltage,temperature);
}

float readTemperature()
{
  //add your code here to get the temperature from your temperature sensor
}
