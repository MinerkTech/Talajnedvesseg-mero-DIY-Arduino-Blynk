# Talajnedvesség mérő - DIY Arduino Blynk
Ebben a projektem összerakunk egy olcsó IoT talajnedvesség mérő kütyüt, ami méri egy növény földjének a nedvességtartalmát és értesítést küld, ha meg kéne locsolni.

Ebben a videóban beszélek bővebben erről a projektről: Még készül

## Mi az az IoT?
Internet of Things magyarul dolgok internete, olyan „intelligens” eszközöket takar, melyek képesek kommunikálni egy hálózaton, szenzorok segítségével adatokat gyűjteni és akár vezérelni más rendszereket. Ilyenek vezérlik az okos otthonokat (okos kapcsoló, okos izzó, okos termosztát, stb.) és egy ilyen eszközt fogunk építeni ebben a projektben is.

## Mi az a Blynk?
A Blynk egy IoT platform, amellyel egyszerűen készíthetsz Arduino eszközökhöz telefonos APP-ot. Fel lehet rá tölteni adatokat, amiket aztán egy mobil alkalmazásban meg lehet nézni, de akár eszköz vezérlésre vagy automatizálásra is alkalmas.
A Blynk-et használom az IoT projekteimhez, mert egyszerűbb alkalmazásokhoz teljesen ingyenes és a könyvtára nagyon megkönnyíti az Arduino-k programozását.

## Mire lesz szükségem?
  - NodeMCU, Wemos D1 Mini vagy bármely ESP8266 alapú mikroszámítógép
  - Talajnedvesség érzékelő
  - Jumper kábelek
  - Micro USB kábel és egy telefontöltő
  - WiFi kapcsolat, internet

### Milyen talaj nedvesség mérőt válasszak?
Kétféle olcsó talajnedvesség mérő létezik, amit Arduino-hoz szoktak használni. Mindkettőhöz találsz programot a mappákban, de jól gondold meg melyiket választod.

A legegyszerűbb és egyben **legolcsóbb** már pár száz forintért kapható szenzort, sokszor név és márkajelzés nélkül forgalmazzák nagy tételben, mivel olyan olcsó és olyan **rövid az élettartama**. Onnan lehet felismerni, hogy két lábán kívülről van egy fém bevonat. Senkinek nem ajánlom ilyen szenzor vásárlását, mivel használattól függően pár hét vagy pár hónap alatt elrozsdál a fém bevonat és elromlik.
- Részletes leírás az olcsó szenzorról: https://lastminuteengineers.com/soil-moisture-sensor-arduino-tutorial/ 

Egy valamivel drágább, de tartósabb megoldás, egy **kapacitív talajnedvesség mérő** vásárlása. Ez úgy néz ki mint egy kis fekete karó. Fém részei nem érintkeznek közvetlenül a talajjal, így sokkal **hosszabb élettartama**. Én ilyen szenzorokat használok és ezek vásárlását ajánlom mindenkinek, mivel hoszútávon ezek olcsóbbak és üzembiztosabbak.
- Részletes leírás a kapacitív szenzorról: https://wiki.dfrobot.com/Capacitive_Soil_Moisture_Sensor_SKU_SEN0193


## Kapcsolás
Az áramkör ábráját, amit össze kell raknod, megtalálod a szenzorok mappáiban.
<p align="center">
  <img src="https://github.com/MinerkTech/Talajnedvesseg-mero-DIY-Arduino-Blynk/blob/Beta/Kapacitiv-szenzor/WemosD1-Kapacitiv-szenzor-kapcsolas.png" weight="640" title="Példa kapcsolás">
</p>

**<p>Az Arduino és a szenzor lábait így kell bekötnöd:</p>**

<p align="center">
3V <-----> VCC
<br>GND <-----> GND
<br>A0 <-----> AOUT</p>

## Szükséges könyvtárak:
- Blynk könyvtár: https://github.com/blynkkk/blynk-library/releases/latest
- ESP8266 könyvtárai: https://github.com/esp8266/Arduino

## Szenzor kalibrálása
Bármilyen szenzort is válassz meg kell adnod, mennyi a szenzor értéke, ha teljesen száraz a föld és mennyi, ha nagyon vizes. Ez szenzoronként és talajonként változó, ezért a legjobb eredmények érdekében a saját eszközöddel az általad használt tajaban érdemes elvégezned a kalibrációt. Erre két módszer létezik:

### Pontatlan, de gyors kalibráció
1. Feltöltöd a szükséges programot.
2. Soros porton vagy az alkalmazásban figyeled pár percig mennyi a szenzor értéke szárazon, a talajon kívül. Felírod ezt az értéket.
3. Vízbe rakod a szenzort, úgy hogy az előírt szintig ellepje azt.
4. Soros porton vagy az alkalmazásban figyeled pár percig mennyi a szenzor értéke vízben, majd felírod ezt az értéket is.
5. A program megfelelő változóiba (`dryValue` - száraz érték, `waterValue` - vizes érték) beírod az általad mért értékeket és újra feltöltöd azt.

### Pontos, de időigényesebb kalibráció
1. Feltöltöd a szükséges programot.
2. Teljesen száraz talajba rakod a szenzort, úgy hogy az előírt szintig föld alatt legyen.
3. Soros porton vagy az alkalmazásban figyeled pár percig mennyi a szenzor értéke, majd felírod ezt az értéket.
4. Meglocsolod a talajt, amennyire csak lehetséges.
5. Soros porton vagy az alkalmazásban figyeled pár percig mennyi a szenzor értéke, majd felírod ezt az értéket is.
6. A program megfelelő változóiba (`dryValue` - száraz érték, `waterValue` - vizes érték) beírod az általad mért értékeket és újra feltöltöd azt.

## Kapcsolat
Ha érdekelnek hasonló projektek, látogass el oldalamra.
- Weboldal: https://minerktech.blog.hu/
- Youtube: https://www.youtube.com/c/MinerkTech
- Facebook: https://www.facebook.com/minerktech
- GitHub: https://github.com/MinerkTech

## Licensz
Ez a projekt a The MIT License (MIT) alatt jelent meg. Bővebb információkat a `LICENSE` fájlban találsz.
