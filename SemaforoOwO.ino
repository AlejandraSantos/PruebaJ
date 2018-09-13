int ledDelay=2000;
int CarRojo = 13;
int CarAmarillo = 12;
int CarVerde = 11;
int PeaRojo = 10;
int PeaVerde = 9;
int Boton = 2;
int TiempoParaCruzar = 5000;
int valor = analogRead(A0);
int tiempo = map(valor,0, 1023, 10, 60)*1000;
unsigned long changeTime;

void setup(){
Serial.begin(9600);
int i,j;  
for(i=9;i<14;i++){
  pinMode(i,OUTPUT);
  digitalWrite(i,LOW);
}

for(i=9;i<14;i++){
  digitalWrite(i,HIGH);  
  delay(ledDelay/3);
}

for(i=9;i<14;i++){
  digitalWrite(i,LOW);
  delay(ledDelay/3);
}
}

void RutinaDeLuces(){
int estado=0;  
for(estado=1;estado<4;estado++){
  switch(estado){
    case(0):
    digitalWrite(CarRojo,LOW);
    digitalWrite(CarAmarillo,LOW);
    digitalWrite(CarVerde,LOW);
    digitalWrite(PeaRojo,LOW);
    digitalWrite(PeaVerde,HIGH);
    break;
    case(1):
    digitalWrite(CarRojo,HIGH);
    digitalWrite(CarAmarillo,LOW);
    digitalWrite(CarVerde,LOW);
    digitalWrite(PeaRojo,LOW);
    digitalWrite(PeaVerde,HIGH);
    break;
    case(2):
    digitalWrite(CarRojo,LOW);
    digitalWrite(CarAmarillo,HIGH);
    digitalWrite(CarVerde,LOW);
    digitalWrite(PeaRojo,HIGH);
    digitalWrite(PeaVerde,LOW);
    break;

    case(3):
    digitalWrite(CarRojo,LOW);
    digitalWrite(CarAmarillo,LOW);
    digitalWrite(CarVerde,HIGH);
    digitalWrite(PeaRojo,HIGH);
    digitalWrite(PeaVerde,LOW);
    break;
  }
delay(ledDelay);
digitalWrite(CarRojo,LOW);
digitalWrite(CarAmarillo,LOW);
digitalWrite(CarVerde,LOW);
digitalWrite(PeaRojo,LOW);
digitalWrite(PeaVerde,HIGH);
}}
void PasoDePeatones(){
  int estado=0;
  Serial.println("paso de peatones");
  for(estado=1;estado<3;estado++){
    switch(estado){
      case(1):
      digitalWrite(CarRojo,LOW);
      digitalWrite(CarAmarillo,HIGH);
      digitalWrite(CarVerde,LOW);
      digitalWrite(PeaRojo,HIGH);
      digitalWrite(PeaVerde,LOW);
      break;
      case(2):
      digitalWrite(CarRojo,HIGH);
      digitalWrite(CarAmarillo,LOW);
      digitalWrite(CarVerde,LOW);
      digitalWrite(PeaRojo,LOW);
      digitalWrite(PeaVerde,LOW);
      break;
    }
    delay(ledDelay);
    digitalWrite(CarRojo,LOW);
    digitalWrite(CarAmarillo,LOW);
    digitalWrite(CarVerde,LOW);
    digitalWrite(PeaRojo,LOW);
    digitalWrite(PeaVerde,HIGH);
  }
 }
  void loop(){  
    int EstadoBoton=digitalRead(Boton);
    if(EstadoBoton==HIGH&&(millis()-changeTime)>1250){
      PasoDePeatones();
    }
    else{
      RutinaDeLuces();
    }
  }
