# Jalkapallo_Jaakko
Robotiikka-kurssin lopputyö. Rakensimme alusta asti robotin valitsemistamme osista ja ohjelmoimme sen toiminnot. Tämän robotti "pelaa jalkapalloa".

Jaettu Google photos albumi, jossa esimerkkejä Jaakon toiminnasta:
https://photos.app.goo.gl/cSrG7Hgc1SSKotdDA

## Robotin käyttötarkoitus

Alkuperäisen suunnitelman mukaan robotin oli tarkoitus pelata jalkapalloa.

Sen tehtävänä piti olla
1. Paikallistaa pallo
2. Kulkea sen luo
3. Ottaa pallo haltuun
4. Kääntyä kohti maalia
5. Potkaista pallo maaliin
6. Tuulettaa!

En kuitenkaan koskaan saanut tällaisen robotin toiminnalle kriittistä palloa, jonka robotti osaisi
löytää, joten suunnitelma eli hieman. Korona-tilanne ja rajalliset komponentit
rajoittivat uuttakin toteutusta.

Tällä hetkellä robotti osaa
1. Totella käskyjä serial-portin kautta, jolloin sitä voi ohjata kuten RC-autoa.
2. Käskyt, joita robotti tottelee ovat
    q käänny vasemmalle liikkuen samalla eteenpäin
    w eteenpäin
    e käänny oikealle liikkuen samalla eteenpäin
    a pyöri paikallaan vasemmalle
    s peruuta
    d pyöri paikallaan oikealle
    z potkaise palloa
    x jarruta
    c sammuta kaikki ledit ja moottorit
    t tuuleta, tanssii pienen ennalta ohjelmoidun tanssi ja vilkuttaa ledejä
    g suunnista, ajaa eteenpäin, kunnes löytää edestään esteen ja kääntyy oikealle 90 astetta ja jatkaa sitten eteenpäin ja toistaa           edellä mainittua
    b tanssi, tanssii satunnaisen 10 eri liikkeestä muodostuvan tanssin
    
Näistä vain ”g suunnista” on tila, jossa robotti mittaa ympäristöään ja osaa tehdä itsenäisiä päätöksiä mittausten pohjalta.
Robotin ohjaamiseen voi käyttää mitä tahansa oikein konfiguroitua kauko-ohjainta. Itse käytin Processing 3 –työkalulla ohjelmoimaani kauko-ohjainta.

## Kuinka lähestyimme ongelmaa
Lähestyin ongelmaa, vai pitäisikö sanoa kaikkia ongelmia, hyvin pragmaattisesti ja virheistä oppien. Jokainen iteraatio paranteli robottia joltain osin, vaikka välillä liitäntöjä hajosi ja komponentit lakkasivat toimimasta, mutta näistäkin tilanteista opittiin paljon.

Projekti alkoi rungon miettimisellä ja DC-moottoreiden kiinnityksellä siihen. Tämän päälle liitin akun ja toisen kerroksen, johon Arduino Uno + motorshield ja kaikki muut komponentit liitettiin. Meillä oli kuitenkin alusta asti selkeä visio jalkapallorobotin toiminnasta ja isot linjat sen toteutuksesta oli mietitty heti projektin alussa. Lopullinen muoto eli projektin edetessä ja tämän
Korona-episodin myötä myös toimintaperiaatteet sekä lopullinen ulkomuoto muuttuivat radikaalisti.

## Robotin toteutus

**Osat**
- Arduino Uno
- Motorshield
- 6 v akku
- 2x DG02S-2M 48:1välityksellä olevaa DC-moottoria
- DF15MG servomoottori
- 6 lediä (2x vihreä, 2x keltainen ja 2x punainen)
- HC-SR04 ultraäänisensori
- Hyppykaapeleita, improvisoituja kaapeleita, resistoreja
    
**Kirjastot**
- Servo.h
    
**Algoritmit**
Simppeli suunnistusalgoritmi:
1. jos edessä tilaa -> aja eteenpäin
2. tai jos edessä este alle 10 cm päässä -> pysähdy ja käänny 90 astetta oikealle
3. toista
        
## Robotin parhaat puolet
- Robotti on pieni ja ketterä
- Reagoi käskyihin nopeasti ja kontrollointi kauko-ohjaimella on miellyttävää
- Potkaisumekanismi servomoottorilla onnistui hyvin
- Suunnistus ultraäänisensorin avulla onnistuu hyvin
- Käskyjen vastaanotto ja päätösteon visualisointi ledeillä havainnollistaa robotin toimintaa ja päätöksentekoa hyvin
- Suurin osa liitoksista ovat kestäviä ja osat napakasti kiinni rungossa eli ei helposti mene rikki
- Uskomaton Daruden Sandstorm kappaleeseen synkronoitu tanssi.
- Ulkonäkö

## Kehitysideoita
1. Infrapuna-sensorilla ja oikeanlaisella pallolla robotin saisi pelaamaan jalkapalloa
itsenäisesti
2. USB-johto tekee robotista vähän kömpelön. Esim. xbeellä ja toisella akulla kaukoohjattavuus poistaisi tämän ongelman.
3. Robotin voisi koteloida, jolloin saataisiin vielä parempi ulkonäkö ja suojaus iskuilta.
4. Lisää tanssimuuveja
