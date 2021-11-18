#define LED 12 //
//int keskiarvo,1,2,3,4,5,6,7,8,9,10;
int i[9];
int x;
int analogPin1 = A0;
int analogPin2 = A1;



void setup()
{
 Serial.begin(9600);
 
 pinMode(LED, OUTPUT);
 noInterrupts(); // disable all interrupts
 TCCR1A = 0;
 TCCR1B = 0;
 TCNT1 = 0;
 OCR1A = 62500; // Määritetään kellon nopeus että yksi laskuri on 1 sek
 TCCR1B |= (1 << WGM12); // CTC mode
 TCCR1B |= (1 << CS12); // 256 prescaler
 TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt
 interrupts(); // enable all interrupts
}

void loop()
{

  

  Serial.print("Jeggu");
  Serial.print("\n");
}

ISR(TIMER1_COMPA_vect) // timer compare interrupt service routine
{

      

    Serial.print("kikkelit");
    Serial.print("\n");
     

}
