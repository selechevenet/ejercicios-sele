int distancia = 0;

int promedio = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

int counter;

void setup()
{
  Serial.begin(9600);

}

void loop()
{
  promedio = 0;
  for (counter = 0; counter < 5; ++counter) {
    distancia = 0.01723 * readUltrasonicDistance(3, 3);
    promedio = (promedio + distancia);
    Serial.print("distancia = ");
    Serial.println(distancia);
  }
  promedio = (promedio / 5);
  Serial.print("el promedio es ");
  Serial.print(promedio);
  Serial.println(" cm");
  delay(10); 
}
