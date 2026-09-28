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

byte secuencia[MAX_NIVEL];
byte nivel = 1;

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

  // Inicialización de la semilla aleatoria
  randomSeed(analogRead(A0));
}

void loop() {
  // Agregar un nuevo elemento a la secuencia
  secuencia[nivel - 1] = random(0, NUM_ELEMENTOS);

  // Mostrar el nuevo elemento mediante el LED correspondiente
  byte elemento = secuencia[nivel - 1];

  digitalWrite(LEDS[elemento], HIGH);
  delay(500);
  digitalWrite(LEDS[elemento], LOW);

  // Por ahora esperamos antes de comenzar el siguiente nivel
  delay(1000);

  nivel++;

  // Reiniciar después del nivel máximo
  if (nivel > MAX_NIVEL) {
    nivel = 1;
  }
}
