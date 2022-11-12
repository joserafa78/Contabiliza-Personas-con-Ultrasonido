/*Contador de Personas usando Sensor Ultrasonico con Arduino.*/
int TRIG=10;
int ECO=9;
int LED_AMARILLO=3;
int LED_AZUL=4;
int LED_ROJO=5;
int BUCER=7;
int DURACION;
int DISTANCIA;
int PERSONA=0;
int ZONA=LOW;
int CHEKEO=LOW;

void setup() {
  pinMode(TRIG,OUTPUT);
  pinMode(ECO,INPUT);
  pinMode(LED_AMARILLO,OUTPUT);
  pinMode(LED_AZUL,OUTPUT);
  pinMode(LED_ROJO,OUTPUT);
  pinMode(BUCER,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG,HIGH);
  delay(1);
  digitalWrite(TRIG,LOW);
  DURACION = pulseIn(ECO,HIGH);
  //Convierte duracion del teimpo en Distancia.
  DISTANCIA=DURACION/58.2;


  //Detecta si hay un objeto a menos de 20 centimetros
  if(DISTANCIA >=50 && DISTANCIA <150){//Rango de Distanci en Centimetros. AMARILLO
      digitalWrite(LED_AMARILLO,HIGH);
      digitalWrite(BUCER,HIGH);
      delay(DISTANCIA * 10);// Distancia proporcional a la Demora
      digitalWrite(LED_AMARILLO,LOW);
      digitalWrite(BUCER,LOW);
      //---------------CONTADOR DE INDIVIDUO-----------
      ZONA=HIGH;
            
  }else if (DISTANCIA >=10 && DISTANCIA <50 ){//Rango de Distanci en Centimetros. AZUL
      digitalWrite(LED_AZUL,HIGH);
      digitalWrite(BUCER,HIGH);
      delay(DISTANCIA * 10);// Distancia proporcional a la Demora
      digitalWrite(LED_AZUL,LOW);
      digitalWrite(BUCER,LOW);
  }else if (DISTANCIA >=0 && DISTANCIA <10 ){//Rango de Distanci en Centimetros. ROJO
      digitalWrite(LED_ROJO,HIGH);
      digitalWrite(BUCER,HIGH);
      delay(DISTANCIA * 10);// Distancia proporcional a la Demora
      digitalWrite(LED_ROJO,LOW);
      digitalWrite(BUCER,LOW);
  }else{
    ZONA=LOW;
    CHEKEO=LOW;
  }
//  -------EVALUA SI EL INDIVIDUO AUN ESTA EN LA ZONA-----
if(ZONA==HIGH && CHEKEO == LOW){
  PERSONA=PERSONA+1;
  CHEKEO=HIGH;
  Serial.print(PERSONA);//Imprime Valor y luego un Enter, Valor en Centimetros.
  Serial.println("- PERSONAS");//Imprime Valor y luego un Enter, Valor en Centimetros.
  delay(500);//Demora
}
      
}
