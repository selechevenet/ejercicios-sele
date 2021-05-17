int promedio = 0;

int distancia = 0;

int temperatura = 0;

int promedio2 = 0;

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
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop()
{
  promedio = 0;
  promedio2 = 0;
  for (counter = 0; counter < 5; ++counter) {
    distancia = 0.01723 * readUltrasonicDistance(7, 7);
    temperatura = -40 + 0.488155 * (analogRead(A0) - 20);
    promedio = (promedio + distancia);
    promedio2 = (promedio2 + temperatura);
    Serial.print("distancia = ");
    Serial.print(distancia);
    Serial.print(", temperatura = ");
    Serial.println(temperatura);
  }
  promedio = (promedio / 5);
  promedio2 = (promedio2 / 5);
  Serial.print("La temperatura promedio es  ");
  Serial.print(promedio2);
  Serial.print(" y la distancia promedio es ");
  Serial.print(promedio);
  Serial.println(" cm");
  delay(10); 
}
