/*
 * CIN-212 Hardware Digital - Tarea 1
 * Juego interactivo de secuencia y memoria audiovisual
 * Arduino UNO R3
 */

const byte NUM_ELEMENTOS = 3;

const byte LEDS[NUM_ELEMENTOS] = {2, 3, 4};
const byte BOTONES[NUM_ELEMENTOS] = {5, 6, 7};
const byte BUZZER = 8;

void setup() {
  // Configuración de los LEDs
  for (byte i = 0; i < NUM_ELEMENTOS; i++) {
    pinMode(LEDS[i], OUTPUT);
    digitalWrite(LEDS[i], LOW);
  }

  // Configuración de los botones
  for (byte i = 0; i < NUM_ELEMENTOS; i++) {
    pinMode(BOTONES[i], INPUT_PULLUP);
  }

  // Configuración del buzzer
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // En este commit se prepara el hardware.
  // La lógica del juego se agregará en los siguientes commits.
}
