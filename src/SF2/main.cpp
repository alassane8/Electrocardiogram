#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <ThreeWire.h>  
#include <RtcDS1302.h>

// OLED display parameters
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Define pins for the DS1302 module
#define DAT_PIN 10
#define CLK_PIN 11
#define RST_PIN 2

ThreeWire myWire(DAT_PIN, CLK_PIN, RST_PIN); // (DAT, CLK, RST)
RtcDS1302<ThreeWire> Rtc(myWire);

// Struct to store the time and date
struct Temps {
  int jour;
  int mois;
  int annee;
  int heure;
  int min;
  int sec;
};

// Function prototypes
Temps getTime();
void printTime(Temps t);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.clearDisplay();

  // Initialize the RTC
  // Set initial time (uncomment if you need to set the time)
  // Rtc.SetDateTime(RtcDateTime(2022, 11, 16, 0, 0, 0)); // YYYY, MM, DD, HH, MM, SS

  // Print the initial time to serial monitor
  Temps t = getTime();
  printTime(t);
}

Temps getTime() {
  RtcDateTime now = Rtc.GetDateTime();
  Temps t;
  t.jour = now.Day();
  t.mois = now.Month();
  t.annee = now.Year();
  t.heure = now.Hour();
  t.min = now.Minute();
  t.sec = now.Second();
  return t;
}

void printTime(Temps t) {
  // Print date
  Serial.print(t.jour);
  Serial.print("/");
  Serial.print(t.mois);
  Serial.print("/");
  Serial.print(t.annee);
  Serial.println();

  // Print time
  Serial.print(t.heure);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print(":");
  Serial.print(t.sec);
  Serial.println();
}

void loop() {
  Temps t = getTime();
  printTime(t);

  // Add a 1-second delay between readings
  delay(1000);
}
