
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "be87fc5249a94f38a39941b3e01c4cd6";


char ssid[] = "ZONG MBB-E8231-6E63";
char pass[] = "electroniclinic";

SimpleTimer timer;

// sensors 
int vs = D0; 
int sdata = 0; 

String vdata = ""; 

void myTimerEvent()
{
  Blynk.virtualWrite(V1, millis() / 1000);

}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(vs ,INPUT); 
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(10L,sensorvalue); 
}

void loop()
{
  Blynk.run();
  timer.run(); 

}

void sensorvalue()
{
  long measurement =vibration();
 //delay(50);
  Serial.println(measurement);
  Blynk.virtualWrite(V3, measurement);
  if( measurement > 1000 )
  {
    Blynk.notify("Vibration detected!!");
  }
vdata = vdata + "Vibration: " + measurement;  

  Blynk.virtualWrite(V2, vdata);
vdata = ""; 
}

long vibration(){
  long measurement=pulseIn (vs, HIGH);  
  return measurement;
}
