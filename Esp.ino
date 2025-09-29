#include "Motor.h"

static unsigned long ultimoTempo = 0;

//Motor Direito

#define ENA 14 //azul
#define in1M1 27 //verde
#define in2M1 26 //amarelo

#define enco1Pin 35 //laranja

volatile long contadorM1 = 0;
int velocidadeM1 = 150;

MotorEsp* M1 = new MotorEsp(ENA, in1M1, in2M1, 0);


//Motor Esquerdo


#define ENB 32 //azul
#define in3M2 25 //verde
#define in4M2 33 //amarelo

#define enco2Pin 34 //laranja

volatile long contadorM2 = 0;
int velocidadeM2 = 150;

MotorEsp* M2 = new MotorEsp(ENB, in3M2, in4M2, 1); 

void IRAM_ATTR contarM1() {
  contadorM1 += 1;
}

void IRAM_ATTR contarM2() {
  contadorM2 += 1;
}




void setup() {

  Serial.begin(9600);
  /*
  
  pinMode(in1M1, OUTPUT);
  pinMode(in2M1, OUTPUT);
  pinMode(in3M2, OUTPUT);
  pinMode(in4M2, OUTPUT);

  // Configura PWM direto nos pinos ENA e ENB

  ledcAttach(ENA, 1000, 8); 
  ledcAttach(ENB, 1000, 8);
  */
  //encoders

  
  pinMode(enco1Pin, INPUT_PULLUP);
  pinMode(enco2Pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(enco1Pin), contarM1, RISING);
  attachInterrupt(digitalPinToInterrupt(enco2Pin), contarM2, RISING);
  
}

void loop() {
  
  Serial.println(0);
  Serial.println(velocidadeM1);
  Serial.println(velocidadeM2);
  Serial.print("M1: ");
  Serial.print(contadorM1);
  Serial.print(" | M2: ");
  Serial.println(contadorM2);

  M1->frente(velocidadeM1);
  M2->frente(velocidadeM2);

  if (millis() - ultimoTempo > 500) { // compara a cada 0,5s
    int dif = contadorM1 - contadorM2;
    contadorM1 = 0;
    contadorM2 = 0;

    if (dif > 0) velocidadeM2 += 1;
    else if (dif < 0) velocidadeM2 -= 1;

    ultimoTempo = millis();
}
  
}


