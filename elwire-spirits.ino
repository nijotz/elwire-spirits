bool status = true;
bool noise = 0.0;
double noise_cycle = 30000.0; // milliseconds

double level_min[] = {
  0,     // blank
  0,     // blank
  0.00,  // channel 1
  0.05,  // channel 2
  0.00,  // channel 3
  0.05,  // channel 4
  0.00,  // channel 5
  0.00,  // channel 6
  0.05,  // channel 7
};

void setup() {
  pinMode(2, OUTPUT);  // channel A
  pinMode(3, OUTPUT);  // channel B
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D
  pinMode(6, OUTPUT);  // channel E
  pinMode(7, OUTPUT);  // channel F
  pinMode(8, OUTPUT);  // channel G
  pinMode(9, OUTPUT);  // channel H

  // We also have two status LEDs, pin 10 on the Escudo,
  // and pin 13 on the Arduino itself
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  for (int i=2; i<=6; i++) {
    double millis_into_cycle = millis() % (int)noise_cycle;
    double percent_of_cycle = millis_into_cycle / (long)noise_cycle;
    double angle_of_cycle = percent_of_cycle * 2 * M_PI;
    angle_of_cycle += (3.0f * M_PI_4);
    double target = sin(angle_of_cycle);
    target = (target + 1.0f) / 2.0f;

    double level = random(target * 500, target * 1000) / 1000.0f;

    // Serial.print("target: ");
    // Serial.print(target);
    // Serial.print("\n");

    // Serial.print("percent_of_cycle: ");
    // Serial.print(percent_of_cycle);
    // Serial.print("\n");

    // Serial.print("level: ");
    // Serial.print(level);
    // Serial.print("\n");

    if (true) {//level > level_min[i]) {
      digitalWrite(i, HIGH);
    } else {
      digitalWrite(i, LOW);
    }

    delay(25);
  }

  // blink both status LEDs
  digitalWrite(10, status);
  digitalWrite(13, status);
  status = !status;
}
