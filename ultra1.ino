int trigpin1=13;    //penginisal kaki trigpin masuk pin 3
int echopin1=12;
float durasi1, jarak1;
int trigpin2=7;    //penginisal kaki trigpin masuk pin 3
int echopin2=6;
float durasi2, jarak2;
const int pinBuzzer = 10;

void setup() {
Serial.begin(9600); //memulai serial
pinMode(trigpin1,OUTPUT);  //pin trigpin sebagai OUTPUT
pinMode(echopin1,INPUT);
pinMode(trigpin2,OUTPUT);  //pin trigpin sebagai OUTPUT
pinMode(echopin2,INPUT);
pinMode(11, OUTPUT);
pinMode(pinBuzzer, OUTPUT);  
}

void loop() {
digitalWrite(trigpin1,LOW); 
delayMicroseconds(2);
digitalWrite(trigpin1,HIGH);  
delayMicroseconds(10);
digitalWrite(trigpin1,LOW);    
int durasi1 = pulseIn(echopin1,HIGH);   //pin echo membaca atau menerima sinyal
int jarak1 = durasi1 /58;    //rumus dalam cm

digitalWrite(trigpin2,LOW); 
delayMicroseconds(2);
digitalWrite(trigpin2,HIGH);  
delayMicroseconds(10);
digitalWrite(trigpin2,LOW);    
int durasi2 = pulseIn(echopin2,HIGH);   //pin echo membaca atau menerima sinyal
int jarak2 = durasi2 /58;    //rumus dalam cm
if (jarak1 <= 12 && jarak2 <= 12) //jarak (cm) dapat diatur dan disesuaikan
{
  digitalWrite(11, HIGH);
  digitalWrite(pinBuzzer, HIGH);
  delay(200);
  digitalWrite(pinBuzzer, LOW);
  delay(200);
  
   
}
else 
{
  digitalWrite(11, LOW);
  
}
Serial.println(jarak1); //menampilkan nilai jarak pada serial
Serial.println(jarak2); //menampilkan nilai jarak pada serial
delay(1000);
 
}
