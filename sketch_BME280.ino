#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define SEALEVELPRESSURE_HPA (1012.0)

Adafruit_BME280 bme;

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN //In this case CSN = pin 8 with PCB it is pin 10

//address through which two modules communicate.
const byte address[6] = "00001";


void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
}

float Temp;
float Hum;
char buffer[16];
long count = 1;

char stringOne[4] = "H1 ";
char stringTemp[5];
char stringHum[5];
char stringMessage[16];

// free RAM check for debugging. SRAM for ATmega328p = 2048Kb.
int availableMemory() 
{
    // Use 1024 with ATmega168
    int size = 2048;
    byte *buf;
    while ((buf = (byte *) malloc(--size)) == NULL);
        free(buf);
    return size;
}

void loop() {
  
    Temp = (bme.readTemperature());
    
    Hum = (bme.readHumidity());
     
    //Send message to receiver
  
    dtostrf(Temp,4,1,stringTemp);
    dtostrf(Hum,4,1,stringHum);
    strcpy(stringMessage, stringOne);
    
    strcat(stringMessage, stringTemp);
    strcat(stringMessage, " ");
    strcat(stringMessage, stringHum);
    Serial.println(stringMessage);  
    radio.write(stringMessage, sizeof(stringMessage));

    //Serial.println(availableMemory()); //uncomment for memory info
    Serial.println(count);
    count++;
    delay(60000);
}
