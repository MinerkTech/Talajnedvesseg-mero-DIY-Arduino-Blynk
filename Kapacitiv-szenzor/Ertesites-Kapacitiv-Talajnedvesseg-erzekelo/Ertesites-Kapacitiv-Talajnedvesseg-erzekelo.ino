/*********************************************************************

Ez a program megadott időközönként mér egy kapacitív 
talajnedvesség mérővel, feltölti az adatokat Blynk-re és
értesítést küld, ha kiszáradt a talaj.

A projekt részletes bemutatóját itt találod:
      Még készül
      
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

Szükséges könyvtárak:     
  - Blynk könyvtár:
        https://github.com/blynkkk/blynk-library/releases/latest
  - ESP8266 könyvtárai:
        https://github.com/esp8266/Arduino


Blynk alkalmazás beállításai:
  - Value Display vagy SuperChart Widget a V1-hez csatolva
  - Value Display vagy SuperChart Widget a V2-höz csatolva

  Az alkalmazásban a Display Widget-ek beállításainál a READING RATE-t
  (olvasási gyakoriság) állítsd PUSH-ra. Ezzel az Arduino-n futó
  program szabja meg milyen gyakran küld be adatot.

Ha érdekelnek hasonló projektek, látogass el oldalamra.
    - Weboldal: https://minerktech.blog.hu/
    - Youtube: https://www.youtube.com/c/MinerkTech
    - Facebook: https://www.facebook.com/minerktech
    - GitHub: https://github.com/MinerkTech

Licensz: MIT License
*********************************************************************/


/* Tedd ezt megjegyzéssé, a prints letiltásához és hely felszabadításához*/
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


/* BEÁLLÍTÁSOK */
/* <<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>> */

// Állítsd be az Auth Token-t (azonosító kulcs)
// A Blynk APP-ban a beállítások (anyacsavar ikon) alatt tudod létrehozni
char auth[] = "AuthToken-ed";

// A Wifi hálózatod adatai
// Állítsd a jelszót ""-ra, ha nincs jelszava
char ssid[] = "HálózatNeve";
char pass[] = "HálózatJelszava";

const int dryValue = 650;       // Cseréld ki ezt a teljesen száraz talajban mért nyers értékre
const int waterValue = 275;     // Cseréld ki ezt a nagyon vízes talajban mért nyers értékre

const int wateringLevel = 500;  //Cseréld ki ezt arra a nyers értékre, amikor locsolni kellene

const string notification = "Locsold meg a növényed!";

const long messureInterval = 1000L;   // Mérési időköz milliszekundumban
                                      // 1000L    = 1 másodperc
                                      // 10000L   = 10 másodperc
                                      // 60000L   = 1 perc
                                      // 600000L  = 10 perc
                                      // 3600000L = 1 óra
                                      // Másodpercenként max 10 adat küldhető be

const long notifyInterval = 60000L;   // Értesítések közötti időköz milliszekundumban
                                      // 60000L   = 1 perc
                                      // 600000L  = 10 perc
                                      // 3600000L = 1 óra
                                      // 7200000L = 2 óra
                                      // Minimum 5 másodpercnek el kell telnie két értesítés között
                                                                          

#define percentPin 1        // A Blynk virtuális pin száma (V1), ahol a nedvesség százalékban van elküldve
#define sensorvaluePin 2    // A Blynk virtuális pin száma (V2), ahol a nyers mért érték van elküldve

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
  soilMoistureValue = analogRead(sensorPin);
    Serial.println("");
    Serial.print("Nyers adat: ");
    Serial.println(soilMoistureValue);

  soilMoisturePercent = map(soilMoistureValue, dryValue, waterValue, 0, 100);
    Serial.print("Talajnedvesség százalékban: ");
    Serial.println(soilMoisturePercent);

  // Adatok küldése Blynk-re
  Blynk.virtualWrite(percentPin, soilMoisturePercent);
  Blynk.virtualWrite(sensorvaluePin, soilMoistureValue);
}



void notifyWatering() {
  // Actually send the message.
  // Note:
  // We allow 1 notification per 5 seconds for now.
  if (soilMoistureValue > wateringLevel)
  {
    Serial.println("");
    Serial.print("Értesítés: ");
    Serial.println(notification);

    Blynk.notify(notification);
    // You can also use {DEVICE_NAME} placeholder for device name,
    // that will be replaced by your device name on the server side.
  }
}



void setup() {
  
  // Hibakereső konzol indítása
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // Beállíthatsz más szervert is:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Mérés és adatok elküldése 'messureInterval' időközönként
  timer.setInterval(messureInterval, sendSensor);

  // Adatok elemzése 'notifyInterval' indőközönként és értesítés küldése
  timer.setInterval(notifyInterval, notifyWatering);
}



void loop() {
  Blynk.run();
  timer.run();
}