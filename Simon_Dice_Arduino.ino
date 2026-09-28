/*
 * CIN-212 Hardware Digital - Tarea 1
 * Juego interactivo de secuencia y memoria audiovisual
 * Arduino UNO R3
 */

const byte NUM_ELEMENTOS = 3;
const byte MAX_NIVEL = 50;

const byte LEDS[NUM_ELEMENTOS] = {2, 3, 4};
const byte BOTONES[NUM_ELEMENTOS] = {5, 6, 7};
const byte BUZZER = 8;

const unsigned long DEBOUNCE_MS = 40;
const unsigned long TIEMPO_LED = 500;
const unsigned long PAUSA_SECUENCIA = 150;

byte secuencia[MAX_NIVEL];
byte nivel = 1;

void setup() {
  for (byte i = 0; i < NUM_ELEMENTOS; i++) {
    pinMode(LEDS[i], OUTPUT);
    digitalWrite(LEDS[i], LOW);

    pinMode(BOTONES[i], INPUT_PULLUP);
  }

  pinMode(BUZZER, OUTPUT);

  randomSeed(analogRead(A0));
}

void loop() {
  secuencia[nivel - 1] = random(0, NUM_ELEMENTOS);

  reproducirSecuencia();

  if (leerSecuenciaJugador()) {
    sonidoExito();
    nivel++;

    if (nivel > MAX_NIVEL) {
      nivel = 1;
      limpiarSecuencia();
      delay(1000);
    }

    delay(500);
  } else {
    gameOver();

    nivel = 1;
    limpiarSecuencia();

    delay(1000);
  }
}

void reproducirSecuencia() {
  delay(500);

  for (byte i = 0; i < nivel; i++) {
    byte elemento = secuencia[i];

    digitalWrite(LEDS[elemento], HIGH);
    tone(BUZZER, frecuenciaElemento(elemento));

    delay(TIEMPO_LED);

    digitalWrite(LEDS[elemento], LOW);
    noTone(BUZZER);

    delay(PAUSA_SECUENCIA);
  }
}

bool leerSecuenciaJugador() {
  for (byte posicion = 0; posicion < nivel; posicion++) {

    int boton = esperarBoton();

    if (boton < 0) {
      return false;
    }

    digitalWrite(LEDS[boton], HIGH);
    tone(BUZZER, frecuenciaElemento(boton));

    delay(150);

    digitalWrite(LEDS[boton], LOW);
    noTone(BUZZER);

    if (boton != secuencia[posicion]) {
      return false;
    }
  }

  return true;
}

int esperarBoton() {
  while (true) {

    for (byte i = 0; i < NUM_ELEMENTOS; i++) {

      if (digitalRead(BOTONES[i]) == LOW) {

        unsigned long inicio = millis();

        while (digitalRead(BOTONES[i]) == LOW) {

          if (millis() - inicio >= DEBOUNCE_MS) {

            if (digitalRead(BOTONES[i]) == LOW) {

              while (digitalRead(BOTONES[i]) == LOW) {
                delay(1);
              }

              return i;
            }
          }
        }
      }
    }
  }
}

void sonidoExito() {
  tone(BUZZER, 523);
  delay(120);

  tone(BUZZER, 659);
  delay(120);

  tone(BUZZER, 784);
  delay(180);

  noTone(BUZZER);
}

void gameOver() {
  tone(BUZZER, 180);

  for (byte repeticion = 0; repeticion < 3; repeticion++) {

    for (byte i = 0; i < NUM_ELEMENTOS; i++) {
      digitalWrite(LEDS[i], HIGH);
    }

    delay(200);

    apagarLEDs();

    delay(200);
  }

  noTone(BUZZER);
}

void apagarLEDs() {
  for (byte i = 0; i < NUM_ELEMENTOS; i++) {
    digitalWrite(LEDS[i], LOW);
  }
}

void limpiarSecuencia() {
  for (byte i = 0; i < MAX_NIVEL; i++) {
    secuencia[i] = 0;
  }
}

unsigned int frecuenciaElemento(byte elemento) {
  switch (elemento) {

    case 0:
      return 440;

    case 1:
      return 660;

    case 2:
      return 880;

    default:
      return 440;
  }
}
