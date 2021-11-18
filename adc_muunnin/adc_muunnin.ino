
 
int counter=0; 
int a1, a2; // luodaan muuttujat
float ka1;
float ka2;
int count1;
int count2;
int luku1;
int luku2;

 
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
delay(100); // hidastetaan looppia sekunnilla
 if (count1 >= 10){ // suoritetaan komento kun on laskettu 10 kertaa a1 navalta
  ka1=luku1/10;
  Serial.print("KA 1: a1 input: ");
  Serial.print(ka1);
  Serial.print("\n\n");
  luku1=0;
  count1=0;
 }
  if (count2 >= 10){ // suoritetaan komento
  ka2=luku2/10;
  Serial.print("KA 2: a2 input: ");
  Serial.print(ka2);
  Serial.print ("\n\n");
  luku2=0;
  count2=0;
 }
 Serial.print("\n");
 
} 
 
ISR(ADC_vect) // keskseytys
{ 
  switch(counter)
  {
 
   case 0: 
    a1 =  ADCL | (ADCH << 8);  // luetaan ADC arvot a1 muuttujaan a1 inputista
    counter=1; //counterilla vaihdetaan casea seuraavaan mahdolliseen
    ADMUX &= B11110000; // nollataan input luku pinnit
    ADMUX |= B00000001; // määritetään 0 pinni ylös
    luku1=luku1+a1; // lasketaan mitattu arvo yhteen edellisiin arvoihin.
    count1++; //lisätään countia.
    break; 
  case 1: 
    a2 =  ADCL | (ADCH << 8); // samat kuin ylhäällä
    counter=0; 
     ADMUX &= B11110000; 
     ADMUX |= B00000010;
     luku2=luku2+a2;
     count2++;
    break;
  } 
}
