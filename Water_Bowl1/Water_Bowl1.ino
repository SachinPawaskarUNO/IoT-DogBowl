/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  This example shows how value can be pushed from Arduino to
  the Blynk App.

  NOTE:
  BlynkTimer provides SimpleTimer functionality:
    http://playground.arduino.cc/Code/SimpleTimer

  App project setup:
    Value Display widget attached to Virtual Pin V5
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "*********";

// Your WiFi credentials.
// Set password to "" for open networks.

// WiFi network name ""
char ssid[] = "*********";
// WiFi password ""
char pass[] = "*********";

int sensor = 0;
int lastState = 0;



void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  
  // Setup a function to be called every second
 // timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  
  sensor=analogRead(A0);

 // This sends your phone a notifcation when the water bowl is empty
 if (sensor < 200 && lastState == 0) {
   Blynk.notify("Your pet's water bowl is empty!");
   lastState = 1;
   delay(1000);
   
   }
   else if (sensor < 200 && lastState == 1) {
   delay(1000);
   }
   else {
    //st
    lastState = 0;
    delay(1000);
  }
  
  delay(100);
}
