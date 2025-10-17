#include "Motor.h"
#include "UltraSonico.h"

static unsigned long ultimoTempo = 0;

//UltraSonicos

#define TRIG 5
#define ECHO1 18
#define ECHO2 19
#define ECHO3 21

UltraSonico* SensorE = new UltraSonico(TRIG, ECHO1);
UltraSonico* SensorM = new UltraSonico(TRIG, ECHO2);
UltraSonico* SensorD = new UltraSonico(TRIG, ECHO3);



//Sensor de Linha

#define SENSOR_ESQUERDO 22 // branco
#define SENSOR_DIREITO 23 // branco

//Motor Direito

#define ENA 14 //azul
#define IN1M1 27 //verde
#define IN2M1 26 //amarelo

#define ENCO1 35 //laranja

volatile long contadorM1 = 0;
int velocidadeM1 = 150;

MotorEsp* M1 = new MotorEsp(ENA, IN1M1, IN2M1, 0);


//Motor Esquerdo


#define ENB 32 //azul
#define IN3M2 25 //verde
#define IN4M2 33 //amarelo

#define ENCO2 34 //laranja

volatile long contadorM2 = 0;
int velocidadeM2 = 150;

MotorEsp* M2 = new MotorEsp(ENB, IN3M2, IN4M2, 1); 

void IRAM_ATTR contarM1() {
  contadorM1 += 1;
}

void IRAM_ATTR contarM2() {
  contadorM2 += 1;
}

int velocidade = 130;

void reto(){

  M1->frente(velocidade);
  M2->frente(velocidade);

}

void esquerda(){

  M1->frente(velocidade);
  M2->desliga();

}

void direita(){

  M2->frente(velocidade);
  M1->desliga();
  
}

void para(){

  M1->desliga();
  M2->desliga();

}

void segueLinha(){

  bool linhaEsquerda = !digitalRead(SENSOR_ESQUERDO);
  bool linhaDireita = !digitalRead(SENSOR_DIREITO);

  if (linhaEsquerda && linhaDireita) {

    reto();

  } 

  else if (linhaEsquerda && !linhaDireita) {

    esquerda();

  } 

  else if (!linhaEsquerda && linhaDireita) {

    direita();

  } 

  else {

    para();

  }

}




void setup() {

  Serial.begin(115200);

  //Sendor de Linha
  pinMode(SENSOR_ESQUERDO, INPUT);
  pinMode(SENSOR_DIREITO, INPUT);

  //Encoaders
  pinMode(ENCO1, INPUT_PULLUP);
  pinMode(ENCO2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENCO1), contarM1, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCO2), contarM2, RISING);
  
}

void loop() {


  float dist1 = SensorM->pulso();
  float dist2 = SensorE->pulso();
  float dist3 = SensorD->pulso();
  
  if(dist1 <= 13 && dist1 != 0){

    Serial.println(1);
    Serial.println(dist1);

  }
  if(dist2 <= 13 && dist2 != 0){

    Serial.println(2);
    Serial.println(dist2);
    
  }
  if(dist3 <= 13 && dist322 != 0){

    Serial.println(3);
    Serial.println(dist3);
    
  }
  
  
}


