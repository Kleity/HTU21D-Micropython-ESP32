#include <Wire.h>
#include "Adafruit_HTU21DF.h"

// Connect Vin to 3-5VDC
// Connect GND to ground
// Connect SCL to I2C clock pin (A5 on UNO)
// Connect SDA to I2C data pin (A4 on UNO)

Adafruit_HTU21DF htu = Adafruit_HTU21DF();

void setup() {
  Serial.begin(9600);
  Serial.println("HTU21D-F test");

  if (!htu.begin()) {
    Serial.println("Couldn't find sensor!");
    while (1);
  }
}

void loop() {
    Serial.print(getHTU('C'));
    printDegree();
    Serial.println("C");
    
    Serial.print(getHTU('F'));
    printDegree();
    Serial.println("F");

    Serial.print(getHTU('K'));
    Serial.println("K");    
    Serial.println(" ");  

    Serial.print("Humidity:");
    Serial.print(getHTU('H'));
    Serial.println("%");

    if(getHTU('C') <81)
    {
      //digitalWrite(5, LOW);
          
    }
    delay(5000);
}


/*
 * @brief returns temperature or relative humidity
 * @param "type" is character
 *     C = Celsius
 *     K = Keliven
 *     F = Fahrenheit
 *     H = Humidity
 * @return returns one of the values above
 * Usage: to get Fahrenheit type: getHTU('F')
 * to print it on serial monitor Serial.println(getHTU('F'));
 */
float getHTU(char type)
{
  float value;
    float temp = htu.readTemperature();
    float rel_hum = htu.readHumidity();
   if(type =='F')
   {
    value = temp *9/5 + 32;//convert to Fahrenheit 
   }else if(type =='K')
   {
    value = temp + 273.15;//convert to Kelvin
   }else if(type =='H')
   {
    value = rel_hum;//return relative humidity
   }else{
    value = temp;// return Celsius
   }
   return value;
}//


/*
 * @brief prints degree symbol on serial monitor
 * @param none
 * @return returns nothing
 */
 void printDegree()
{
    Serial.print("\xC2"); 
    Serial.print("\xB0");  
}
