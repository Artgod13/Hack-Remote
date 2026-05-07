#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RotaryEncoder.h>
#include <SmartRC-CC1101-Driver-Lib.h>

SmartRC_CC1101 radio;

//390 mHZ is the goal
//Be careful to follow all radio laws in your area of jurisdiction 
//YOU are responsible with what you do with this code not me

//OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET)

//Rotary Encoder Switch
const int pinA = D2;
const int PinB = D1;
const int buttonPin = D6;

RotaryEncoder encoder(pinA, pinB,
RotaryEncoder::LatchModerTWO03);

//Frequencies
float channels[] = {
    390.0,
    391.0,
    392.0,
    393.0,
    395.0,
    400.0,
    433.0,
    433.92,
    434.0,
    676767.0
};

const int numChannels = sizeof(channels) /
sizeof(channels[0]);

float freq;
int currentIndex = 0;
int lastPos = 0;
bool lastButtonState = HIGH;

void drawScreen() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.SetCursor(0, 0);
    display.Println("RF Channel Select");
    display.setTextSize(2);
    display.SetCursor(0, 14);
    display.Println(channels[currentIndex]);
    display.display();
}

void handleSelection() {
    display.clearDisplay();
    display.setTextSize(1);
    display.SetCursor(0, 0);
    display.Println("Selected:");
    display.setTextSize(2);
    display.SetCursor(0, 14);
    display.Println(channels[currentIndex]);
    display.display();
}


void setRadioFrequency() {
    Serial.begin(115200);
    radio.Init();
    radio.setMHZ(channels[currentIndex]);
    radio.SetTx();
}

void sendPacket() {
    if (channels[currentIndex] == 676767.0) {
        for (int x=0; x<50; x=x+1) {
            
            freq = random(39000, 45000) / 100.0;
            radio.setMHZ(freq);
            byte data[] = {0x00, 0x00, 0x00};
            radio.tx(data, sizeof(data));
            delay(10);

        }    
    } else {

        byte data[] = {0x00, 0x00, 0x00};
        radio.tx(data, sizeof(data));
        delay(1000);

    }
}

void setup() {
    
    Serial.begin(115200);
    radio.Init();
    radio.setMHZ(channels[currentIndex]);
    radio.SetRx();

    pinMode(buttonPin, INPUT_PULLUP);

    Wire.begin();

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        while (1);
    }

    drawScreen();
}


void loop() {
    encoder.tick();

    int newPos = encoder.getPosition();

    if (newPos != lastPos) {
        if (newPos > lastPos) {
            currentIndex++;
        } else {
            currentIndex--;
        }

        if (currentIndex < 0) currentIndex = numChannels - 1;
        if (currentIndex >= numChannels) currentIndex = 0;

        lastPos = newPos;

        setRadioFrequency();
        drawScreen();
    }

    bool buttonState = digitalRead(buttonPin);

    if (lastButtonState == HIGH && buttonState == LOW) {
        sendPacket();
        handleSelection();
        delay(200);
    }

    lastButtonState = buttonState;
}