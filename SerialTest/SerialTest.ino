void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
char a=Serial.read();
digitalWrite(8,LOW);
digitalWrite(7,LOW);
if(a=='1')
{digitalWrite(8,HIGH);delay(500);}
if(a=='2')
{digitalWrite(7,HIGH);delay(500);}
}
