#include <EEPROM.h>

#define CE_PIN I0_12   //Pin sensor de conductividad electrica
#define PH_PIN I0_11   //Pin sensor pH
#define OD_PIN I0_10   //Pin sensor Oxigeno Disuelto
#define ORP_PIN I0_9   //Pin sensor Potencial de oxido-reduccion
#define TDS_PIN I0_8   //Pin sensor total de solidos disueltos
#define TURB_PIN I0_7  //Pin sensor turbidez
#define TEMP_PIN I0_4  //Pin sensor temperatura

void setup() {
  Serial.begin(9600);
  pinMode(CE_PIN,INPUT);
  pinMode(PH_PIN,INPUT);
  pinMode(OD_PIN,INPUT);
  pinMode(ORP_PIN,INPUT);
  pinMode(TDS_PIN,INPUT);
  pinMode(TURB_PIN,INPUT);
  pinMode(TEMP_PIN,INPUT);
}

void loop() {
  float CE = analogRead(CE_PIN);
  float PH = analogRead(PH_PIN);
  float OD = analogRead(OD_PIN);
  float ORP = analogRead(ORP_PIN);
  float TDS = analogRead(TDS_PIN);
  float TURB = analogRead(TURB_PIN);
  float TEMP = analogRead(TEMP_PIN);
  Serial.println("//////////////////////////");
  Serial.print("Conductividad electrica: ");
  Serial.println(CE);
  Serial.print("pH: ");
  Serial.println(PH);
  Serial.print("Oxigeno disuelto: ");
  Serial.println(OD);
  Serial.print("Potencial de oxido-reducción: ");
  Serial.println(ORP);
  Serial.print("Total de solidos disueltos: ");
  Serial.println(TDS);
  Serial.print("Turbidez: ");
  Serial.println(TURB);
  Serial.print("Temperatura: ");
  Serial.println(TEMP);
  Serial.println("//////////////////////////");
  delay(1000);
}
