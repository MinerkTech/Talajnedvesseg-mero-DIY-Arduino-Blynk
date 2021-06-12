/*********************************************************************

Ez az univerzális program mér bármilyen talajnedvességmérővel, majd a
kapott nyers értékekeket megjeleníti soros monitoron.
Arra lett tervezve, hogy a projekben használt talajnedvességmérőket
teszteljük és kalibráljuk vele.

Ha a beállításokban megadott pinre (D1) kötöd a szenzor VCC lábát ki
fogkapcsolni a mérések között. Ez az olcsóbb szenzorok esetében
lehet hasznos, mivel így nő az élettartamuk.

A projekt részletes bemutatóját itt találod:
      Még készül
      
**********************************************************************

Amire szükség lesz:
  - NodeMCU, Wemos D1 Mini vagy bármely ESP8266 alapú mikroszámítógép
  - Bármilyen talajnedvességmérő
  - Jumper kábelek
  - Micro USB kábel és egy telefontöltő

Kapcsolás:
    Kapacitív szenzor:
        3V    <----->   VCC
        GND   <----->   GND
        A0    <----->   AOUT

    Olcsó szenzor:
        D1    <----->   VCC
        GND   <----->   GND
        A0    <----->   A0

Ha érdekelnek hasonló projektek, látogass el oldalamra.
    - Weboldal: https://minerktech.blog.hu/
    - Youtube: https://www.youtube.com/c/MinerkTech
    - Facebook: https://www.facebook.com/minerktech
    - GitHub: https://github.com/MinerkTech

Licensz: MIT License
*********************************************************************/

/* BEÁLLÍTÁSOK */
/* <<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>> */

#define sensorPower D1      // A digitális pin, amiről az olcsó szenzor kapja az áramot

/* <<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>><<¤>> */

#define sensorPin A0

void setup() {

  pinMode(sensorPower, OUTPUT);

  digitalWrite(sensorPower, LOW);     // Indításnál kikapcsol a szenzor

  Serial.begin(9600);
}

void loop() {

  // Talajnedvesség mérő bekapcsolása
  digitalWrite(sensorPower, HIGH);
  delay(10);      // Várakozás, hogy bekapcsoljon a szenzor
  
  int soilMoistureValue = analogRead(sensorPin);      // Mérés
  
  digitalWrite(sensorPower, LOW);     // Szenzor kikapcsolása

  // Adatok kiírása
  Serial.print("Nyers érték: ");
  Serial.println(soilMoistureValue);
  
  delay(1000);
}
