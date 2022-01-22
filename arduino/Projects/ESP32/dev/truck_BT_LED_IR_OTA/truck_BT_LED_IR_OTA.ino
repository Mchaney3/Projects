//    32-BIT DAC A2DP_Sink with WS2182FX and bluetooth streaming/control

//    TODO: Figure out the symaphore to shut down BT on Core 0, from Core 1
//  Stabilize code with ILI9341 connected. Crashing with BT connected

// Pins 32 through 39 are only unused pins. 33-39 are input only

#include "credentials.h"
#include "BluetoothA2DPSink.h"
//BluetoothA2DPSink a2dp_sink;
#include <WiFi.h>
#include <WiFiMulti.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <WS2812FX.h>
#include "soc/soc.h" //disable brownout problems
#include "soc/rtc_cntl_reg.h"  //disable brownout problems
#include <TFT_eSPI.h>                 // Include the graphics library (this includes the sprite functions)
#include "Core0.h"
#include <Arduino.h>
//#include "IRpindefinitions.h"
#include <IRremote.hpp>

#define LED_COUNT       255
#define LED_PIN         2
#define DECODE_NEC      // Includes Apple and Onkyo
//#define DEBUG         // to see if attachInterrupt is used
//#define TRACE         // to see the state of the ISR state machine
#define IR_RECEIVE_PIN  39  // analog pin
#define STR_HELPER(x)   #x // IR Receiver helper
#define STR(x)          STR_HELPER(x) // IR Receiver Helper
int OKAY_SHIFT = 0;

WiFiMulti wifiMulti;
WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
//                                    // the pointer is used by pushSprite() to push it onto the TFT
TFT_eSPI    tft = TFT_eSPI();         // Create object "tft"
TFT_eSprite img = TFT_eSprite(&tft);  // Create Sprite object "img" with pointer to "tft" object

void process_IR(){    //    Need to write case for this instead of if, if, if, if
  if (IrReceiver.decodedIRData.protocol != NEC) {
    // We have an unknown protocol here, print more info
    //IrReceiver.printIRResultRawFormatted(&Serial, true);
    } else {
      // Print a short summary of received data
      IrReceiver.printIRResultShort(&Serial);
      Serial.println();
    }
  IrReceiver.resume(); // Enable receiving of the next value
  //    0x18 = Up arrow - Increase brightness by 25
  if (IrReceiver.decodedIRData.command == 0x18) {
    if (OKAY_SHIFT == 0) {
      Serial.print("Setting brightness to ");
      Serial.println(ws2812fx.getBrightness() + 25);
      ws2812fx.setBrightness(ws2812fx.getBrightness() + 25);
    } else {
      ws2812fx.setColor(ws2812fx.getColor() + 1);
      Serial.print("Setting color to ");
      Serial.println(ws2812fx.getColor() + 1);
    }
  }
  //    0x52 = Down Arrow - Decrease brightness by 25
  else if (IrReceiver.decodedIRData.command == 0x52) {
    if (OKAY_SHIFT == 0) {
      Serial.print("Setting brightness to ");
      Serial.println(ws2812fx.getBrightness() - 25);
      ws2812fx.setBrightness(ws2812fx.getBrightness() - 25);
      } else {
        ws2812fx.setColor(ws2812fx.getColor() - 1);
        Serial.print("Setting color to ");
        Serial.println(ws2812fx.getColor() - 1);
      }
    }
  //    0x8 = Left arrow
  else if (IrReceiver.decodedIRData.command == 0x8) {
    if (OKAY_SHIFT == 0) {
      int lastMode = ws2812fx.getMode() - 1;
      Serial.print("Settting LED mode to ");
      Serial.println(lastMode);
      ws2812fx.setMode(lastMode);
    } else {
      int speedDecrease = ws2812fx.getSpeed() - 10;
      Serial.print("Settting LED speed mode to ");
      Serial.println(speedDecrease);
      ws2812fx.setMode(speedDecrease);
    }
  }
  //    0x5A = Right arrow
  else if (IrReceiver.decodedIRData.command == 0x5A) {
    if (OKAY_SHIFT == 0) {
      int nextMode = ws2812fx.getMode() + 1;
      Serial.print("Settting LED mode to ");
      Serial.println(nextMode);
      ws2812fx.setMode(nextMode);
    } else {
      int speedIncrease = ws2812fx.getSpeed() + 10;
      Serial.print("Settting LED speed mode to ");
      Serial.println(speedIncrease);
      ws2812fx.setMode(speedIncrease);
    }
  }
  //    0x1C = OK
  else if (IrReceiver.decodedIRData.command == 0x1C) {
    if (OKAY_SHIFT == 0) {
      OKAY_SHIFT++;
    } else if (OKAY_SHIFT == 1) {
      OKAY_SHIFT--;
    }
    Serial.println(OKAY_SHIFT);
  }
  //    0x45 = 1
  else if (IrReceiver.decodedIRData.command == 0x45) {
    ws2812fx.setMode(FX_MODE_CHASE_BLACKOUT_RAINBOW);
    Serial.print("Set LED mode to ");
    Serial.println("FX_MODE_CHASE_BLACKOUT_RAINBOW");
    }
  //    0x46 = 2
  else if (IrReceiver.decodedIRData.command == 0x46) {
    ws2812fx.setMode(FX_MODE_FIREWORKS_RANDOM);
    Serial.print("Set LED mode to ");
    Serial.println("FX_MODE_FIREWORKS_RANDOM");
  }
  //    0x47 = 3
  else if (IrReceiver.decodedIRData.command == 0x47) {
    ws2812fx.setMode(FX_MODE_HYPER_SPARKLE );
    Serial.print("Set LED mode to ");
    Serial.println("FX_MODE_HYPER_SPARKLE");
  }
  //    0x44 = 4
  else if (IrReceiver.decodedIRData.command == 0x44) {
    ws2812fx.setMode(FX_MODE_THEATER_CHASE);
    Serial.print("Set LED mode to ");
    Serial.println("FX_MODE_THEATER_CHASE");
  }
  //    0x40 = 5
  else if (IrReceiver.decodedIRData.command == 0x40) {
    ws2812fx.setMode(FX_MODE_COLOR_SWEEP_RANDOM);
    Serial.print("Set LED mode to ");
    Serial.println("FX_MODE_COLOR_SWEEP_RANDOM");
  }
  //    0x43 = 6
  else if (IrReceiver.decodedIRData.command == 0x43) {
    ws2812fx.setMode(FX_MODE_DUAL_SCAN);
    Serial.print("Set LED mode to ");
    Serial.println("FX_MODE_DUAL_SCAN");
  }
  //    0x7 = 7
  else if (IrReceiver.decodedIRData.command == 0x7) {
    ws2812fx.setMode(FX_MODE_MULTI_DYNAMIC);
    Serial.print("Set LED mode to ");
    Serial.println("FX_MODE_MULTI_DYNAMIC");
  }
  //    0x15 = 8
  else if (IrReceiver.decodedIRData.command == 0x15) {
    ws2812fx.setMode(FX_MODE_COLOR_WIPE_RANDOM);
    Serial.print("Set LED mode to ");
    Serial.println("FX_MODE_COLOR_WIPE_RANDOM");
  }
  //    0x9 = 9
  else if (IrReceiver.decodedIRData.command == 0x9) {
    ws2812fx.setMode(FX_MODE_FIRE_FLICKER);
    Serial.print("Set LED mode to ");
    Serial.println("FX_MODE_FIRE_FLICKER");
  }
  //    0x19 = 0
  else if (IrReceiver.decodedIRData.command == 0x19) {
    ws2812fx.setMode(FX_MODE_MERRY_CHRISTMAS );
    Serial.print("Set LED mode to ");
    Serial.println("FX_MODE_MERRY_CHRISTMAS");
  }
  //    0x16 = Asterisk
  else if (IrReceiver.decodedIRData.command == 0x16) {
    int randMode = random(1,65);
    ws2812fx.setMode(randMode);
    Serial.print("Set LED mode to a rAnDoM mode named ");
    Serial.println(ws2812fx.getModeName(randMode));
  }
  //    0xD = Pound sign. Use this to follow with 0xx for mode number, 1xx for brightness, 2xx for speed, followed by ok
  else if (IrReceiver.decodedIRData.command == 0x44) {
    /*   # Sign followed by 1xx can set the mode
    *    # Sign followed by 2xx can set the brighntess
    *    # Sign followed by 3xx will set speed    
    */
  }
}

TaskHandle_t bt_stream;
SemaphoreHandle_t xSemaphore = NULL;

void setup() {
  
  Serial.begin(115200);
  delay(1000);
  int cpuSpeed = getCpuFrequencyMhz();
  // Just to know which program is running on my Arduino
  Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));
  Serial.println("CPU running at " + String(cpuSpeed) + "MHz");
  WiFi.mode(WIFI_STA);
  wifiMulti.addAP(ssid1, ssidPassphrase1);
  wifiMulti.addAP(ssid2, ssidPassphrase1);
  if(wifiMulti.run() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    }
    //  OTA 
  ArduinoOTA.setHostname(espHostName);
  ArduinoOTA.setPasswordHash(otaPasswordHash);
  ArduinoOTA
    .onStart([]() {
      noInterrupts();
      a2dp_sink.pause();
      a2dp_sink.set_stream_reader(read_data_stream, false);
      a2dp_sink.stop();
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
      ESP.restart();
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

  ArduinoOTA.begin();
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  Serial.println("\nLCD Initialized\n");
  //IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
  Serial.print(F("\rNEC Protocol initiated. IR ready at hardware pin "));
  Serial.println(IR_RECEIVE_PIN);
  ws2812fx.init();
  ws2812fx.setBrightness(8);
  ws2812fx.setSpeed(1000);
  ws2812fx.setColor(0x007BFF);
  ws2812fx.setMode(FX_MODE_CHASE_RAINBOW);
  ws2812fx.start();
  
  xSemaphore = xSemaphoreCreateMutex();
  
  xTaskCreatePinnedToCore(
                    btTASK,   /* Task function. */
                    "bt_stream",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    2,           /* Always highest priority to assure audio quality */
                    &bt_stream,      /* Task handle to keep track of created task */
                    0);          /* pin Bluetooth to core o */                  
  delay(500);

}

void loop() {
  
  ws2812fx.service();
  if (IrReceiver.decode()) {
    process_IR();
  }
  ArduinoOTA.handle();
  // OTA Setup runs on core 1. Handle on core 0 to shut down BT for upgrade.
  // Creating a Semaphore will fix this so I can run on Core 1 with wifi and LED's
  // Set colour depth of Sprite to 8 (or 16) bits
  img.setColorDepth(8);
  //Create play button sprite
  // Color red or green, depending on if something is playing
  if(a2dp_sink.get_audio_state()!=ESP_A2D_AUDIO_STATE_STARTED){
    tft.setTextSize(2);
    tft.setCursor(0, 0, 2);
    tft.setTextFont(4);
    tft.setTextColor(TFT_CYAN, TFT_RED);
    tft.println("Push Play!");
  } else {
    //clear above
  }
}
