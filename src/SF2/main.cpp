#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGH 64
#include <TimeLib32.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGH, &Wire, -1);

ThreeWire myWire(10,11,2); // 10 : DAT ; 11 = CLK ;2= RST
RtcDS1302<ThreeWire> Rtc(myWire);
int bpm = 0;

void setup ()
{
    Serial.begin(9600);

    Serial.print("compiled: ");
    Serial.print(__DATE__);
    Serial.println(__TIME__);
     if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for(;;);
    }
    Rtc.Begin();
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    Serial.println();
    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled)
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        Rtc.SetDateTime(compiled);
    }
}

void loop ()
{
  RtcDateTime now = Rtc.GetDateTime();

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,10);
  display.print(now.Hour(),DEC);
  display.print(":");
  display.print(now.Minute(),DEC);
  display.print(":");
  display.print(now.Second(),DEC);
  display.print(":");
  display.display();
}