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
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trig, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trig, LOW);//Inicializamos el pin con 0
  pinMode(led, OUTPUT);  //pin como entrada
  pinMode(zumbador, OUTPUT);
}
void loop()
{
  digitalWrite(Trig, HIGH);
  delayMicroseconds(20);          //Enviamos un pulso de 10us
  digitalWrite(Trig, LOW);
  
  tiempo = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  distancia = tiempo / 59;             //escalamos el tiempo a una distancia en cm
  
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
