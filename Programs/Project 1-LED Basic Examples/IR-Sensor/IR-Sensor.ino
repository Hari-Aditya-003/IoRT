void setup () 
{
  pinMode(D5, OUTPUT);
  pinMode(D7, INPUT);
}
void loop ()
{
  if(digitalRead(D7)==1)
  {
     digitalWrite(D5, HIGH);
  }
else
{
  digitalWrite(D5, LOW);
}
  }
  
