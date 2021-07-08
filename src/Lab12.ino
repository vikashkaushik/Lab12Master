/*
 * Project Lab12
 * Description: MASTER
 * Author:
 * Date:
 */
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
// setup() runs once, when the device is first turned on.
void setup()
{
  // Put initialization like pinMode and begin functions here.
  pinMode(D5, OUTPUT);

  SPI.setClockSpeed(1, MHZ);
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.begin(SPI_MODE_MASTER, D5);

  Serial.begin(9600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  // The core of your code will likely live here.
  // transmitting and receiving data
  char rx[1];
  char tx[1];
  if (Serial.available())
  { // Will be true if there is serial data to read
    char value = Serial.read();
    tx[0] = value;
    // if 0 or 1 it just transfers that to slave
    if (value == '0')
    {
      digitalWrite(D5, LOW);
      SPI.transfer(tx, rx, 1, NULL);
      digitalWrite(D5, HIGH);
    }
    if (value == '1')
    {
      digitalWrite(D5, LOW);
      SPI.transfer(tx, rx, 1, NULL);
      digitalWrite(D5, HIGH);
    }
    // if ? then it requests for button info
    if (value == '?')
    {
      digitalWrite(D5, LOW);
      SPI.transfer(tx, rx, 1, NULL);
      digitalWrite(D5, HIGH);
      // if button is off it prints L in serial. H if on.
      if(rx[0] == 0){
        Serial.println('L');
      }
      else{
        Serial.println('H');
      }
      

    }
  
  }

} 
