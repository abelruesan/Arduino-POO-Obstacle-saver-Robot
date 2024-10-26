#ifndef _COCHE_H
#define _COCHE_H

#include <Arduino.h>

class Coche{
  private:
    int led1;
    int led2;
    int motor1_atras;
    int motor1_delante;
    int motor2_atras;
    int motor2_delante;
    int trig;
    int eco;

  public:
    Coche(int _led1, int _led2, int _motor1_atras, int _motor1_delante, int _motor2_atras, int _motor2_delante, int _trig, int _eco);
    init();
    void delante();
    void atras();
    void izquierda();
    void derecha();
    void parar();
    float calcularDistancia();
    void intermitenteAtras();
    void intermitenteDerecha();
    void intermitenteIzquierda();
};

#endif