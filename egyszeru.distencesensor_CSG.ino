// Pin definiálás
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  // Kezdeti beállítások
  Serial.begin(9600); // Soros monitor elindítása
  pinMode(trigPin, OUTPUT); // Trig pin kimenet
  pinMode(echoPin, INPUT);  // Echo pin bemenet
}

void loop() {
  // Ultrahang impulzus küldése
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Visszajövő impulzus mérése
  long duration = pulseIn(echoPin, HIGH);

  // Távolság kiszámítása (sebesség=343 m/s)
  long distance = (duration / 2) * 0.0344; // A durációt elosztjuk kettővel, mert oda-vissza mérjük.

  // Eredmény kiírása
  Serial.print("Távolság: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Frissítés fél másodpercenként
}
