/*
 * Este es el código de muestra para Gravity: Analog pH Sensor / Meter Kit V2, SKU: SEN0161-V2
 * Para garantizar la precisión, se necesita un sensor de temperatura como DS18B20, para ejecutar la compensación automática de temperatura.
 * Puede enviar comandos en el monitor en serie para ejecutar la calibración.
 * Comandos seriales:
 *   enterph -> entrar en el modo de calibración
 *   calph   -> calibre con la solución tampón estándar, se reconocerán automáticamente dos soluciones tampón (4.0 y 7.0)
 *   exitph  -> guardar los parámetros calibrados y salir del modo de calibración
 */

#include "DFRobot_PH.h"
#include <EEPROM.h>

#define PH_PIN I0.11
float voltage,phValue,temperature = 25;
DFRobot_PH ph;

void setup()
{
    Serial.begin(115200);  
    ph.begin();
}

void loop()
{
    static unsigned long timepoint = millis();
    if(millis()-timepoint>1000U){                  //Intervalo de tiempo: 1s
        timepoint = millis();
        //temperature = readTemperature();         // lea su sensor de temperatura para ejecutar la compensación de temperatura
        voltage = analogRead(PH_PIN)/1024.0*5000;  // leer el voltage
        phValue = ph.readPH(voltage,temperature);  // convertir el voltage a pH con compensación de temperatura
        Serial.print("temperature:");
        Serial.print(temperature,1);
        Serial.print("^C  pH:");
        Serial.println(phValue,2);
    }
    ph.calibration(voltage,temperature);           
}

float readTemperature()
{
  //add your code here to get the temperature from your temperature sensor
}
