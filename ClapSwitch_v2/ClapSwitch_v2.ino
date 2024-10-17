#define NEED_CLAPS 3
#define CLAP_RANGE 1000
#define RELAY_PIN 2
#define SOUND_PIN 3

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SOUND_PIN, INPUT);
}

uint8_t count = 0;
unsigned long lastClapMillis = 0;

void loop() {
  if (millis() - lastClapMillis > CLAP_RANGE) {
    count = 0;
  }

  if (digitalRead(SOUND_PIN)) {
    count += 1;
    if (count >= NEED_CLAPS) {
      digitalWrite(RELAY_PIN, !digitalRead(RELAY_PIN));
      count = 0;
    }
    lastClapMillis = millis();
    delay(250);
  }
}
