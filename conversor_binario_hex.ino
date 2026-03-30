/*
 * ============================================
 * EJERCICIO EN CLASE - PUNTO 2
 * Conversor Binario (4 bits) a Hexadecimal
 * ============================================
 * Plataforma : Arduino UNO
 * Simulador  : Tinkercad
 * Fecha      : 29/03/2026
 *
 * Conexiones:
 *   - DIP Switch → Pines A0 (bit0=1), A1 (bit1=2),
 *                        A2 (bit2=4), A3 (bit3=8)
 *   - Display 7 seg (cátodo común) → Pines D2–D8
 *     (segmentos a,b,c,d,e,f,g respectivamente)
 * ============================================
 */

// Pines de los segmentos del display (a → g)
const int segmentos[] = {2, 3, 4, 5, 6, 7, 8};

// Pines del DIP Switch (entradas binarias)
const int switchPins[] = {A0, A1, A2, A3};

// Matriz cátodo común: 1=encendido, 0=apagado
// Orden de segmentos: a, b, c, d, e, f, g
const byte digitosHex[16][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
  {1, 1, 1, 0, 1, 1, 1}, // A
  {0, 0, 1, 1, 1, 1, 1}, // b
  {1, 0, 0, 1, 1, 1, 0}, // C
  {0, 1, 1, 1, 1, 0, 1}, // d
  {1, 0, 0, 1, 1, 1, 1}, // E
  {1, 0, 0, 0, 1, 1, 1}  // F
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(switchPins[i], INPUT);
  }
}

void loop() {
  // Leer los 4 bits del DIP Switch y calcular valor decimal
  int valorDecimal = 0;
  if (digitalRead(A0) == HIGH) valorDecimal += 1;
  if (digitalRead(A1) == HIGH) valorDecimal += 2;
  if (digitalRead(A2) == HIGH) valorDecimal += 4;
  if (digitalRead(A3) == HIGH) valorDecimal += 8;

  // Mostrar el valor en el display como hexadecimal
  escribirDisplay(valorDecimal);

  delay(150);
}

// Función que activa los segmentos según el índice (0–15)
void escribirDisplay(int index) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentos[i], digitosHex[index][i]);
  }
}
