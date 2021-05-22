/*********************************************************************

Ez a program megadott időközönként mér egy  
talajnedvesség mérővel és feltölti az adatokat Blynk-re.

A projekt részletes bemutatóját itt találod:
      Még készül
      
**********************************************************************

Amire szükség lesz:
  - NodeMCU, Wemos D1 Mini vagy bármely ESP8266 alapú mikroszámítógép
  - FC-28 vagy bármilyen hasonló egyszerű talajnedvesség érzékelő
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

const int dryValue = 1024;     // Cseréld ki ezt a teljesen száraz talajban mért nyers értékre
const int waterValue = 220;   // Cseréld ki ezt a nagyon vízes talajban mért nyers értékre

const long messureInterval = 1000L;   // Mérési időköz milliszekundumban
                                      // 1000L    = 1 másodperc
                                      // 10000L   = 10 másodperc
                                      // 60000L   = 1 perc
                                      // 600000L  = 10 perc
                                      // 3600000L = 1 óra
                                     
#define sensorPower D1     // A digitális pin, amiről a szenzor kapja az áramot

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
  
  // Talajnedvesség mérő bekapcsolása
  digitalWrite(sensorPower, HIGH);
  delay(10); // Várakozás, hogy bekapcsoljon a szenzor
  
  //Mérés és adat átalakítás
  soilMoistureValue = analogRead(sensorPin);
    Serial.println("");
    Serial.print("Nyers adat: ");
    Serial.println(soilMoistureValue);

  soilMoisturePercent = map(soilMoistureValue, dryValue, waterValue, 0, 100);
    Serial.print("Talajnedvesség: ");
    Serial.print(soilMoisturePercent);
    Serial.println("%");

  digitalWrite(sensorPower, LOW); // Szenzor kikapcsolása

  // Adatok küldése Blynk-re
  Blynk.virtualWrite(percentPin, soilMoisturePercent);
  Blynk.virtualWrite(sensorvaluePin, soilMoistureValue);
}



void setup() {
  
  // Hibakereső konzol indítása
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // Beállíthatsz más szervert is:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  pinMode(sensorPower, OUTPUT);     // A digitális pin kimenetre történő állítása
  digitalWrite(sensorPower, LOW);

  // Mérés és adatok elküldése 'messureInterval' időközönként
  timer.setInterval(messureInterval, sendSensor);
}



void loop() {
  Blynk.run();
  timer.run();
}