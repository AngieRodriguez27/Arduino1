//UN RESTAURANTE QUIERE PREMIAR A SUS CLIENTES ASI QUE CUANDO INGRESE EL CLIENTE NUMERO 5 EL RESTAURANTE LE REGALARA TODO LO QUE CONSUMAN

const int Trig = PA10;  
const int Echo = PA8;   
const int led = PB11;  
const int zumbador = PA7;
  long tiempo; 
  long distance; 
   int contador=0;
   int acumulador=0;
   int tono = 540;

void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT); 
  pinMode(Echo, INPUT);  
  digitalWrite(Trig, LOW);
  pinMode(led, OUTPUT);  
  pinMode(zumbador, OUTPUT);
}
void loop()
{
  digitalWrite(Trig, HIGH);
  delayMicroseconds(20);          
  digitalWrite(Trig, LOW);
  
  tiempo = pulseIn(Echo, HIGH); 
  distancia = tiempo / 59;           
  
  an();

  
}

void an(){
 
  if(distancia > 0 && distancia < 50)
  {
    contador = contador + 1;
    if(contador == 5){
    Serial.print("Eres el ganador!!! ")
    }
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(zumbador, HIGH);
    tone(zumbador, tono);
    delay(500);
    noTone(zumbador);
    digitalWrite(led, LOW);
    digitalWrite(zumbador, LOW);
    Serial.println();
    Serial.print("Registro una persona.");
  
  
  }
  else{
    Serial.println();
    Serial.print("Espera un momento.");

  }
  
  
}
