
 
int counter=0; 
int a1, a2; // luodaan muuttujat


int arvo = 0;
float vastus = 0;
float buffer;
int luku = 5;
float jannite;
float apu1, apu2, apu3, apu4;
void setup() 
{ 
  Serial.begin(9600); 
  noInterrupts(); // poistetaan keskseytykset käytöstä
  ADMUX &= B11011111; // nollataan 5 bitti joka ADC-tietorekisteriin viittaava
  ADMUX |= B01000000; // määritetään referenssi
  ADMUX &= B11110000; // nollataan/alustetaan lukija navat
  ADCSRA |= B10000000; //sallitaan ADC
  ADCSRA |= B00000111; // määritetään kello ADC:lle
  ADCSRA |= B00001000; //sallitaan keskeytys
  ADCSRA |= B01000000; //Sallitaan ADC käännös
  interrupts(); 
 
} 
 
void loop() 
{ 
 ADCSRA |= B01000000; // sallitaan ADC käännös

if(arvo){
    buffer = arvo * luku;
    jannite = (buffer)/1024.0;
    apu1 = pow(jannite,2);
    apu2 =1247.5*apu1;
    apu3 = 13229*jannite;
    vastus =-4376.2*jannite+20365;
    
    Serial.print("jannite: ");
    Serial.println(jannite);
    Serial.print("R2: ");
    Serial.println(vastus);

    delay(1000);
} }

 
ISR(ADC_vect) // keskseytys
{ 
  switch(counter)
  {
 
   case 0: 
    arvo =  ADCL | (ADCH << 8);  // luetaan ADC arvot a1 muuttujaan a1 inputista
    counter=1; //counterilla vaihdetaan casea seuraavaan mahdolliseen
    ADMUX &= B11110000; // nollataan input luku pinnit
    ADMUX |= B00000001; // määritetään 0 pinni ylös
    break; 
  case 1: 

  counter=0;
    break;
  } 
}
