class UltraSonico{

  private:

    int trig;
    int echo;
    long duracao;
    float distancia;

    void limpa(){

      digitalWrite(trig, LOW);
      delayMicroseconds(2);

    }

  public:
    UltraSonico(int tri, int ech){

      trig = tri;
      echo = ech;

      pinMode(trig, OUTPUT);
      pinMode(echo, INPUT);

    }

    float pulso(){

      limpa();

      digitalWrite(trig, HIGH);
      delay(1);
      digitalWrite(trig, LOW);
      digitalWrite(echo, HIGH);

      duracao = (pulseIn(echo, HIGH))/58.2;
      distancia = duracao;// * 0.0343 / 2;
      delay(50);

      return distancia;

    }
    






};
