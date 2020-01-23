#include <Servo.h> //Biblioteka odpowiedzialna za serwa
 
Servo serwomechanizm_1;  //Tworzymy obiekt, dzięki któremu możemy odwołać się do serwa 
Servo serwomechanizm_2;
Servo serwomechanizm_3;
Servo serwomechanizm_4;
Servo serwomechanizm_5;
int pozycja_1 = 90; //Aktualna pozycja serwa 0-180
int pozycja_2 = 90; 
int pozycja_3 = 90;
int pozycja_4 = 90;  
int pozycja_5 = 90;  
int zmiana = 5; //Co ile ma się zmieniać pozycja serwa?
int zmiana_2 = 2; //zmiana stopni dla chwytaka 
//deklaracja dla dzojstikow na wejscia analogowe 
const int inX = A0; // analog input for x-axis
const int inY = A1; // analog input for y-axis
const int inX2 = A2; // analog input for x-axis
const int inY2 = A3; // analog input for y-axis
//wartosci przyjmoane podczas nacisniecia od 0 do 1023
int xValue = 0; // variable to store x value
int yValue = 0; // variable to store y value
int x2Value = 0; // variable to store x value
int y2Value = 0; // variable to store y value
void setup() { 
  pinMode(inX, INPUT); // setup x input
  pinMode(inY, INPUT); // setup y input
  pinMode(inX2, INPUT); // setup x input
  pinMode(inY2, INPUT); // setup y input
  serwomechanizm_1.attach(2);  //Serwomechanizm podłączony do pinu 9
  serwomechanizm_2.attach(3);
  serwomechanizm_3.attach(4);
  serwomechanizm_4.attach(5);
  serwomechanizm_5.attach(6);
  Serial.begin(9600); // Setup serial connection for print out to console
}
void loop() {
  xValue = analogRead(inX); // reading x value [range 0 -> 1023]
  yValue = analogRead(inY); // reading y value [range 0 -> 1023]
  x2Value = analogRead(inX2); // reading x value [range 0 -> 1023]
  y2Value = analogRead(inY2); // reading y value [range 0 -> 1023]
// pierwsze serwo
if(xValue>600)
{
    if(pozycja_1<=175){pozycja_1 =pozycja_1 + zmiana;}
    serwomechanizm_1.write(pozycja_1); //Wykonaj ruch
    delay(200); //Opóźnienie dla lepszego efektu 
    
    
  
}
if(xValue<400)
{
   if(pozycja_1>=5){pozycja_1 =pozycja_1 - zmiana;}
    serwomechanizm_1.write(pozycja_1); //Wykonaj ruch
    delay(200); //Opóźnienie dla lepszego efektu 
   
  
}  
// 2 i 3 serwo
if(yValue>600)
{
    if(pozycja_2<=175){pozycja_2 =pozycja_2 + zmiana;} 
    serwomechanizm_2.write(pozycja_2); //Wykonaj ruch
     serwomechanizm_3.write(pozycja_2);
    delay(200); //Opóźnienie dla lepszego efektu 
    
  
}
if(yValue<400)
{
  if(pozycja_2>=5){pozycja_2 =pozycja_2 - zmiana;} 
    serwomechanizm_2.write(pozycja_2); //Wykonaj ruch
    serwomechanizm_3.write(pozycja_2); //Wykonaj ruch
    delay(200); //Opóźnienie dla lepszego efektu 
} 
// 4 serwo to przy chwytaku 
if(x2Value>600)
{
  if(pozycja_4<=175){pozycja_4 =pozycja_4+ zmiana;} 
    serwomechanizm_4.write(pozycja_4); //Wykonaj ruch
    delay(200); //Opóźnienie dla lepszego efektu 
 
  
}
if(x2Value<400)
{
   if(pozycja_4>=5){pozycja_4 =pozycja_4 - zmiana;}
    serwomechanizm_4.write(pozycja_4); //Wykonaj ruch
    delay(200); //Opóźnienie dla lepszego efektu 
 
  
} 
//chwytak
if(y2Value<400)
{
   if(pozycja_5<=174){pozycja_5 =pozycja_5 + zmiana_2;} 
    serwomechanizm_5.write(pozycja_5); //Wykonaj ruch
    delay(200); //Opóźnienie dla lepszego efektu 
}
if(y2Value>600)
{
   if(pozycja_5>=94){pozycja_5 =pozycja_5 - zmiana_2;}
    serwomechanizm_5.write(pozycja_5); //Wykonaj ruch
    delay(200); //Opóźnienie dla lepszego efektu  
}  
}
