#include <OneWire.h>                
#include <DallasTemperature.h>
 
OneWire ourWire(2);                //Se establece el pin 2  como bus OneWire
 
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor

DeviceAddress address1 = {0x28, 0xFF, 0xCA, 0x4A, 0x5, 0x16, 0x3, 0xBD};//dirección del sensor 1
DeviceAddress address2 = {0x28, 0xFF, 0x89, 0x3A, 0x1, 0x16, 0x4, 0xAF};//dirección del sensor 2
DeviceAddress address3 = {0x28, 0xFF, 0x23, 0x19, 0x1, 0x16, 0x4, 0xD9};//dirección del sensor 3

void setup() {
delay(1000);
Serial.begin(9600);
sensors.begin();   //Se inicia el sensor
}
 
void loop() {
  
sensors.requestTemperatures();   //envía el comando para obtener las temperaturas
float temp1= sensors.getTempC(address1);//Se obtiene la temperatura en °C del sensor 1
float temp2= sensors.getTempC(address2);//Se obtiene la temperatura en °C del sensor 2
float temp3= sensors.getTempC(address3);//Se obtiene la temperatura en °C del sensor 3

Serial.print("Temperatura 1 = ");
Serial.print(temp1);
Serial.print(" C");
Serial.print("   Temperatura 2 = ");
Serial.print(temp2);
Serial.print(" C");
Serial.print("   Temperatura 3 = ");
Serial.print(temp3);
Serial.println(" C");
delay(100);    
delay(100);                     
}
