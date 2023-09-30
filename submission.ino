#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT11.h>
DHT11 dht11(3);
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int Button1 = 2;
int Button2 = 5;
int Button3 = 4;




const int gasSensorPin = 0;


void Temperature();

void Gas();

void setup() {
    pinMode(Button1, INPUT); // pin 2
    pinMode(Button2, INPUT); // 
    pinMode(Button3, INPUT); 
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    Serial.begin(9600);
    display.clearDisplay();
    display.display();
}

void loop() {
    display.clearDisplay();
    display.display();
    int val1 = digitalRead(Button1);
    int val2 = digitalRead(Button2);
    int val3 = digitalRead(Button3);
    if (val1 == HIGH) 
    {
      Gas();
    }
    if(val2 == HIGH)
    {
     display.clearDisplay();
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("MENU");
    display.display();

    }
    if(val3 == HIGH)
    {
      Temperature();
    }
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
