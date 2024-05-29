// RGB LED pinleri
int led1_r = 3;
int led1_g = 5;
int led1_b = 6;
int led2_r = 9;
int led2_g = 10;
int led2_b = 11;
int led3_r = 13;
int led3_g = A1;
int led3_b = A2;

// Potansiyometre pini
int potPin = A0;

void setup() {
  // LED pinlerini çıkış olarak ayarla
  pinMode(led1_r, OUTPUT);
  pinMode(led1_g, OUTPUT);
  pinMode(led1_b, OUTPUT);
  pinMode(led2_r, OUTPUT);
  pinMode(led2_g, OUTPUT);
  pinMode(led2_b, OUTPUT);
  pinMode(led3_r, OUTPUT);
  pinMode(led3_g, OUTPUT);
  pinMode(led3_b, OUTPUT);

  // Potansiyometre pinini giriş olarak ayarla
  pinMode(potPin, INPUT);
}

void loop() {
  // Potansiyometreden değeri oku (0 - 1023 arası değer)
  int potValue = analogRead(potPin);

  // Potansiyometre değerini 0 - 255 aralığına ölçekle
  int brightness = map(potValue, 0, 1023, 0, 255);

  // RGB LED 1: Kırmızı (parlaklık potansiyometreden kontrol ediliyor)
  analogWrite(led1_r, brightness);
  analogWrite(led1_g, 0);
  analogWrite(led1_b, 0);

  // RGB LED 2: Yeşil (parlaklık potansiyometreden kontrol ediliyor)
  analogWrite(led2_r, 0);
  analogWrite(led2_g, brightness);
  analogWrite(led2_b, 0);

  // RGB LED 3: Mavi (parlaklık potansiyometreden kontrol ediliyor)
  analogWrite(led3_r, 0);
  analogWrite(led3_g, 0);
  analogWrite(led3_b, brightness);

  delay(50); // Kısa bir bekleme süresi
}
