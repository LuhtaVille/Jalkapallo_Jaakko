# Jalkapallo_Jaakko
Robotiikka-kurssin lopputyö. Rakensimme alusta asti robotin valitsemistamme osista ja ohjelmoimme sen toiminnot. Tämän robotti "pelaa jalkapalloa".

Jaettu Google photos albumi, jossa esimerkkejä Jaakon toiminnasta:
https://photos.app.goo.gl/cSrG7Hgc1SSKotdDA

# Robotin käyttötarkoitus

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

# Kuinka lähestyimme ongelmaa
Lähestyin ongelmaa, vai pitäisikö sanoa kaikkia ongelmia, hyvin pragmaattisesti ja virheistä oppien. Jokainen iteraatio paranteli robottia joltain osin, vaikka välillä liitäntöjä hajosi ja komponentit lakkasivat toimimasta, mutta näistäkin tilanteista opittiin paljon.

Projekti alkoi rungon miettimisellä ja DC-moottoreiden kiinnityksellä siihen. Tämän päälle liitin akun ja toisen kerroksen, johon Arduino Uno + motorshield ja kaikki muut komponentit liitettiin. Meillä oli kuitenkin alusta asti selkeä visio jalkapallorobotin toiminnasta ja isot linjat sen toteutuksesta oli mietitty heti projektin alussa. Lopullinen muoto eli projektin edetessä ja tämän
Korona-episodin myötä myös toimintaperiaatteet sekä lopullinen ulkomuoto muuttuivat radikaalisti.

