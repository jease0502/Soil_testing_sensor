float Temp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  Temp = analogRead(A0);
  Temp = (Temp / 1024 * 5) /0.01;
  Serial.print("溫度");
  Serial.println(Temp);
  delay(1000);
}
