//    32-BIT DAC A2DP_Sink with WS2182FX and bluetooth streaming/control

#include <WiFi.h>
#include <WiFiMulti.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
WiFiMulti wifiMulti;
#include "BluetoothA2DPSink.h"
BluetoothA2DPSink a2dp_sink;
// this header is needed for Bluetooth Serial -> works ONLY on ESP32
#include "BluetoothSerial.h"
#include "credentials.h"
// init Class:
BluetoothSerial ESP_BT;
int incoming;

#include <WS2812FX.h>
#include "WipItsLED.h"

TaskHandle_t btStream;
TaskHandle_t wifi_Neo;

void setup() {
  xTaskCreatePinnedToCore(
                    btTASK,   /* Task function. */
                    "btStream",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &btStream,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
  delay(500); 

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
                    wifiTASK,   /* Task function. */
                    "wifi_Neo",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &wifi_Neo,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 */
    delay(500);
}


  void btTASK( void * pvParameters ){
//  Serial.print("Task1 running on core ");
//  Serial.println(xPortGetCoreID());

  a2dp_sink.set_bits_per_sample(32);
  i2s_pin_config_t my_pin_config = {
    .bck_io_num = 21,   //    BCK
    .ws_io_num = 22,    //    LRCK
    .data_out_num = 4,   //    DIN
    .data_in_num = I2S_PIN_NO_CHANGE
  };
  a2dp_sink.set_pin_config(my_pin_config);
  a2dp_sink.start(btDeviceName);  
  for(;;){
    delay(1000);
  }
}

void initOTA(){
  WiFi.persistent(false);  // Disable storing WiFi settings in flash
  WiFi.mode(WIFI_STA);
  WiFi.setHostname(espHostName);
  wifiMulti.addAP(ssid1, ssidPassphrase1);
  wifiMulti.addAP(ssid2, ssidPassphrase2);
  if(wifiMulti.run() == WL_CONNECTED) {
    ESP.restart();
  }
  ArduinoOTA.setHostname(espHostName);
  ArduinoOTA.setPasswordHash(otaPasswordHash);
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else // U_SPIFFS
      type = "filesystem";

    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
//      Serial.println("Start updating " + type);
  })
  .onEnd([]() {
//      Serial.println("\nEnd");
  })
  .onProgress([](unsigned int progress, unsigned int total) {
//      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  })
  .onError([](ota_error_t error) {
//  Serial.printf("Error[%u]: ", error);
//  if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
//  else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
//  else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
//  else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
//  else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });

  ArduinoOTA.begin();

//  Serial.println("Ready");
//  Serial.print("IP address: ");
//  Serial.println(WiFi.localIP());
}

  void wifiTASK( void * pvParameters ){
//  Serial.print("Task1 running on core ");
//  Serial.println(xPortGetCoreID());

  initOTA();
  ESP_BT.begin("Chl@B$_WipIts");    //    Initialize Bluetooth and name your Bluetooth interface -> will show up on your phone
  ws2812fx.init();
  ws2812fx.setBrightness(30);
  ws2812fx.setSpeed(1000);
  ws2812fx.setColor(0x007BFF);
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.start();
  
  for(;;){
  if(wifiMulti.run() != WL_CONNECTED) {
      delay(1000);
    }
    ws2812fx.service();
    ArduinoOTA.handle();
//    btCommandIncoming();
  }
}

void loop() {
    //    Move along. Nothing to see here.
  }
