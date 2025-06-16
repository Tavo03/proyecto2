#include melodia.h

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