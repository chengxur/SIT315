// github code  https://github.com/chengxur/SIT315
const int SENSOR_PIN = A0;
const int RED_LED_PIN = 2;
const int YELLO_LED_PIN = 5;
const int DELAY = 1000;


void setup()
{
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLO_LED_PIN, OUTPUT);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(YELLO_LED_PIN, LOW);
  Serial.begin(9600);
}

void loop()
{
  int temperature = analogRead(SENSOR_PIN);
  Serial.print("\n temperature value: ");
  Serial.print(temperature);
  
  if (temperature > 200) {
    blink(RED_LED_PIN);
  } else {
    digitalWrite(RED_LED_PIN, LOW);

    if (temperature > 50 and temperature < 150) {
      blink(YELLO_LED_PIN);
    } else {
      digitalWrite(YELLO_LED_PIN, LOW);
    }
  }
}

void blink(int LED) {
  digitalWrite(LED, HIGH);
  delay(DELAY);
  digitalWrite(LED, LOW);
  delay(DELAY);
}