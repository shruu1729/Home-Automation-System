
#include <DHT_U.h>

#define Type DHT11
int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float tempC; 
float tempF;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
  delay(10);  //wait before accessing sensor
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);
  Serial.print("\n Humidity: ");    //prints the humdity in surrounding
  Serial.print(humidity);
  Serial.print("% ");
  
  Serial.print("\n Temperature in Celcius : ");   //prints the temp in degree celcius
  Serial.print(tempC);
  Serial.print("C ");
  
  Serial.print("\n Temperature in Farhenite : ");   //prints the temp in farhenite
  Serial.print(tempF);
  Serial.print("F \n\n\n");
  
  delay(3000);  //delay to next sensing
}
