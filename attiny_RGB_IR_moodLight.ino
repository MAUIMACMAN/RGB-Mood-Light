/*ATtiny85 RGB Mood Light
Zwei Funktionen: Fade und Farbwahl per IR-Fernsteuerung
Es kann eine x-beliebige IR-Fernsteuerung benutzt werden
*/

const int redPin = 1;           // Pin fuer Rot 
const int grnPin = 2;           // Pin fuer Gruen
const int bluPin = 3;           // Pin fuer Blau
const int sensor = 4;           // Pin fuer IR-Sensor
const int schalter = 0;         // Pin fuer Funktionsschalter
int delayColor = 7000;          // Zeitintervall fuer Farbwechsel bei Fade

int mode = 0;                   //  Variable fuer Modus-Wahl (Fade oder einzelne Farben)

void setup()
{    
  pinMode(redPin, OUTPUT);    
  pinMode(grnPin, OUTPUT);    
  pinMode(bluPin, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(schalter, INPUT);
}

void loop() {

if (digitalRead(sensor) == LOW){
  delay(100);
  mode++;
}

if (mode > 7){
mode = 1;
}

// Fade Funktion
while (digitalRead(schalter) == HIGH){
redtoyellow();
yellow();
delay(delayColor);
yellowtogreen();
green();
delay(delayColor);
greentocyan();
cyan();
delay(delayColor);
cyantoblue();
blue();
delay(delayColor);
bluetomagenta();
magenta();
delay(delayColor);
magentatored();
red();
delay(delayColor);
}

// Einzelne Farben
if (mode == 1){
yellow();
}

if (mode == 2){
green();
}

if (mode == 3){
cyan();
}

if (mode == 4){
blue();
}

if (mode == 5){
magenta();
}

if (mode == 6){
red();
}

if (mode == 7){
white();
}
}

// FUNCTIONS

void cyantoblue()
{
  digitalWrite(redPin, HIGH);
  digitalWrite(bluPin, LOW);

  // fade up green
  for(byte i=1; i<100; i++) {
    byte on  = i;
    byte off = 100-on;
    for( byte a=0; a<100; a++ ) {
      digitalWrite(grnPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(grnPin, LOW);
      delayMicroseconds(off);
    }
  }
}

void bluetomagenta()
{
  digitalWrite(grnPin, HIGH);
  digitalWrite(bluPin, LOW);

  // fade down red
  for(byte i=1; i<100; i++) {
    byte on  = 100-i;
    byte off = i;
    for( byte a=0; a<100; a++ ) {
      digitalWrite(redPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(redPin, LOW);
      delayMicroseconds(off);
    }
  }
}


void magentatored()
{
  digitalWrite(grnPin, HIGH);
  digitalWrite(redPin, LOW);

  // fade up blue
  for(byte i=1; i<100; i++) {
    byte on  = i;
    byte off = 100-on;
    for( byte a=0; a<100; a++ ) {
      digitalWrite(bluPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(bluPin, LOW);
      delayMicroseconds(off);
    }
  }
}



void redtoyellow()
{
  digitalWrite(bluPin, HIGH);
  digitalWrite(redPin, LOW);

  // fade down green
  for(byte i=1; i<100; i++) {
    byte on  = 100-i;
    byte off = i;
    for( byte a=0; a<100; a++ ) {
      digitalWrite(grnPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(grnPin, LOW);
      delayMicroseconds(off);
    }
  }
}


void yellowtogreen()
{
  digitalWrite(bluPin, HIGH);
  digitalWrite(grnPin, LOW);

  // fade up red
  for(byte i=1; i<50; i++) {
    byte on  = i;
    byte off = 50-on;
    for( byte a=0; a<50; a++ ) {
      digitalWrite(redPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(redPin, LOW);
      delayMicroseconds(off);
    }
  }
}



void greentocyan()
{
  digitalWrite(redPin, HIGH);
  digitalWrite(grnPin, LOW);

  // fade down blue
  for(byte i=1; i<100; i++) {
    byte on  = 100-i;
    byte off = i;
    for( byte a=0; a<100; a++ ) {
      digitalWrite(bluPin, HIGH);
      delayMicroseconds(on);
      digitalWrite(bluPin, LOW);
      delayMicroseconds(off);
    }
  }
}

void blue(){
  digitalWrite(redPin, HIGH);
  digitalWrite(grnPin, HIGH);
  digitalWrite(bluPin, LOW);
}

void magenta(){
  digitalWrite(redPin, LOW);
  digitalWrite(grnPin, HIGH);
  digitalWrite(bluPin, LOW);
}

void red(){
  digitalWrite(redPin, LOW);
  digitalWrite(grnPin, HIGH);
  digitalWrite(bluPin, HIGH);
}

void yellow(){
  digitalWrite(redPin, LOW);
  digitalWrite(grnPin, LOW);
  digitalWrite(bluPin, HIGH);
}

void green(){
  digitalWrite(redPin, HIGH);
  digitalWrite(grnPin, LOW);
  digitalWrite(bluPin, HIGH);
}

void cyan(){
  digitalWrite(redPin, HIGH);
  digitalWrite(grnPin, LOW);
  digitalWrite(bluPin, LOW);
}

void white(){
  digitalWrite(redPin, LOW);
  digitalWrite(grnPin, LOW);
  digitalWrite(bluPin, LOW);
}
