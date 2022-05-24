
// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID          "enter your template id from email"
#define BLYNK_DEVICE_NAME           "rc car"
#define BLYNK_AUTH_TOKEN            "enter your auth token here"

int x,y;
// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "%Cipher%®™";
char pass[] = "2444666668888888";

WidgetLED led1(V1);

BlynkTimer timer;

// V1 LED Widget is blinking
void blinkLedWidget()
{
  if (led1.getValue()) {
    led1.off();
    //Serial.println("LED on V1: off");
    digitalWrite(LED_BUILTIN, 0); 
  } else {
    led1.on();
    //Serial.println("LED on V1: on");
    digitalWrite(LED_BUILTIN, HIGH); 
  }
}

BLYNK_WRITE(V3) {
  int x = param[0].asInt();
  
  Serial.print("X = ");
  Serial.print(x);
    int y = param[1].asInt();
  
  Serial.println();
  Serial.print("Y = ");
  Serial.print(y);
 
 Serial.println();
}

void setup()
{pinMode(LED_BUILTIN,OUTPUT);
 pinMode(D0,OUTPUT);
 pinMode(D1,OUTPUT);
 pinMode(D2,OUTPUT);
 pinMode(D3,OUTPUT);
 // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  timer.setInterval(1000L, blinkLedWidget);
}

void loop()
{
  Blynk.run();
  timer.run();
}
