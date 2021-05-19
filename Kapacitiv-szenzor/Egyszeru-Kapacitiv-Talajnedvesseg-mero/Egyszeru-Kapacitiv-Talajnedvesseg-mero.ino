/*********************************************************************
Ez a program megadott időközönként mér egy kapacitív 
talajnedvesség mérővel és feltölti az adatokat Blynk-re.

A projekt részletes bemutatóját itt találod:
      Még készül

Licensz: MIT License
**********************************************************************

Amire szükség lesz:
  - NodeMCU, Wemos D1 Mini vagy bármely ESP8266 alapú mikroszámítógép
  - Kapacitív talajnedvesség érzékelő
  - Jumper kábelek
  - Micro USB kábel és egy telefontöltő
  - WiFi kapcsolat, internet

Kapcsolás:
    3V    <----->   VCC
    GND   <----->   GND
    A0    <----->   AOUT

        https://github.com/esp8266/Arduino
  - Blynk könyvtár:
Szükséges könyvtárak:
  - ESP8266 könyvtárai:
        https://github.com/blynkkk/blynk-library/releases/latest


Blynk alkalmazás beállításai:
  - Value Display vagy SuperChart Widget a V1-hez csatolva
  - Value Display vagy SuperChart Widget a V2-höz csatolva


Ha érdekelnek hasonló projektek, látogass el oldalamra.
    - Weboldal: https://minerktech.blog.hu/
    - Youtube: https://www.youtube.com/c/MinerkTech
    - Facebook: https://www.facebook.com/minerktech
    - GitHub: https://github.com/MinerkTech

*********************************************************************/


/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


/* BEÁLLÍTÁSOK */
/* <<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>> */

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// A Wifi hálózatod adatai
// Állítsd a jelszót ""-ra, ha nincs jelszava
char ssid[] = "HálózatNeve";
char pass[] = "HálózatJelszava";

const int airValue = 630;     // Cseréld ki ezt az értéket a száraz szenzorral mért nyers értékre
const int waterValue = 275;   // Cseréld ki ezt az értéket a vízben lévő szenzorral mért nyers értékre

const long messureInterval = 1000L;   // Mérési időköz milliszekundumban
                                      // 1000L    = 1 másodperc
                                      // 10000L   = 10 másodperc
                                      // 60000L   = 1 perc
                                      // 600000L  = 10 perc
                                      // 3600000L = 1 óra
                                     

#define percentPin 1        // A virtuális pin száma (V1), ahol a nedvesség százalékban van elküldve
#define sensorvaluePin 2    // A virtuális pin száma (V2), ahol a nyers mért érték van megadva

/* <<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>> */


#define sensorPin A0

int soilMoistureValue = 0;
int soilMoisturePercent = 0;

BlynkTimer timer;



// Ez a fügvény méri a talajnedvességet és küldi el az adatokat a Blynk-nek
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor() {
  
  //Mérés és adat átalakítás
  int soilMoistureValue = analogRead(sensorPin);
    Serial.println("Soil moisture raw value: ");
    Serial.print(soilMoistureValue);

  int soilMoisturePercent = map(soilMoistureValue, airValue, waterValue, 0, 100);
    Serial.println("Soil moisture value in percent: ");
    Serial.print(soilMoisturePercent);

  // Adatok küldése Blynk-re
  Blynk.virtualWrite(percentPin, soilMoisturePercent);
  Blynk.virtualWrite(sensorvaluePin, soilMoistureValue);
}



void setup() {
  
  // Hibakereső konzol indítása
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Mérés és adatok elküldése 'messureInterval' időközönként
  timer.setInterval(messureInterval, sendSensor);
}



void loop() {
  Blynk.run();
  timer.run();
}