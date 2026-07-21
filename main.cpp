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
#define led1 18
#define led2 17
#define led3 16
#define led4 4

#define botonsuma 19
#define botonresta 22
#define botonmodo 23

//************************************************************/
//Variables
//************************************************************/
uint8_t contador = 0;
uint8_t Salidamas = 0;
uint8_t Salidamenos = 0;
uint8_t salida = 0;
uint8_t modo = 0;

//************************************************************/
//Prototipo de funciones
//************************************************************/
void apagar(void);

void setup() {
Serial.begin(115200);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);

pinMode(botonsuma, INPUT_PULLUP);
pinMode(botonresta, INPUT);
pinMode(botonmodo, INPUT);
}

void loop() {
//Apagar todos los LEDs
apagar();

//Lectura de botones
uint8_t estado = digitalRead(botonsuma);
uint8_t estado2 = digitalRead(botonresta);
uint8_t estado3 = digitalRead(botonmodo);

//************************************************************/
//Cambio de modo
//************************************************************/
if (estado3==LOW){
  salida = 1;
}
if((estado3==HIGH)&&(salida==1)){
  delay(15);
  modo=modo+1;
  if(modo>2){
    modo=0;
  }
  salida=0;
  contador = 0;
}

//Modo 0
if(modo==0){
  apagar();
}

//************************************************************/
//Contador de Décadas
//************************************************************/
if(modo==1){
  if (estado==LOW){
    Salidamas = 1;
  }
  if ((Salidamas==1)&&(estado==HIGH)){
    delay(15);
    contador = contador + 1;
    if (contador>4){
      contador = 1;
    }
    Salidamas = 0;
  }
  if (estado2==HIGH){
    Salidamenos = 1;
  }
  if ((Salidamenos==1)&&(estado2==LOW)){
    delay(15);
    contador = contador - 1;
    if (contador==0){
      contador = 4;
    }
    Salidamenos=0;
  }
  switch(contador){
    case 0: digitalWrite(led1,LOW); digitalWrite(led2,LOW); digitalWrite(led3,LOW); digitalWrite(led4,LOW); break;
    case 1: digitalWrite(led1,HIGH); digitalWrite(led2,LOW); digitalWrite(led3,LOW); digitalWrite(led4,LOW); break;
    case 2: digitalWrite(led1,LOW); digitalWrite(led2,HIGH); digitalWrite(led3,LOW); digitalWrite(led4,LOW); break;
    case 3: digitalWrite(led1,LOW); digitalWrite(led2,LOW); digitalWrite(led3,HIGH); digitalWrite(led4,LOW); break;
    case 4: digitalWrite(led1,LOW); digitalWrite(led2,LOW); digitalWrite(led3,LOW); digitalWrite(led4,HIGH); break;
  }
}

//************************************************************/
//Contador Binario
//************************************************************/
if(modo == 2){
  if (estado==LOW){
    Salidamas = 1;
  }
  if ((Salidamas==1)&&(estado==HIGH)){
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
    if (contador==255){
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
Serial.print("suma: "); Serial.print(estado);
Serial.print(" | resta: "); Serial.print(estado2);
Serial.print(" | modo: "); Serial.print(estado3);
Serial.print(" | modo_actual: "); Serial.println(modo);

}

//************************************************************/
//Funciones
//************************************************************/
void apagar(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}
