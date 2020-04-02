/* Suunnistaessaan Jalkapallo_Jaakko toimii itsenäisesti.

   Käytössä on tosin vain yksi ultraäänisensori, joten ohjelma on simppeli:
   -> liiku eteenpäin kunnes este alle 10 cm päässä
   -> käänny 90 astetta oikealle ja jatka matkaa.
   -> toista.

   Toimintojen etenemisestä ja etäisyyksistä raportoidaan serial portin kautta. Voidaan lukea esim. serial monitorilla.
*/

void suunnista() {
  Serial.println("Suunnistus aloitettu!");
  Serial.println("Liikun nyt itsenäisesti!");
  vilkutaLed(8);

  while (true) {                        // Suunistetaan kunnes toisin käsketään (x:n syöttö lopettaa)
    if (Serial.available()) {
      inbit = Serial.read();
      if (inbit == 'x') {
        jarruta();
        sammuta();
        Serial.println("\nSuunnistus keskeytetty!");
        vilkutaLed(8);
        draw();
        break;
      }
    }
    digitalWrite(trigPin, LOW);         // Tyhjennä trigPin
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);        // Aseta trigPin HIGH tilaan 10 ms ajaksi
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    kesto = pulseIn(echoPin, HIGH);     // Lukee echoPin, palauttaa heijastuneen ääniaallon matka-ajan muodossa ms

    etaisyys = kesto * 0.0343 / 2;      // Lasketaan heijastaneen pinnan etäisyys

    Serial.print("Edessä tilaa ");
    Serial.print(etaisyys);
    Serial.println(" cm.");

    if (etaisyys < 10) {                // Toiminta jos jokin este alle 10 cm päässä
      jarruta();
      Serial.print("Este havaittu alle 10 cm päässä!");
      vilkutaLed(2);
      taakse(75);
      delay(400);
      Serial.println("Käännyn oikealle 90 astetta.");
      kaannyOik90();
      Serial.println("Matka jatkukoon!");
      ledimato1(2);
    } else if (etaisyys > 1000) {       // Toiminta jos arvot ovat tod. näk. virheelliset
      jarruta();
      Serial.println("Etäisyyssensorin lukemissa on jotain häikkää. Vaihdan suuntaa.");
      vilkutaLed(2);
      taakse(75);
      delay(400);
      Serial.println("Käännyn oikealle 90 astetta.");
      kaannyOik90();
      Serial.println("Matka jatkukoon!");
      ledimato1(2);
    } else {
      ajaEteenpain();
    }
  }
}

void kaannyOik90() {
  pyoriOik(200);
  delay(600);
  jarruta();
  delay(200);
}

void ajaEteenpain() {
  eteen(75);
  delay(1);
}
