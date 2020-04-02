// Ledien vilkutukset yms, nimet kuvaavat toiminnan
void sytytaLed() {  // Sytytä kaikki
  digitalWrite(puna, HIGH);
  digitalWrite(kelt, HIGH);
  digitalWrite(vihr, HIGH);
}

void sytytaLed(int aika) { // Sytytä kaikki tietyksi aikaa
  digitalWrite(puna, HIGH);
  digitalWrite(kelt, HIGH);
  digitalWrite(vihr, HIGH);
  delay(aika);
}

void sammutaLed() { // Sammuta kaikki
  digitalWrite(puna, LOW);
  digitalWrite(kelt, LOW);
  digitalWrite(vihr, LOW);
}

void vilkutaLed(int x) {
  for (int i = 0; i < x; i++) {
    digitalWrite(puna, HIGH);
    digitalWrite(kelt, HIGH);
    digitalWrite(vihr, HIGH);
    delay(100);
    digitalWrite(puna, LOW);
    digitalWrite(kelt, LOW);
    digitalWrite(vihr, LOW);
    delay(100);
  }
}

void ledimato1(int x) {          // Ledit syttyvät takaa eteenpäin
  for (int i = 0; i < x; i++) {
    digitalWrite(puna, HIGH);
    delay(50);
    digitalWrite(puna, LOW);
    delay(50);
    digitalWrite(kelt, HIGH);
    delay(50);
    digitalWrite(kelt, LOW);
    delay(50);
    digitalWrite(vihr, HIGH);
    delay(50);
    digitalWrite(vihr, LOW);
    delay(50);
  }
}

void ledimato2(int x) {          // Ledit syttyvät edestä taaksepäin
  for (int i = 0; i < x; i++) {
    digitalWrite(vihr, HIGH);
    delay(50);
    digitalWrite(vihr, LOW);
    delay(50);
    digitalWrite(kelt, HIGH);
    delay(50);
    digitalWrite(kelt, LOW);
    delay(50);
    digitalWrite(puna, HIGH);
    delay(50);
    digitalWrite(puna, LOW);
    delay(50);
  }
}

void ledimato3(int x) {          // Ledit syttyvät edestakaisin yht 400*x ms
  for (int i = 0; i < x; i++) {
    digitalWrite(vihr, HIGH);
    delay(50);
    digitalWrite(vihr, LOW);
    delay(50);
    digitalWrite(kelt, HIGH);
    delay(50);
    digitalWrite(kelt, LOW);
    delay(50);
    digitalWrite(puna, HIGH);
    delay(50);
    digitalWrite(puna, LOW);
    delay(50);
    digitalWrite(kelt, HIGH);
    delay(50);
    digitalWrite(kelt, LOW);
    delay(50);
  }
}
