//    32-BIT DAC A2DP_Sink with WS2182FX and bluetooth streaming/control

//    TODO: Figure out the symaphore to shut down b


TaskHandle_t bt_stream;
TaskHandle_t led_show;
SemaphoreHandle_t xSemaphore = NULL;
#include "credentials.h"
#include "BluetoothA2DPSink.h"
BluetoothA2DPSink a2dp_sink;
#include <WS2812FX.h>
#include "BT_LED_IR.h"
#include "soc/soc.h" //disable brownout problems
#include "soc/rtc_cntl_reg.h"  //disable brownout problems

void setup() {
  
  Serial.begin(115200);
  delay(3000);
  int cpuSpeed = getCpuFrequencyMhz();
  Serial.println("Running at " + String(cpuSpeed) + "MHz");

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

  xTaskCreatePinnedToCore(
                    ledTASK,   /* Task function. */
                    "led_show",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* Assign priority 1, lower than bluetooth task to assure audio quality */
                    &led_show,      /* Task handle to keep track of created task */
                    1);          /* pin WiFi, LED's, IR and any other thing I can think of to core 1 */
  delay(500);

}

void loop() {
  
}
