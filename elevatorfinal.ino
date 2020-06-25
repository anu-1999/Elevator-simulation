
int liftp=0,dstn=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT); //LSB 21
  pinMode(3,OUTPUT);//22
  pinMode(4,OUTPUT);//19
  pinMode(5,OUTPUT); //MSB 20
  pinMode(6,OUTPUT); //LSB 21
  pinMode(7,OUTPUT);//22
  pinMode(8,OUTPUT);//19
  pinMode(9,OUTPUT); //MSB 20
  pinMode(10,INPUT); //LSB 21
  pinMode(11,INPUT);//22
  pinMode(12,INPUT);//19
  pinMode(13,INPUT); //MSB 20


  // Make clr=HIGH
  digitalWrite(6,HIGH); //GF
  digitalWrite(7,HIGH);//FF
  digitalWrite(8,HIGH);//SF
  digitalWrite(9,HIGH);//TF
  digitalWrite(2,LOW); // Initial position of the lift
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int GF,FF,SF,TF;
  GF=digitalRead(10);
  FF=digitalRead(11);
  SF=digitalRead(12);
  TF=digitalRead(13);
  if(GF==LOW)
  {
    Serial.println("Requst from GF");
    dstn=0;
    ServiceGFR();
  }
  if(FF==LOW)
  {
    Serial.println("Requst from FF");
    dstn=3;
    ServiceFFR();
  }
  if(SF==LOW)
  {
    Serial.println("Requst from SF");
    dstn=6;
    ServiceSFR();
  }
  if(TF==LOW)
  {
    Serial.println("Requst from TF");
    dstn=9;
    ServiceTFR();
  }
  
  
} //end of loop(main)

void ServiceGFR()
{
  if(liftp==0 && dstn==0)
  {
  digitalWrite(6,LOW);
  digitalWrite(6,HIGH);
  }
  if(liftp==3 && dstn==0)
  {
    disp3();
    delay(1000);
    disp2();
    delay(1000);
    disp1();
    delay(1000);
    disp0();
    delay(1000);
     digitalWrite(6,LOW);
  digitalWrite(6,HIGH);
    
    liftp=0;
    
  }
  if(liftp==6 && dstn==0)
  {
  disp6();
 delay(1000);
 disp5();
 delay(1000);
 disp4();
 delay(1000); 
 disp3();
 delay(1000);
  disp2();
    delay(1000);
    disp1();
    delay(1000);
    disp0();
    delay(1000);
    digitalWrite(6,LOW);
  digitalWrite(6,HIGH);
    liftp=0;
  }
   if(liftp==9 && dstn==0)
 {
   disp9();
  delay(1000);
  disp8();
  delay(1000);
  disp7();
  delay(1000); 
   disp6();
  delay(1000);
  disp5();
  delay(1000);
  disp4();
  delay(1000); 
  disp3();
 delay(1000);
 disp2();
 delay(1000);
 disp1();
 delay(1000);
 disp0();
 delay(1000);
  digitalWrite(6,LOW);
 digitalWrite(6,HIGH);
 liftp=0;
 }
  
 }
void ServiceFFR()
 {
  if(liftp==3 && dstn==3)
  {
  digitalWrite(7,LOW);
  digitalWrite(7,HIGH);
  }
   if(liftp==0 && dstn==3)
   {
 disp0();
 delay(1000);
 disp1();
 delay(1000); 
 disp2();
 delay(1000);
 disp3();
 delay(1000);
 digitalWrite(7,LOW);
 digitalWrite(7,HIGH);
 liftp=3;
   }
  
    if(liftp==6 && dstn==3)
 {
   disp6();
 delay(1000);
 disp5();
 delay(1000);
 disp4();
 delay(1000); 
 disp3();
 delay(1000);
 digitalWrite(7,LOW);
 digitalWrite(7,HIGH);
 liftp=3;
 
 }
 if(liftp==9 && dstn==3)
   {
    disp9();
  delay(1000);
  disp8();
  delay(1000);
  disp7();
  delay(1000); 
  disp6();
 delay(1000);
  disp5();
 delay(1000);
 disp4();
 delay(1000); 
 disp3();
 delay(1000);
 digitalWrite(7,LOW);
 digitalWrite(7,HIGH);
 liftp=3;
   }
     
    
 
 }
  
 

 void ServiceSFR()
 {
  if(liftp==6 && dstn==6)
  {
  digitalWrite(8,LOW);
  digitalWrite(8,HIGH);
  }
 if(liftp==0 && dstn==6)
 {
 disp0();
 delay(1000);
 disp1();
 delay(1000); 
 disp2();
 delay(1000);
 disp3();
 delay(1000);
 disp4();
 delay(1000); 
 disp5();
 delay(1000);
 disp6();
 delay(1000);
 digitalWrite(8,LOW);
 digitalWrite(8,HIGH);
 liftp=6;
 }
 
 
 if(liftp==3 && dstn==6)
  {
     disp3();
  delay(1000);
  disp4();
  delay(1000);
  disp5();
  delay(1000); 
  disp6();
 delay(1000);
 digitalWrite(8,LOW);
 digitalWrite(8,HIGH);
 liftp=6;
  }
   if(liftp==9 && dstn==6)
   {
    disp9();
  delay(1000);
  disp8();
  delay(1000);
  disp7();
  delay(1000); 
  disp6();
 delay(1000);
 digitalWrite(8,LOW);
 digitalWrite(8,HIGH);
 liftp=6;
   }
 }
 void ServiceTFR()
 {
   if(liftp==9 && dstn==9)
  {
  digitalWrite(9,LOW);
  digitalWrite(9,HIGH);
  }
   if(liftp==0 && dstn==9)
 {
  
     disp0();
  delay(1000);
  disp1();
  delay(1000);
  disp2();
  delay(1000); 
   disp3();
  delay(1000);
  disp4();
  delay(1000);
  disp5();
  delay(1000); 
  disp6();
 delay(1000);
 disp7();
 delay(1000);
 disp8();
 delay(1000);
 disp9();
 delay(1000);
  digitalWrite(9,LOW);
 digitalWrite(9,HIGH);
 liftp=9;
 }
 if(liftp==3 && dstn==9)
 {
  disp3();
  delay(1000);
  disp4();
  delay(1000);
  disp5();
  delay(1000); 
  disp6();
 delay(1000);
 disp7();
 delay(1000);
 disp8();
 delay(1000);
 disp9();
 delay(1000);
  digitalWrite(9,LOW);
 digitalWrite(9,HIGH);
 liftp=9;
 }
 if(liftp==6 && dstn==9)
 {
   disp6();
 delay(1000);
 disp7();
 delay(1000);
 disp8();
 delay(1000);
 disp9();
 delay(1000);
  digitalWrite(9,LOW);
 digitalWrite(9,HIGH);
 liftp=9;
 }
  
 } 


void disp0()
{
  digitalWrite(2,LOW); 
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}
void disp1()
{
  digitalWrite(2,HIGH); 
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}
void disp2()
{
  digitalWrite(2,LOW); 
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}
void disp3()
{
  digitalWrite(2,HIGH); 
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}
void disp4()
{
  digitalWrite(2,LOW);   
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}
void disp5()
{
  digitalWrite(2,HIGH); 
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}
void disp6()
{
  digitalWrite(2,LOW); 
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}
void disp7()
{
  digitalWrite(2,HIGH); 
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}
void disp8()
{
  digitalWrite(2,LOW); 
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
}
void disp9()
{
  digitalWrite(2,HIGH); 
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
}
