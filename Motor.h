class MotorEsp {
  private:
  
    int velPIN;
    int in1;
    int in2;
    int canalPWM;  

    void setVelocidade(int vel) {
      ledcWrite(velPIN, vel);   
    }

  public:
    MotorEsp(int PWMPin, int input1, int input2, int canal) {
      velPIN = PWMPin;
      in1 = input1;
      in2 = input2;
      canalPWM = canal;

      // Configuração dos pinos de direção
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);

      ledcAttachChannel(velPIN, 1000, 8, canalPWM);
    }

    void frente(int vel) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      setVelocidade(vel);
    }

    void atras(int vel) {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      setVelocidade(vel);
    }

    void desliga() {
      ledcWrite(velPIN, 0);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
    }
};
