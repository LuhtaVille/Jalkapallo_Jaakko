import processing.serial.*;

Serial port;
char inbit;

void setup() {

  size(300, 200);
  rectMode(RADIUS);

  println(Serial.list());
  port = new Serial(this, Serial.list()[2], 9600);

  textAlign(CENTER, CENTER);
  textSize(40);
  fill(#006600);
}   

void draw() {

  if (keyPressed) {
    inbit = key;
    background(255);

    switch (inbit) {
    case 'w':
      port.write('w');
      text("w\neteen", 150, 80);
      break;
    case 's':
      port.write('s');
      text("s\ntaakse", 150, 80);
      break;
    case 'a':
      port.write('a');
      text("a\npyöri vas.", 150, 80);
      break;
    case 'd':
      port.write('d');
      text("d\npyöri oik.", 150, 80);
      break;
    case 'q':
      port.write('q');
      text("q\nkäänny vas.", 150, 80);
      break;
    case 'e':
      port.write('e');
      text("e\nkäänny oik.", 150, 80);
      break;
    case 'z':
      port.write('z');
      text("z\npotku!", 150, 80);
      break;
    case 'x':
      port.write('x');
      text("x\npysahdy", 150, 80);
      break;
    case 'c':
      port.write('c');
      text("c\nsammuta", 150, 80);
      break;
    case 't':
      port.write('t');
      text("t\ntuuleta", 150, 80);
      break;
    case 'g':
      port.write('g');
      text("g\nsuunnista", 150, 80);
      break;
    case 'b':
      port.write('b');
      text("b\ntanssi", 150, 80);
      break;
    default:
      port.write('c');
      break;
    }
  } else {
    port.write('c');
    background(0);
  }
}
