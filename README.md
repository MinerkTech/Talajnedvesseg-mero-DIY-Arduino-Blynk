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

Röviden az arduino és a szenzor lábait így kell bekötnöd:

3V    <----->   VCC

GND   <----->   GND

A0    <----->   AOUT

##Szenzor kalibrálása
Bármilyen szenzort is válassz meg kell adnod, mennyi a szenzor értéke, ha teljesen száraz a föld és mennyi, ha nagyon vizes. Ez szenzoronként és talajonként változó, ezért a legjobb eredmények érdekében a saját eszközöddel az általad használt tajaban érdemes elvégezned a kalibrációt. Erre két módszer létezik:

Pontatlan, de gyors
Feltöltöd a szükséges programot.
Soros porton vagy az alkalmazásban figyeled pár percig mennyi a szenzor értéke szárazon, a talajon kívül. Felírod ezt az értéket.
Vízbe rakod a szenzort, úgy hogy az előírt szintig ellepje azt.
Soros porton vagy az alkalmazásban figyeled pár percig mennyi a szenzor értéke vízben, majd felírod ezt az értéket is.
A program megfelelő változóiba beírod az általad mért értékeket és újra feltöltöd azt.

Pontos, de időigényesebb
Feltöltöd a szükséges programot.
Teljesen száraz talajba rakod a szenzort, úgy hogy az előírt szintig föld alatt legyen.
Soros porton vagy az alkalmazásban figyeled pár percig mennyi a szenzor értéke, majd felírod ezt az értéket.
Meglocsolod a talajt, amennyire csak lehetséges.
Soros porton vagy az alkalmazásban figyeled pár percig mennyi a szenzor értéke, majd felírod ezt az értéket is.
A program megfelelő változóiba beírod az általad mért értékeket és újra feltöltöd azt.


Ez a projekt a The MIT License (MIT) alatt jelent meg.
