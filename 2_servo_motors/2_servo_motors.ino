#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;
Servo servo1;

char auth[] = "LzPCvxwBNJlvr3L2u8P0Z15RcunqD9hr";
char ssid[] = "3G";
char pass[] = "9946160099";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  servo.attach(15);// NodeMCU D8 pin
  servo1.attach(13);// NodeMCU D7 pin
  
 }
  
void loop()
{
  
  Blynk.run();
  
}
BLYNK_WRITE(V1)
{
   servo.write(param.asInt());
}

BLYNK_WRITE(V2)
{
  servo.write(0);
}
BLYNK_WRITE(V3)
{
  servo.write(90);
}
BLYNK_WRITE(V4)
{
   servo1.write(param.asInt());
   //servo2.write(param.asInt());
}

BLYNK_WRITE(V5)
{
  servo1.write(0);
  //servo2.write(0);
  //delay(15);
}
BLYNK_WRITE(V6)
{
  servo1.write(90);
  //servo2.write(90);
  //delay(15);
}
