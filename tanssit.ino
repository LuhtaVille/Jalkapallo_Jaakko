/* Tanssit ovat hassuttelua ja robotin liikkuvuuden testailua varten.
   Idea näihin syntyikin liikkumistapoja mietittäessä.
*/

//Nuottien pituudet (ms) BPM 136:
int _16 = 110;
int _8 = 221;
int _4 = 441;
int _2 = 882;
int _1 = 1765;

void tanssiRandom() {           // Nyt tanssitaan! 10 randomilla valittua liikettä peräkkäin
  for (int i = 0; i < 10; i++) {
    randomint = random(0, 6);

    switch (randomint) {          // Switch perustuen randomintiin. Valitsee tanssiliikkeen sen mukaan.
      case 0:
        tanssiEdestakas(250, 4);
        break;
      case 1:
        tanssiKierrosVas();
        break;
      case 2:
        tanssiKierrosOik();
        break;
      case 3:
        tanssiPyoriVas();
        break;
      case 4:
        tanssiPyoriOik();
        break;
      case 5:
        tanssiMiniTwerk();
        break;
      case 6:
        tanssiMegaTwerk();
        break;
    }
  }
  serial_flush();
}

void tanssiSandstorm() {        // Daruden klassikobiisin ohjelmoidut askeleet.
  tanssiLiikuEteen(6960, 60);  // Eka isku. Ajoita tanssikäsky tähän iskuun!
  jarruta();
  tanssiLiikuTaakse(5020, 80);
  jarruta();
  sammutaLed();
  delay(1500);

  sytytaLed(_8);                // Toka isku
  sammutaLed();
  delay(_8);
  tanssiKierrosOik();           // dudu..
  delay(2100);

  sytytaLed(_8);                // dii dudu..
  sammutaLed();
  delay(_8);
  tanssiKierrosOik();
  delay (2300);

  tanssiEdestakas(441, 4);      // dudu intensifies
  tanssiEdestakas(221, 7);
  delay(221);

  tanssiKierrosVas();           // dududududuu
  tanssiServo(465, 1);
  tanssiTwerk(416, 2);
  delay(200);
  tanssiKierrosVas();
  tanssiServo(465, 1);
  tanssiTwerk(208, 4);
  delay(200);

  tanssiPyoriOik();             // dududududuu 2. kerta
  tanssiTwerk(383, 2);          
  delay(100);
  tanssiPyoriVas();
  tanssiTwerk(192, 4);
  delay(100);

  tanssiServo(441, 4);          // dududududuu 3. kerta
  tanssiKierrosOik();
  tanssiServo(441, 1);
  delay(224);
  tanssiServo(221, 8);
  tanssiKierrosOik();
  tanssiServo(221, 2);
  delay(224);

  tanssiPyoriOik();           // dududududuu 4. kerta  
  tanssiPyoriVas();
  tanssiTwerk(416, 2);
  tanssiTwerk(208, 4);

  ledimato3(100);
}

// Erinäiset tanssiliikkeet. Nimet kuvaavat toimintaa.
void tanssiEdestakas(int viive, int toisto) { //1
  for (int i = 0; i < toisto; i++) {
    eteen(255);
    delay(viive);
    sammuta();
    taakse(255);
    delay(viive);
    sammuta();
  }
}

void tanssiKierrosVas() { //2 1100 ms
  kaannyVas(255);
  delay(1000);
  jarruta();
  sammuta();
}

void tanssiKierrosOik() { //3 yht 1100 ms
  kaannyOik(255);
  delay(1000);
  jarruta();
  sammuta();
}

void tanssiPyoriVas() { //4 yht 1800 ms
  pyoriVas(255);
  delay(1700);
  jarruta();
  sammuta();
}

void tanssiPyoriOik() { //5 yht 1800 ms
  pyoriOik(255);
  delay(1700);
  jarruta();
  sammuta();
}

void tanssiMiniTwerk() { //6 yht 2100 ms
  for (int i = 0; i < 8; i++) {
    pyoriVas(255);
    delay(125);
    sammuta();
    pyoriOik(255);
    delay(125);
    sammuta();
  }
  jarruta();
}

void tanssiMegaTwerk() { //7 yht 2100 ms
  for (int i = 0; i < 4; i++) {
    pyoriVas(255);
    delay(250);
    sammuta();
    pyoriOik(255);
    delay(250);
    sammuta();
  }
  jarruta();
}

void tanssiTwerk(int viive, int toisto) { // yht 2*viive*toisto + 100 ms
  for (int i = 0; i < toisto; i++) {
    pyoriVas(255);
    delay(viive);
    sammuta();
    pyoriOik(255);
    delay(viive);
    sammuta();
  }
  jarruta();
}

void tanssiServo(int viive, int toisto) {
  viive = viive / 2 ;

  for (int i = 0; i < toisto; i++) {
    servoAsento = servoAsento - 90;
    swivel.write(servoAsento);
    delay(viive);
    servoAsento = servoAsento + 90;
    swivel.write(servoAsento);
    delay(viive);
  }
}

void tanssiLiikuEteen(int viive, int nopeus){
  digitalWrite(suuntaA_taa, 0);
  digitalWrite(suuntaA_eteen, 1);
  digitalWrite(suuntaB_taa, 0);
  digitalWrite(suuntaB_eteen, 1);

  analogWrite(moottoriA, nopeus);
  analogWrite(moottoriB, nopeus);

  digitalWrite(vihr, HIGH);
  digitalWrite(kelt, HIGH);
  digitalWrite(puna, HIGH);

  delay(viive);
}

void tanssiLiikuTaakse(int viive, int nopeus){
  digitalWrite(suuntaA_taa, 1);
  digitalWrite(suuntaA_eteen, 0);
  digitalWrite(suuntaB_taa, 1);
  digitalWrite(suuntaB_eteen, 0);

  analogWrite(moottoriA, nopeus);
  analogWrite(moottoriB, nopeus);

  digitalWrite(vihr, HIGH);
  digitalWrite(kelt, HIGH);
  digitalWrite(puna, HIGH);

  delay(viive);
}

void tuuleta() { //T
  vilkutaLed(4);
  tanssiPyoriVas();
  ledimato1(2);
  tanssiPyoriOik();
  ledimato2(2);
  tanssiPyoriVas();
  vilkutaLed(4);

  for (int i = 0; i < 3; i++) {
    servoAsento = servoAsento - 90;
    swivel.write(servoAsento);
    delay(300);
    servoAsento = servoAsento + 90;
    swivel.write(servoAsento);
    delay(300);
  }
  serial_flush();
}
