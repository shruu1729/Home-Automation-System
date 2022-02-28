
//Temperature sensor

#define BLYNK_PRINT Serial    
#include "ESP8266WiFi.h"
#include "BlynkSimpleEsp8266.h"
#include "DHT.h"

char auth[] = "       "; //Enter the Auth code which was send by Blink


char ssid[] = "     ";  //Enter your WIFI Name
char pass[] = "     ";  //Enter your WIFI Password

#define DHTPIN 2          // Digital pin 4

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     

DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();  //dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V5, h);  //V5 is for Humidity
  Blynk.virtualWrite(V6, t);  //V6 is for Temperature
}

void setup()
{
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth, ssid, pass);

  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer
}
