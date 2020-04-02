/* Jalkapallo Jaakko on Villen lukemattomien tuntien kehitystyön tulos.
   Jaakkoa ohjataan reaaliaikaisesti - kuin kauko-ohjattavaa autoa - haluamallaan 'kauko-ohjaimella'.
   Itse olen käyttänyt tähän Processing 3 -työkalulla luotua ohjelmaa.

   Jaakko osaa liikkua kaikkiin suuntiin ennalta määrätyllä nopeudella sekä potkaista palloa hämmästyttävän tarkasti
   ja vieläpä pitkälle!

   Tämän lisäksi Jaakko on varsinainen parkettien partaveitsi jolta taipuu kaikki tanssit valssista twerkkaukseen.
   Ledit visualisoivat saatuja käskyjä ja lisäävät katu-uskottavuutta.

   (c) Ville Kyytinen 2020, kyytiville@outlook.com
*/

#include <Servo.h>

// LIITÄNNÄT            // moottorien pinnit
int moottoriA = 3;      // Kanavan A nopeus
int suuntaA_taa = 4;    // Kanavan A suunta 0
int suuntaA_eteen = 5;  // Kanavan A suunta 1
int moottoriB = 6;      // Kanavan B nopeus
int suuntaB_taa = 7;    // Kanavan B suunta 0
int suuntaB_eteen = 8;  // Kanavan B suunta 1

int puna = 13;          // Ledien pinnit
int kelt = 12;
int vihr = 11;

int trigPin = 2;  // Ultraäänisensorin pinnit // keltainen johto
int echoPin = 9;  // 3-johdon liitin

// GLOBAALIT MUUTTUJAT
char inbit;       // Serial inputin talletukseen robotin käskyttämistä varten
char roskis;       // Serial inputin tyhjentämisen apumuuttuja
int nopeus;       // Nopeusarvo, jota muuttamalla kaikkien käskyjen nopeus vaihtuu
int randomint;    // Satunnaisen kokonaisluvun taltiointia varten
int etaisyys;     // Etäisyyksien mittaukseen käytetyt muuttujat suunnistettaessa
long kesto;

Servo swivel;       // Servon moodina pyyhkäisy
int servoAsento = 90; // Servomoottorin asento alussa

// ASETUKSET
void setup() {
  Serial.begin(9600);       // Aloita serial portin kommunikointi nopeudella 9600 baud

  swivel.attach(10);        // Servo kiinnitettynä pinniin 10
  swivel.write(servoAsento);  // Servon asennon alustus

  pinMode(moottoriA, OUTPUT);   // Aseta moottorien kontrollipinnit outputeiksi
  pinMode(moottoriB, OUTPUT);   // B = vasemman- ja A = oikeanpuoleinen moottori
  pinMode(suuntaA_taa, OUTPUT);
  pinMode(suuntaA_eteen, OUTPUT);
  pinMode(suuntaB_taa, OUTPUT);
  pinMode(suuntaB_eteen, OUTPUT);

  pinMode(puna, OUTPUT);    // Aseta ledien kontrollipinnit outputeiksi
  pinMode(kelt, OUTPUT);
  pinMode(vihr, OUTPUT);

  pinMode(trigPin, OUTPUT); // Ultraäänisensorin pinnien määritykset
  pinMode(echoPin, INPUT);

  nopeus = 255;             // Nopeuden asetus haluttuun arvoon väliltä 0-255

  draw();                   // Piirrä käyttöohjeet serial monitor terminaaliin
}

void loop() {
  if (Serial.available())
  {
    inbit = Serial.read();

    switch (inbit) {
      case 'w':
        eteen(nopeus);
        break;
      case 's':
        taakse(nopeus);
        break;
      case 'a':
        pyoriVas(nopeus);
        break;
      case 'd':
        pyoriOik(nopeus);
        break;
      case 'q':
        kaannyVas(nopeus);
        break;
      case 'e':
        kaannyOik(nopeus);
        break;
      case 'z':
        potkaise();
        break;
      case 'x':
        jarruta();
        break;
      case 'c':
        sammuta();
        break;
      case 't':
        tuuleta();
        break;
      case 'g':
        suunnista();
        break;
      case 'b':
        tanssiSandstorm();
        break;
      case '1':
        tanssiEdestakas(250, 4);
        break;
      case '2':
        tanssiKierrosVas();
        break;
      case '3':
        tanssiKierrosOik();
        break;
      case '4':
        tanssiPyoriVas();
        break;
      case '5':
        tanssiPyoriOik();
        break;
      case '6':
        tanssiMiniTwerk();
        break;
      case '7':
        tanssiMegaTwerk();
        break;
      default:
        sammuta();
        break;
    }
  }
}

// Liikkumisen metodit
void eteen(int nopeus) {  // Liiku eteenpäin
  digitalWrite(suuntaA_taa, 0);
  digitalWrite(suuntaA_eteen, 1);
  digitalWrite(suuntaB_taa, 0);
  digitalWrite(suuntaB_eteen, 1);

  analogWrite(moottoriA, nopeus);
  analogWrite(moottoriB, nopeus);

  digitalWrite(vihr, HIGH);
}

void taakse(int nopeus) {  // Liiku taaksepäin
  digitalWrite(suuntaA_taa, 1);
  digitalWrite(suuntaA_eteen, 0);
  digitalWrite(suuntaB_taa, 1);
  digitalWrite(suuntaB_eteen, 0);

  analogWrite(moottoriA, nopeus);
  analogWrite(moottoriB, nopeus);

  digitalWrite(puna, HIGH);
}

void kaannyVas(int nopeus) { // Käänny vasemmalle liikkuen eteenpäin
  digitalWrite(suuntaA_taa, 0);
  digitalWrite(suuntaA_eteen, 1);
  digitalWrite(suuntaB_taa, 0);
  digitalWrite(suuntaB_eteen, 1);

  analogWrite(moottoriA, nopeus);
  analogWrite(moottoriB, nopeus / 4);

  digitalWrite(vihr, HIGH);
  digitalWrite(kelt, HIGH);
}

void kaannyOik(int nopeus) { // Käänny oikealle liikkuen eteenpäin
  digitalWrite(suuntaA_taa, 0);
  digitalWrite(suuntaA_eteen, 1);
  digitalWrite(suuntaB_taa, 0);
  digitalWrite(suuntaB_eteen, 1);

  analogWrite(moottoriA, nopeus / 4);
  analogWrite(moottoriB, nopeus);

  digitalWrite(vihr, HIGH);
  digitalWrite(kelt, HIGH);
}

void pyoriVas(int nopeus) {  // Pyöri vasemmalle paikallaan
  digitalWrite(suuntaA_taa, 0);
  digitalWrite(suuntaA_eteen, 1);
  digitalWrite(suuntaB_taa, 1);
  digitalWrite(suuntaB_eteen, 0);

  analogWrite(moottoriA, nopeus / 2);
  analogWrite(moottoriB, nopeus / 2);

  digitalWrite(puna, HIGH);
  digitalWrite(kelt, HIGH);
}

void pyoriOik(int nopeus) {  // Pyöri oikealle paikallaan
  digitalWrite(suuntaA_taa, 1);
  digitalWrite(suuntaA_eteen, 0);
  digitalWrite(suuntaB_taa, 0);
  digitalWrite(suuntaB_eteen, 1);

  analogWrite(moottoriA, nopeus / 2);
  analogWrite(moottoriB, nopeus / 2);

  digitalWrite(puna, HIGH);
  digitalWrite(kelt, HIGH);
}

void jarruta() {             // Lyhyt jarrutus
  digitalWrite(suuntaA_taa, 1);
  digitalWrite(suuntaA_eteen, 1);
  digitalWrite(suuntaB_taa, 1);
  digitalWrite(suuntaB_eteen, 1);

  analogWrite(moottoriA, 0);
  analogWrite(moottoriB, 0);

  digitalWrite(puna, 1);
  digitalWrite(kelt, 1);
  digitalWrite(vihr, 1);

  delay(100);
}

void sammuta() {            // Pysäytä moottorit ilman jarrutusta
  digitalWrite(suuntaA_taa, 0);
  digitalWrite(suuntaA_eteen, 0);
  digitalWrite(suuntaB_taa, 0);
  digitalWrite(suuntaB_eteen, 0);

  analogWrite(moottoriA, 0);
  analogWrite(moottoriB, 0);

  digitalWrite(puna, LOW);
  digitalWrite(kelt, LOW);
  digitalWrite(vihr, LOW);
}

void potkaise() {            // Potkaisu! Ota vauhtia ja pyöritä servomoottoria 90 astetta ja palauta
  taakse(63);
  delay(1000);
  sammuta();
  eteen(255);
  delay(250);
  sammuta();
  servoAsento = servoAsento - 90;
  swivel.write(servoAsento);
  delay(500);
  servoAsento = servoAsento + 90;
  swivel.write(servoAsento);

  serial_flush();
}

// Apufunktio serialin lukemisen bufferin tyhjentämiseen.
void serial_flush() {             // Ilman tätä esim. "potkaise" kutsutaan useasti, kun käytetään ulkoista kauko-ohjainta.
  while (Serial.available ())
  {
    roskis = Serial.read();        // Jos jotain tulee niin luetaan se pois ja hävitetään bittiavaruuteen
  }
}

void draw() {                // Jalkapallo-Jaakon logon ja käyttöohjeiden printtaus serial monitoriin
  Serial.println("                                                                      ");
  Serial.println("       _...----.._                          Käyttöohjeet              ");
  Serial.println("    ,:':::::.      `>.              -------------------------------   ");
  Serial.println("  ,' |:::::;'      |:::.            |    Q    |    W    |    E    |   ");
  Serial.println(" /    `'::'        :::::\\           |käännyVas|eteenpäin|käännyOik|  ");
  Serial.println("/          _____     `::;\\          -------------------------------  ");
  Serial.println(":         /Jalka\\      `  :         |    A    |    S    |    D    |  ");
  Serial.println("| ,.     /:Pallo:\\        |         |pyöriVas | peruuta |pyöriOik |  ");
  Serial.println("|;:::.   `:Jaakko'        |         -------------------------------   ");
  Serial.println("::::::     `::;'      ,.  ;         |    Z    |    X    |    C    |   ");
  Serial.println(" \\:::'              ,::::/          |potkaise!| jarruta | sammuta |  ");
  Serial.println("  \\                 \\:::/           ------------------------------- ");
  Serial.println("   `.     ,:.        :;'            |    T    |    G    |    B    |   ");
  Serial.println("     `-.::::::..  _.''              | tuuleta!|suunnista| tanssi! |   ");
  Serial.println("        ```----'''                  -------------------------------   ");
}
