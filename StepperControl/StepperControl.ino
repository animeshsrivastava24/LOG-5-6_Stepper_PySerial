
#include <Stepper.h>

const int TotalSteps = 64; // total steps per revolution by the 28BYJ-48 stepper motor

Stepper myStepper(TotalSteps, 3, 4, 5, 6); // an object of the class 'Stepper' is created defined inside 'Stepper.h'

int led1 = 7;
int led2 = 8;
int Button1 = 9;
int Button2 = 10;
int ForwardCount = 0;  // variable to store the number of steps the motor has taken in clockwise sense
int ReverseCount = 0; //variable to store the number of steps taken in anti-clockwise direction
int Position;
int SpeedVar = 0;  // variable to be passed as an argument while controlling the speed of rotation       
char keyword;

void setup() {
  //initialise by declaring the pins as input/output
  pinMode(3,1);
  pinMode(4,1);
  pinMode(5,1);
  pinMode(6,1);
  pinMode(7,1);
  pinMode(8,1);
  pinMode(A0,0);
  Serial.begin(9600);//Serial Communications are initialised to start communicating by the Serial Monitor
  Serial.println("Ready");
  myStepper.setSpeed(15);
  
}

int FindSpeed()
{
  return analogRead(A0);
}

int FindPosition()
{
  if(ForwardCount>1024)
  {
    ForwardCount=0;
    Position=ForwardCount;
  }
  else
  {
    Position=ForwardCount;
  }
}

void OneCompleteRotation()
{
  digitalWrite(led1,HIGH);
  for(int i=0;i<1024;i++)
  {
    myStepper.setSpeed(60);
    myStepper.step(2);
    ForwardCount++;
    FindPosition();
    Serial.println(Position);
  }
  digitalWrite(led1,LOW);
}

void Step(int x)
{
  myStepper.step(x*2);
}

void loop() 
{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  if(Serial.available()>0)
  {
    keyword=Serial.read();
    if(keyword=='1')
    {
      digitalWrite(led1,HIGH);
      Step(1);
      ForwardCount++;
      FindPosition();
      Serial.println(Position);
      delay(1);
    }
    if(keyword=='2')
    {
      OneCompleteRotation();
      delay(1);
    }
      
  }
  else if(digitalRead(Button1)==HIGH)
  {
    digitalWrite(led1,HIGH);
    Step(10);
  }
  
}

