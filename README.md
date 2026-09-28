# CIN-212 Tarea 1 — Simón Dice

## Descripción

Proyecto desarrollado para la asignatura **CIN-212 Hardware Digital**.

El proyecto consiste en implementar un juego de memoria tipo **“Simón Dice”** utilizando un **Arduino UNO R3**, tres LEDs, tres botones y un buzzer.

El jugador debe repetir correctamente la secuencia de luces y sonidos mostrada por el Arduino. A medida que avanza de nivel, la secuencia aumenta.

## Componentes

* Arduino UNO R3
* 3 LEDs
* 3 resistencias de 220 Ω
* 3 botones
* 1 buzzer
* Protoboard
* Cables de conexión

## Conexiones

| Componente | Pin Arduino |
| ---------- | ----------- |
| LED 1      | D2          |
| LED 2      | D3          |
| LED 3      | D4          |
| Botón 1    | D5          |
| Botón 2    | D6          |
| Botón 3    | D7          |
| Buzzer     | D8          |

Los botones utilizan la configuración `INPUT_PULLUP`.

## Estructura del proyecto

* `Simon_Dice_Arduino.ino` — Código principal del juego.
* `esquematico.png` — Esquema de conexiones del circuito.
* `README.md` — Documentación inicial del proyecto.

## Objetivo

Implementar un juego funcional de secuencia y memoria utilizando entradas y salidas digitales del Arduino UNO R3.

## Autor

**Damián San Martín**

## Estado del proyecto

Versión inicial del proyecto. Se continuará desarrollando y documentando mediante commits progresivos.

