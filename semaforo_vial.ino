/*
 * ============================================
 * EJERCICIO EN CLASE - PUNTO 3
 * Semáforo Vial con Tiempos
 * ============================================
 * Plataforma : Arduino UNO
 * Simulador  : Tinkercad
 * Fecha      : 29/03/2026
 *
 * Conexiones:
 *   - LED Verde   → Pin D2
 *   - LED Amarillo → Pin D3
 *   - LED Rojo    → Pin D4
 *   (Cada LED con resistencia de 150Ω a GND)
 *
 * Secuencia: Verde (5s) → Amarillo (2s) → Rojo (5s)
 * ============================================
 */

// Pines de los LEDs
const int ledVerde    = 2;
const int ledAmarillo = 3;
const int ledRojo     = 4;

// Tiempos de cada fase (en milisegundos)
const unsigned long tiempoVerde    = 5000; // 5 segundos
const unsigned long tiempoAmarillo = 2000; // 2 segundos
const unsigned long tiempoRojo     = 5000; // 5 segundos

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);

  Serial.begin(9600);
  Serial.println("=========================================");
  Serial.println("        SEMAFORO VIAL INICIADO");
  Serial.println("=========================================");
  Serial.println("Verde: 5s | Amarillo: 2s | Rojo: 5s");
  Serial.println("-----------------------------------------");
}

void loop() {
  // ── FASE 1: VERDE ── El tráfico avanza
  Serial.println("🟢 Estado: VERDE  → Avanzar");
  digitalWrite(ledVerde,    HIGH);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledRojo,     LOW);
  delay(tiempoVerde);

  // ── FASE 2: AMARILLO ── Precaución, prepararse para detenerse
  Serial.println("🟡 Estado: AMARILLO → Precaución");
  digitalWrite(ledVerde,    LOW);
  digitalWrite(ledAmarillo, HIGH);
  digitalWrite(ledRojo,     LOW);
  delay(tiempoAmarillo);

  // ── FASE 3: ROJO ── El tráfico se detiene
  Serial.println("🔴 Estado: ROJO   → Detener");
  digitalWrite(ledVerde,    LOW);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledRojo,     HIGH);
  delay(tiempoRojo);

  // La secuencia se repite automáticamente al volver al inicio del loop()
}
