#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

//Auth Token in the Blynk App.
char auth[] = "Your auth token";

// Your WiFi credentials.
// Set password to " " for open networks.
char ssid[] = "your wifi SSID";
char pass[] = "your password";

int buzzer = D2;
int smokeA0 = A0;

// threshold value. We might need to change it.
int sensorThres = 600;

void setup() {
 pinMode(buzzer, OUTPUT);
 pinMode(smokeA0, INPUT);
 Serial.begin(9600);
}

void loop() {
 int analogSensor = analogRead(smokeA0);

 Serial.print("Pin A0: ");
 Serial.println(analogSensor);
 // Checks if it has reached the threshold value
 if (analogSensor > sensorThres)
 {
   tone(buzzer, 1000, 200);
   Blynk.notify("Alert: Fire in the House");  
 }
 else
 {
   noTone(buzzer);
 }
 delay(100);
}
