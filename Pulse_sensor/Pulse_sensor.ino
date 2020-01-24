#define USE_ARDUINO_INTERRUPTS false
#include <PulseSensorPlayground.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>   //including the library of SimpleTimer

DFRobot_Heartrateheartrate(DIGITAL_MODE); 

SimpleTimer timer;
char auth[] = " 4zgidlh3-hclaa6w8b4-Fwn8IilD6TJT";            // You should get Auth Token in the Blynk App.
                                           // Go to the Project Settings (nut icon).

char ssid[] = "3G";    // Your WiFi credentials.
char pass[] = "9946160099";  // Set password to "" for open networks.

void setup() {
Serial.begin(115200);
Blynk.begin(auth, ssid, pass);
timer.setInterval(2000, sendUptime);

}

void sendUptime()
{

uint8_trateValue;
heartrate.getValue(heartratePin); ///< A1 foot sampled values
rateValue = heartrate.getRate(); ///< Get heart rate value 
if(rateValue)  {
Serial.println(rateValue);
Blynk.virtualWrite(V0,rateValue);
  }
delay(20);

}
void loop() {

Blynk.run();
timer.run();

}
