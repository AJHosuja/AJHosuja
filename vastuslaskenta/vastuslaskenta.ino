int analogPin = A2;
int arvo = 0;
int luku = 5;
float jannite = 0;
float tunnettuVastus = 10000;
float vastus2 = 0;
float buffer = 0;

void setup(){
Serial.begin(9600);
}

void loop(){
  arvo = analogRead(analogPin);
  if(arvo){
    buffer = arvo * luku;
    jannite = (buffer)/1024.0;
    buffer = (luku/jannite) - 1;
    vastus2= tunnettuVastus * buffer;
    Serial.print("jannite: ");
    Serial.println(jannite);
    Serial.print("R2: ");
    Serial.println(vastus2);
    delay(1000);
  }
}
