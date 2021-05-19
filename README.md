# Talajnedvesség mérő - DIY Arduino Blynk
Ebben a projektem összerakunk egy olcsó IoT talajnedvesség mérő kütyüt, ami méri egy növény földjének a nedvességtartalmát és értesítést küld, ha meg kéne locsolni.

## Mi az az IoT?


## Mi az a Blynk?
A Blynk egy IoT platform, amellyel egyszerűen készíthetsz Arduino eszközökhöz telefonos APP-ot. Fel lehet rá tölteni adatokat, amiket aztán egy mobil alkalmazásban meg lehet nézni, de akár eszköz vezérlésre vagy automatizálásra is alkalmas.
A Blynk-et használom az IoT projekteimhez, mert egyszerűbb alkalmazásokhoz teljesen ingyenes és a könyvtára nagyon megkönnyíti az Arduino-k programozását.

## Mire lesz szükségem?


### Milyen talaj nedvesség mérőt válasszak?

## Kapcsolás
Az áramkör ábráját, amit össze kell raknod, megtalálod a szenzorok mappáiban.
<p align="center">
  <img src="https://github.com/MinerkTech/Talajnedvesseg-mero-DIY-Arduino-Blynk/blob/main/Kapacitiv-szenzor/NodeMCU-Kapacitiv-szenzor-Kapcsolas.png" height="800" title="Példa kapcsolás">
</p>
**<p>Röviden az Arduino és a szenzor lábait így kell bekötnöd:</p>**

<p align="center">
3V <-----> VCC
<br>GND <-----> GND
<br>A0 <-----> AOUT</p>

## Szenzor kalibrálása
Bármilyen szenzort is válassz meg kell adnod, mennyi a szenzor értéke, ha teljesen száraz a föld és mennyi, ha nagyon vizes. Ez szenzoronként és talajonként változó, ezért a legjobb eredmények érdekében a saját eszközöddel az általad használt tajaban érdemes elvégezned a kalibrációt. Erre két módszer létezik:

### Pontatlan, de gyors
1. Feltöltöd a szükséges programot.
2. Soros porton vagy az alkalmazásban figyeled pár percig mennyi a szenzor értéke szárazon, a talajon kívül. Felírod ezt az értéket.
3. Vízbe rakod a szenzort, úgy hogy az előírt szintig ellepje azt.
4. Soros porton vagy az alkalmazásban figyeled pár percig mennyi a szenzor értéke vízben, majd felírod ezt az értéket is.
5. A program megfelelő változóiba (`airValue` - száraz érték, `waterValue` - vizes érték) beírod az általad mért értékeket és újra feltöltöd azt.

### Pontos, de időigényesebb
1. Feltöltöd a szükséges programot.
2. Teljesen száraz talajba rakod a szenzort, úgy hogy az előírt szintig föld alatt legyen.
3. Soros porton vagy az alkalmazásban figyeled pár percig mennyi a szenzor értéke, majd felírod ezt az értéket.
4. Meglocsolod a talajt, amennyire csak lehetséges.
5. Soros porton vagy az alkalmazásban figyeled pár percig mennyi a szenzor értéke, majd felírod ezt az értéket is.
6. A program megfelelő változóiba (`airValue` - száraz érték, `waterValue` - vizes érték) beírod az általad mért értékeket és újra feltöltöd azt.


Ez a projekt a The MIT License (MIT) alatt jelent meg. Bővebb információkat a `LICENSE` fájlban találsz.
