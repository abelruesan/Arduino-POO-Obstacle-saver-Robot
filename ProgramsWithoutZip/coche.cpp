#include "coche.h"

Coche::Coche(int _led1, int _led2, int _motor1_atras, int _motor1_delante, int _motor2_atras, int _motor2_delante, int _trig, int _eco){
    this->led1 = _led1;
    this->led2 = _led2;
    this->motor1_atras = _motor1_atras;
    this->motor1_delante = _motor1_delante;
    this->motor2_atras = _motor2_atras;
    this->motor2_delante = _motor2_delante;
    this->trig = _trig;
    this->eco = _eco;
    init();
}

Coche::init(){
    pinMode(trig, OUTPUT);
    pinMode(eco, INPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    randomSeed(analogRead(A0));
}

void Coche::delante(){ 
    digitalWrite(led1, HIGH); 
    digitalWrite(led2, HIGH);
    digitalWrite(motor1_delante, HIGH);
    digitalWrite(motor1_atras, LOW);
    digitalWrite(motor2_delante, HIGH);
    digitalWrite(motor2_atras, LOW);
}

void Coche::atras(){ 
    digitalWrite(motor1_delante, LOW);
    digitalWrite(motor1_atras, HIGH);
    digitalWrite(motor2_delante, LOW);
    digitalWrite(motor2_atras, HIGH);
}

void Coche::izquierda(){ 
    digitalWrite(motor1_delante, HIGH);
    digitalWrite(motor1_atras, LOW);
    digitalWrite(motor2_delante, LOW);
    digitalWrite(motor2_atras, HIGH);
}

void Coche::derecha(){ 
    digitalWrite(motor1_delante, LOW);
    digitalWrite(motor1_atras, HIGH);
    digitalWrite(motor2_delante, HIGH);
    digitalWrite(motor2_atras, LOW);
}

void Coche::parar(){ 
    digitalWrite(motor1_delante, LOW);
    digitalWrite(motor1_atras, LOW);
    digitalWrite(motor2_delante, LOW);
    digitalWrite(motor2_atras, LOW);
}

float Coche::calcularDistancia(){
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    long tiempo = (pulseIn(eco, HIGH)/2);
    float distancia = float(tiempo*0.0343); 
    return distancia;
}

void Coche::intermitenteAtras(){
    for(int i=0; i<8; i++){ 
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    delay(150);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    delay(150);
    }
}

void Coche::intermitenteDerecha(){
    for(int i=0; i<6; i++){ 
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    delay(150);
    digitalWrite(led1, HIGH);
    delay(150);
    }
}

void Coche::intermitenteIzquierda(){
    for(int i=0; i<6; i++){ 
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    delay(150);
    digitalWrite(led2, HIGH);
    delay(150);
    }
}
