
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "Your BlynkAuth Code";

char ssid[] = "SSID";
char pass[] = "Password";

#define DHTPIN 0          // D3
#define DHTTYPE DHT11     
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor()
{
float h = dht.readHumidity();
float t = dht.readTemperature(); 

if (isnan(h) || isnan(t)) {
Serial.println("Failed to read from DHT sensor!");
return;
  }

Blynk.virtualWrite(V5, t);
Blynk.virtualWrite(V6, h);
}

void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
dht.begin();
timer.setInterval(1000L, sendSensor);
}

void loop()
{
Blynk.run();
timer.run();
}
