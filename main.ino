#define sensor1 A3
  #define sensor2 A4
  #define sensor3 A5
  
  #define inicializacao 4
  
  #define andar1 A0
  #define andar2 A1
  #define andar3 A2
  
  #define subir 8
  #define descer 6

  
  #define andar1Led 13
  #define andar2Led 12
  #define andar3Led 11


  
  void setup (){
  Serial.begin(9600);
  
  pinMode(inicializacao, OUTPUT);
  pinMode(subir, OUTPUT);
  pinMode(descer, OUTPUT);
  pinMode(andar1Led,OUTPUT);
  pinMode(andar2Led,OUTPUT);
  pinMode(andar3Led,OUTPUT);
  
  }
  
  void loop()
  {
  digitalWrite(inicializacao, HIGH);
  
  Serial.print(digitalRead(sensor1)); Serial.print("__");
  Serial.print(digitalRead(sensor2)); Serial.print("__");
  Serial.print(digitalRead(sensor3)); Serial.print("  ");
  
  Serial.print(digitalRead(andar1)); Serial.print("__");
  Serial.print(digitalRead(andar2)); Serial.print("__");
  Serial.print(digitalRead(andar3)); Serial.println("");
  
  if(digitalRead(andar1) == HIGH){
  while(digitalRead(sensor1) == HIGH){
    digitalWrite (subir, LOW);
    digitalWrite (descer, HIGH);

    digitalWrite (andar1Led, HIGH);
    digitalWrite (andar2Led, LOW);
    digitalWrite (andar3Led, LOW);
    
  }
  }
  if(digitalRead(andar3) == HIGH){
  while(digitalRead(sensor3) == HIGH){
    digitalWrite (subir, HIGH);
    digitalWrite (descer, LOW);
  
    digitalWrite (andar1Led, HIGH);
    digitalWrite (andar2Led, HIGH);
    digitalWrite (andar3Led, HIGH);
     }
  }
   if((digitalRead(sensor3) == LOW)&&(digitalRead(andar2) == HIGH)){
    while(digitalRead(sensor2) == HIGH){
      digitalWrite (subir, LOW);
      digitalWrite (descer, HIGH);
      
    digitalWrite (andar1Led, HIGH);
    digitalWrite (andar2Led, HIGH);
    digitalWrite (andar3Led, LOW);
    
    }
   }
  if((digitalRead(sensor1) == LOW)&&(digitalRead(andar2) == HIGH)){
    while(digitalRead(sensor2) == HIGH){
      digitalWrite (subir, HIGH);
      digitalWrite (descer, LOW);

    digitalWrite (andar1Led, HIGH);
    digitalWrite (andar2Led, HIGH);
    digitalWrite (andar3Led, LOW);
    
    
    }
   }
  digitalWrite (subir, LOW);
  digitalWrite (descer, LOW);
  }
