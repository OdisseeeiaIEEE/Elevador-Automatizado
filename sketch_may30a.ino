/***************************BLUETOOTH CONTROLLED CAR CODE**************************/

//Declare the arduino pins

int lm1 = 9;
int lm2 = 8;
int rm1 = 7;
int rm2 = 6;


void setup()
{
  //initlize the mode of the pins
   pinMode(lm1,OUTPUT);
   pinMode(lm2,OUTPUT);
   pinMode(rm1,OUTPUT);
   pinMode(rm2,OUTPUT);


   //set the serial communication rate
  Serial.begin(9600);
}

void loop()
{
  //check whether arduino is reciving signal or not 
  while(Serial.available() == 0);
  char val = Serial.read() ;//reads the signal
  Serial.print(val);

  /*********For Forward motion*********/
  
  if (val == 'F')
  {
    Serial.println("FORWARD");
    digitalWrite(lm1,HIGH);  digitalWrite(rm1,HIGH);
    digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
    
  }

 
    /*********For Backward Motion*********/
  else if(val == 'B')
  {
  Serial.println("BACK");
      digitalWrite(lm2,HIGH);  digitalWrite(rm2,HIGH);
    digitalWrite(lm1,LOW);       digitalWrite(rm1,LOW);
  
  }
   /*********Right*********/
  else if(val == 'R')
  {
  Serial.println("RIGHT");
    digitalWrite(lm1,HIGH);  digitalWrite(rm2,HIGH);
    digitalWrite(lm2,LOW);       digitalWrite(rm1,LOW);
  }
   /*********Left*********/
  else if(val == 'L')
  {
   Serial.println("LEFT");
     digitalWrite(lm2,HIGH);  digitalWrite(rm1,HIGH);
    digitalWrite(lm1,LOW);       digitalWrite(rm2,LOW);
  
  }

  else
  {
  Serial.println("Invalid!!!");
     digitalWrite(lm1,LOW);  digitalWrite(rm1,LOW);
    digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);

  }
  
}
