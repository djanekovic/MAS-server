% Projektna dokumentacija za projekt iz predmeta Multimedijske arhitekture i sustavi
% Darko Janeković; Ivan Cindrić; Danijel Belošević; Lovro Knežević; Domagoj Kudek
% 22.01.2020

Sadržaj
=======

Opis sustava
============

Sustav je zasnovan na razvojnoj pločici PYNQ-Z1 i kameri ov7670. Na razvojnoj
pločici je ostvaren dohvat slike s kamere, njena obrada i pohrana na SD karticu.
Slika se dohvaća u YUYV formatu gdje je jedan piksel u prosjeku veličine 16
bitova budući da je kromatskih komponenata duplo manje.

Da bi dohvat slike s kamere bio moguć, za početak je potrebno generirati
sklopovlje i na odgovarajuć način ga povezati s procesorskim sustavom. Tu se
govori o blok shemi sustava koja se ostvaruje u programskom alatu Vivado.

Jednom kad je sklopovlje generirano potrebno je postaviti odgovarajuće
vrijednosti u programske registre kamere. Kamera s procesorskim sustavom
komunicira protokolom SSCB koji je sličan protokolu I2C.

Jednom kad je kamera ispravno konfigurirana, s nje je moguće pročitati podatke i
onda ih kasnije obrađivati. Svaki od koraka koji su nabrojani gori, detaljnije
će biti opisani u nastavku.

Sustav na početku svog rada inicijalizira sklopovlje koje koristi. Ovdje se
misli na GPIO priključnice budući da im je potrebno postaviti smjer, na
podatkovne strukture za I2C protokol i na datotečni sustav koji se nalazi na SD
kartici.

Nakon inicijalizacije, sustav konfigurira kameru specificirajući parametre
digitalnog procesora koji se nalazi na kameri. Nakon što je kamera
uspješno konfigurirana sustav počinje s preuzimanjem podataka. Podaci se nakon
preuzimanja obrađuju i spremaju na SD karticu. Opisnik datoteke se zatvara i
sustav završava s radom.


Blok shema
==========

Blok shema sustava iz programskog alata Vivado prikazana je na slici.

![Blok shema sustava](images/block_design.png "Blok shema sustava")
\

Sustav se kao što je to na slici vidljivo sastoji od nekoliko blokova od kojih
su najvažniji blokovi Zynq7, AXI GPIO i AXI I2C.

AXI GPIO se koristi za dohvat podataka s kamere, a AXI I2C za konfiguraciju
kamere preko SSCB protokola.

Zynq7 predstavlja procesorski sustav na kojem se izvršava programski kod i u
nastavku će detaljnije biti opisana točna konfiguracija njegovih perifernih
jedinica.

Na slici je prikazana konfiguracija Zynq7 procesorskog sustava. Od perifernih
jedinica koristi se:

* Ethernet: prijenos podataka do korisnika koristeći Ethernet protokol.
* UART: serijska komunikacija za potrebe pronalaženja grešaka.
* SD: pohrana podataka na SD karticu kad Ethernet nije opcija.

Procesorski sustav radi s frekvencijom takta od 650 MHz dok je priključnicu XCLK
postavljena frekvencija takta 10 MHz budući da je najmanja frekvencija na kojoj
kamera radi 8 MHz.

Potpuna konfiguracija procesorskog sustava prikazana je u nastavku.

![Konfiguracija procesorskog sustava](images/zynq7_conf.png "Zynq7 konfiguracija")
\


Korišteni algoritmi
===================

Prije kompresije je potrebno izvesti proširenje podataka iz zapisa 4:2:2 u
zapis 4:4:4. Postupak je moguće na dva načina:

1. S jednom pomoćnim spremnikom proširujući postojeći spremnik.

2. Alocirajući novi spremnik i nakon što je proširenje obavljeno oslobađajući
memoriju za prošli.

U sustavu koji se opisuje ovim dokumentom implementirana je druga opcija. Prva
opcija je optimalna u prostoru, ali nije optimalna u vremenu i nije moguće
napraviti nekoliko velikih čitanja nego je potrebno raditi puno malih čitanja.
Budući da sustav nije toliko ograničen memorijom, implementirana je druga
opcija koja rezultira s puno manje čitanja i više pogodataka priručne memorije.

Prema broju pozivanja najčešće pozivan algoritam je diskretna kosinusna
transformacija koja radi transformaciju u frekvencijski prostor. JPEG kompresija
je implementirana koristeći programsku biblioteku otvorenog koda TinyJPEG i
modificirajući njene funkcije. Osim obične diskretne kosinusne transformacije
koja radi s kvadratnom složenošću, biblioteka implementira i brzu kosinusnu
transformaciju koja implementira Arai-Agui-Nakajima algoritam za diskretnu
kosinusnu transformaciju. Algoritam je jedan od najbržih i razlika između
naivnog i spomenutog je značajna.

Pored toga, za JPEG je potrebno implementirati i neku vrstu kodiranja. Ova
biblioteka implementira sekvencijalno Huffmanovo kodiranje pri čemu prilikom
pokretanja generira tablicu kodiranja.
