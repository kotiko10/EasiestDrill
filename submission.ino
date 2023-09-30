#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT11.h>
DHT11 dht11(3);
#define DHT11_PIN 3
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int Button1 = 2;
int Button2 = 5;
int Button3 = 4;

// INFRA RED !!!!!!!!!!!!
const int STATE = 6;
// const int SENSOR_PIN = 6;
const int threshold = 500; // Adjust this threshold value as needed
// INFRA RED !!!!!!!!!!!!


const int gasSensorPin = 0;


void Viabration();
void Temperature();
//200< gamoitane ekranze
void Gas();

void setup() {
    pinMode(Button1, INPUT); // pin 2
    pinMode(Button2, INPUT); // 
    pinMode(Button3, INPUT); 
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    Serial.begin(9600);
    display.clearDisplay();
    display.display();
    pinMode(STATE, INPUT);
}

void loop() {
    display.clearDisplay();
    display.display();
    int val1 = digitalRead(Button1);
    int val2 = digitalRead(Button2);
    int val3 = digitalRead(Button3);
    // int val4 = digitalRead(Button3);
    if (val1 == HIGH) 
    {
      // InfoRed();
      Gas();
    }
    if(val2 == HIGH)
    {
      Vibration();
    }
    if(val3 == HIGH)
    {
      Temperature();
    }
    // if(val4 == HIGH){
    //   Gas();
    // }
}

void InfoRed()
{

  // DAWERE
  // DAWERE
  // DAWERE
  while(true){
    display.clearDisplay();
    display.display();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    
    int distance_cm = analogRead(STATE); // Replace SENSOR_PIN with the correct pin number
    int sensorValue = digitalRead(STATE);

    if (sensorValue <= 10) // If obstacle is 10cm or closer
    {
      display.print("Obstacle ");
      display.print(distance_cm);
      display.println("cm <");
    }
    else
    {
      display.println("No obstacle detected");
    }


    // int sensorState = digitalRead(STATE); // reads the status of the sensor

    // if (sensorState == LOW) { // If there is an obstacle (OUT = 0)
    //   display.println("Obstacle detected"); // Print a message to the serial monitor
    // } else {
    //   display.println("No obstacle detected"); // Print a message to the serial monitor
    // }
    display.display();
    delay(1000); // Delay for 1 second to avoid continuous output
  }
}

void Vibration()
{

}

void Temperature()
{
  display.clearDisplay();
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
  int temperature = dht11.readTemperature();
 display.println(temperature);
  if(temperature>=40)
  {
    display.println("Overheating Warning!");
  }
  display.display();
}

void Gas()
{
  // int val;
  // val=analogRead(0); //Read Gas value from analog 0
  // Serial.println(val,DEC); //Print the value to serial port
  // delay(100);
  // int val = analogRead(A0); // Read analog value from SEN0127 sensor
  while(true){
    int gasConcentration = analogRead(gasSensorPin);

    display.clearDisplay();
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println(gasConcentration);
    if (gasConcentration < 100) {
      display.println("No significant gas detected.");
    } else 
    {
      display.println("Wanrning! Gas Detected, Danger!");
    }
    display.display();
    delay(1000); // Delay for reading
  }
  
}