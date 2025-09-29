// Motor 1
int M1P1 = 27;
int M1P2 = 26;
int ENA  = 14;  // PWM

// Motor 2
int M2P1 = 25;
int M2P2 = 33;
int ENB  = 32;  // PWM

// Canais PWM
int canalENA = 0;
int canalENB = 1;

// Frequência e resolução do PWM
int freqPWM = 1000;   // 1 kHz
int resolucao = 8;    // 8 bits -> valores 0-255

void setup() {
  // Pinos de direção
  pinMode(M1P1, OUTPUT);
  pinMode(M1P2, OUTPUT);
  pinMode(M2P1, OUTPUT);
  pinMode(M2P2, OUTPUT);

  // Configuração PWM para ENA e ENB
  ledcSetup(canalENA, freqPWM, resolucao);
  ledcAttachPin(ENA, canalENA);

  ledcSetup(canalENB, freqPWM, resolucao);
  ledcAttachPin(ENB, canalENB);

  Para();
}

void loop() {
  // Anda para frente em velocidade média
  Anda(150, 150);   // valores 0 a 255
  delay(2000);

  // Para
  Para();
  delay(1000);

  // Anda para frente em velocidade máxima
  Anda(255, 255);
  delay(2000);

  // Para
  Para();
  delay(1000);
}

void Anda(int vel1, int vel2) {  
  // Motor 1 para frente
  digitalWrite(M1P1, HIGH);
  digitalWrite(M1P2, LOW);
  ledcWrite(canalENA, vel1);

  // Motor 2 para frente
  digitalWrite(M2P1, HIGH);
  digitalWrite(M2P2, LOW);
  ledcWrite(canalENB, vel2);
}

void Para() {  
  // Desliga motores
  ledcWrite(canalENA, 0);
  ledcWrite(canalENB, 0);

  digitalWrite(M1P1, LOW);
  digitalWrite(M1P2, LOW);
  digitalWrite(M2P1, LOW);
  digitalWrite(M2P2, LOW);
}