#include "coche.h"

float dis;
int numero=0; 

Coche cupra(5, 6, 8, 9, 10, 11, 4, 3);

void setup() {
  Serial.begin(9600);
}
void loop() {
  cupra.delante();
  dis = cupra.calcularDistancia();
  if(dis<15){ 
    cupra.atras(); 
    cupra.intermitenteAtras();
    cupra.parar(); 
    delay(250);
    numero = random(0,2); 
    if(numero==0){ 
      cupra.derecha();
      cupra.intermitenteDerecha();
      cupra.parar(); 
      delay(250);
    }
    if(numero==1){ 
      cupra.izquierda();
      cupra.intermitenteIzquierda();
      cupra.parar();
      delay(250);
    }
  }
}


