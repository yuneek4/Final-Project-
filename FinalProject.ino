

const int temperaturePin = 0;
const int GreenP2 = 6;
const int YellowP3 = 5; 
const int TransP4 = 4;
const int BlueP5 = 3; 
const int RedP6= 2; 


void setup()
{
  pinMode(GreenP2,OUTPUT);
  pinMode(YellowP3,OUTPUT);
  pinMode(TransP4,OUTPUT);
  pinMode(BlueP5,OUTPUT);
  pinMode(RedP6,OUTPUT);  
  Serial.begin(9600);
}


void loop()
{
 
  float voltage, degreesC, degreesF;

  voltage = getVoltage(temperaturePin);

  degreesC = (voltage - 0.5) * 100.0;

  degreesF = degreesC * (9.0/5.0) + 32.0;


  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);


delay(1000); 

if (degreesF < 65) 
{
  digitalWrite(TransP4,HIGH); 
  digitalWrite(YellowP3,HIGH);
}

else if (degreesF == 75) 
{
  digitalWrite(TransP4,LOW);
  digitalWrite(YellowP3,LOW);
  digitalWrite(GreenP2,HIGH);
}

else if (degreesF > 75)
{
  digitalWrite(GreenP2,LOW);
  digitalWrite(BlueP5,HIGH);
}

else if (degreesF < 85)
{
  digitalWrite(BlueP5,LOW);
  digitalWrite(RedP6, HIGH);
}

else
{
  digitalWrite(RedP6,LOW);
}
}


float getVoltage(int pin)
{


  return (analogRead(pin) * 0.004882814);

  // This equation converts the 0 to 1023 value that analogRead()
  // returns, into a 0.0 to 5.0 value that is the true voltage
  // being read at that pin.
}


