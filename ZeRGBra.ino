#include <Adafruit_NeoPixel.h>

#define DATAPIN D2

//#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
//#define BLYNK_DEBUG

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, DATAPIN, NEO_GRB + NEO_KHZ800);

char auth[] = "xxxxx";

WiFiClient client;

char ssid[] = "xxxxxx";
char pass[] = "xxxxxx";

void setup()
{
  Blynk.begin(auth, ssid, pass);
  WiFi.begin(ssid, pass);
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V1)
{
  uint32_t r = param[0].asInt();
  uint32_t g = param[1].asInt();
  uint32_t b = param[2].asInt();

  colorWipe(strip.Color(r, g, b));
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
  }
}
