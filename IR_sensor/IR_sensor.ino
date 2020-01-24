#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "--your blynkajuth key here--";
char ssid[] = "--your wifissid here--";
char pass[] = "--your wifi password herep--";


#define IR D7
bool ir;
void setup() {
Serial.begin(9600);
pinMode(IR, INPUT);
Blynk.begin(auth, ssid, pass);
}
void loop() {
ir = digitalRead(IR);
if(ir == 1)
{
Serial.println("Object is present");
}
else if (ir == 0)
{
Serial.println("Empty");
}

Blynk.run();
}
