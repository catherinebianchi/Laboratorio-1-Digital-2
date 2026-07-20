//************************************************************/
//Universidad del Valle de Guatemala
//BE3029 - Electrónica Digital 2
//Catherine Bianchi 24080
//Laboratorio #1
//************************************************************/

//************************************************************/
//Librerías
//************************************************************/
#include <Arduino.h>
#include <stdint.h>
#include <stdio.h>
#include <driver/gpio.h>


//************************************************************/
//Definiciones
//************************************************************/
#define led1 23
#define led2 1
#define led3 22
#define led4 3

#define botonsuma 39
#define botonresta 36

//************************************************************/
//Variables
//************************************************************/
uint8_t contador = 0;
uint8_t Salidamas = 0;
uint8_t Salidamenos = 0;


void setup() {
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);

pinMode(botonsuma, INPUT);
pinMode(botonresta, INPUT);
}

void loop() {
//Apagar todos los LEDs
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);


uint8_t estado = digitalRead(botonsuma);
uint8_t estado2 = digitalRead(botonresta);

//************************************************************/
//Contador Binario
//************************************************************/
if (estado==HIGH){
  Salidamas = 1;
}

if ((Salidamas==1)&&(estado==LOW)){
  delay(15);
  contador = contador + 1;
  if (contador>15){
    contador = 0;
  }
  Salidamas = 0;
}

if (estado2==HIGH){
  Salidamenos = 1;
}

if ((Salidamenos==1)&&(estado2==LOW)){
  delay(15);
  contador = contador - 1;
  if (contador<0){
    contador = 15;
  }
  Salidamenos=0;
}

switch(contador){
  case 0: digitalWrite(led1,LOW); digitalWrite(led2,LOW); digitalWrite(led3,LOW); digitalWrite(led4,LOW); break;
  case 1: digitalWrite(led1,HIGH); digitalWrite(led2,LOW); digitalWrite(led3,LOW); digitalWrite(led4,LOW); break;
  case 2: digitalWrite(led1,LOW); digitalWrite(led2,HIGH); digitalWrite(led3,LOW); digitalWrite(led4,LOW); break;
  case 3: digitalWrite(led1,HIGH); digitalWrite(led2,HIGH); digitalWrite(led3,LOW); digitalWrite(led4,LOW); break;
  case 4: digitalWrite(led1,LOW); digitalWrite(led2,LOW); digitalWrite(led3,HIGH); digitalWrite(led4,LOW); break;
  case 5: digitalWrite(led1,HIGH); digitalWrite(led2,LOW); digitalWrite(led3,HIGH); digitalWrite(led4,LOW); break;
  case 6: digitalWrite(led1,LOW); digitalWrite(led2,HIGH); digitalWrite(led3,HIGH); digitalWrite(led4,LOW); break;
  case 7: digitalWrite(led1,HIGH); digitalWrite(led2,HIGH); digitalWrite(led3,HIGH); digitalWrite(led4,LOW); break;
  case 8: digitalWrite(led1,LOW); digitalWrite(led2,LOW); digitalWrite(led3,LOW); digitalWrite(led4,HIGH); break;
  case 9: digitalWrite(led1,HIGH); digitalWrite(led2,LOW); digitalWrite(led3,LOW); digitalWrite(led4,HIGH); break;
  case 10: digitalWrite(led1,LOW); digitalWrite(led2,HIGH); digitalWrite(led3,LOW); digitalWrite(led4,HIGH); break;
  case 11: digitalWrite(led1,HIGH); digitalWrite(led2,HIGH); digitalWrite(led3,LOW); digitalWrite(led4,HIGH); break;
  case 12: digitalWrite(led1,LOW); digitalWrite(led2,LOW); digitalWrite(led3,HIGH); digitalWrite(led4,HIGH); break;
  case 13: digitalWrite(led1,HIGH); digitalWrite(led2,LOW); digitalWrite(led3,HIGH); digitalWrite(led4,HIGH); break;
  case 14: digitalWrite(led1,LOW); digitalWrite(led2,HIGH); digitalWrite(led3,HIGH); digitalWrite(led4,HIGH); break;
  case 15: digitalWrite(led1,HIGH); digitalWrite(led2,HIGH); digitalWrite(led3,HIGH); digitalWrite(led4,HIGH); break;
}



}
