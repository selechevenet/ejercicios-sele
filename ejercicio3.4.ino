int variable = 0;

void setup()
{
  Serial.begin(9600);

}

void loop()
{
  variable = random(1, 360 + 1);
  Serial.println(variable);
  delay(20); 
}
