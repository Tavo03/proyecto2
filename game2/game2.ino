//Minijuego 1 con pantalla LCD
#include <EEPROM.h>
#include <LiquidCrystal.h>//libreria de la pantalla
#include "melodia.h"

LiquidCrystal lcd(10, 8, 7, 6, 5, 4); //Configura los pines de salida para la lcd

//Definimos los nuebos caracteres
byte caracateres[8][8] = {{ B01110, B00100, B11111, B01110, B01010, B01010, B11111, B01010 },
                  { B01110, B00100, B11111, B01110, B11011, B00000, B11111, B11111 },
                  { B01110, B10101, B11111, B01110, B01010, B01010, B11111, B01010 },
                  { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 },
                  { B00000, B00000, B00000, B11111, B11111, B11111, B11111, B11111 },
                  { B00000, B11111, B11111, B11111, B11111, B11111, B11111, B11111 },
                  { B01110, B11111, B11111, B11111, B11111, B11111, B11111, B11111 }};

//definicion pin buzzer
const int buzz = 9;

//definicion boton
const int btn = 3;

// definicion de las variables del juego
int x=15;
int y=1;
int obstaculos=0;
int vel=100;
int puntaje=0;
int GameOver=3;
int moment = 0;
int maximoPuntaje = 0;

//definicion variables musica
int notaActual = 0;
unsigned long tiempoNotaAnterior = 0;
bool notaActiva = false;

void setup(){
  //lectura del maximo puntaje historico
  EEPROM.write(maximoPuntaje,0);
  //inicializamos la interrupción
  attachInterrupt(digitalPinToInterrupt(btn), incrementarContador, RISING);
  //inicializamos el lcd
  lcd.begin(16, 2);
  //Creamos los nuevos caracteres
  for(int i=0; i<8; i++){
    lcd.createChar(i,caracateres[i]);
  }
  //inicializamos el buzzer
  pinMode(buzz, OUTPUT);
  noTone(buzz);
}

void loop(){
  //reproducimos musica del juego
  reproducirMusica();
  //reproducimos el juego en el lcd
  actualizarJuego();
}

void actualizarJuego(){
  if (moment == 0){
    inicioJuego();
  } else if (moment == 1){
    juego();
  } else {
    finJuego();
  }
}

void reproducirMusica(){
  unsigned long ahora = millis();
  if (notaActual < numNotas) {
    if (notaActiva == false) {
      tone(buzz, melodia[notaActual][0]);
      tiempoNotaAnterior = ahora;
      notaActiva = true;
    }

    if (ahora - tiempoNotaAnterior >= melodia[notaActual][1]) {
      noTone(buzz);
      notaActual++;
      notaActiva = false;
    }
  } else {
    notaActual = 0;
  }
}

void inicioJuego(){

}

void juego(){

}

void finJuego(){

}

void incrementarContador() {
  moment++;
}