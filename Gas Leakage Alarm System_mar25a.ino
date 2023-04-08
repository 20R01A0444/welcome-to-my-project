#define BLYNK_TEMPLATE_ID "TMPLOuhO36DM"
#define BLYNK_TEMPLATE_NAME "gas leakage"
#define BLYNK_AUTH_TOKEN "n-QQCPjArObyWBPyp09bznXctZA4k5sV"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = "n-QQCPjArObyWBPyp09bznXctZA4k5sV";
char ssid[] = "iasmar";  
char pass[] = "9876543210";  
int smokeA0 = A0;
int data = 0;
int sensorThres = 100;


BlynkTimer timer;

void sendSensor(){
 
 int data = analogRead(smokeA0);
 Blynk.virtualWrite(V0, data);
 Serial.print("Pin A0: ");
 Serial.println(data);

  if (data > 20)     // Change the Threshold value
  {
    Blynk.logEvent("gas_leakage","GAS LEAKAGE DETECTED");
  }
}

void setup(){
   pinMode(smokeA0, INPUT);
   Serial.begin(115200);
   Blynk.begin(auth, ssid, pass);
   timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}


