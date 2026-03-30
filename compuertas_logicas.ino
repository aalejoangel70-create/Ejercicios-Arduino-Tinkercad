/*
 * ============================================
 * EJERCICIO EN CLASE - PUNTO 1
 * Simulación de Compuertas Lógicas (AND, NOT, OR)
 * ============================================
 * Plataforma : Arduino UNO
 * Simulador  : Tinkercad
 * Fecha      : 29/03/2026
 * 
 * Conexiones:
 *   - DIP Switch 1 → Pin A0 (Entrada A)
 *   - DIP Switch 2 → Pin A1 (Entrada B)
 *   - Chips: 74HC04 (NOT), 74HC08 (AND), 74HC32 (OR)
 * ============================================
 */

const int pinEntradaA = A0; // Conectado al DIP Switch 1
const int pinEntradaB = A1; // Conectado al DIP Switch 2

void setup() {
  pinMode(pinEntradaA, INPUT);
  pinMode(pinEntradaB, INPUT);

  Serial.begin(9600);
  Serial.println("=========================================");
  Serial.println("   SIMULACION DE COMPUERTAS LOGICAS");
  Serial.println("=========================================");
  Serial.println("Entradas: A=A0, B=A1");
  Serial.println("-----------------------------------------");
}

void loop() {
  int A = digitalRead(pinEntradaA);
  int B = digitalRead(pinEntradaB);

  Serial.print("A="); Serial.print(A);
  Serial.print(" | B="); Serial.print(B);
  Serial.print(" || NOT A="); Serial.print(!A);
  Serial.print(" | AND="); Serial.print(A && B);
  Serial.print(" | OR="); Serial.println(A || B);

  delay(250);
}
