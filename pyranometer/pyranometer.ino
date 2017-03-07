void setup() 
{ 
  Serial.begin(115200);    // <----- here

  // prints title with ending line break 
  Serial.println("ASCII Table ~ Character Map"); 
} 

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0)*1000;
  // print out the value you read:
  Serial.println(voltage);
}
