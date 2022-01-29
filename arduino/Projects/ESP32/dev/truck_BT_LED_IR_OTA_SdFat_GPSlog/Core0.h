#include "BluetoothA2DPSink.h"
BluetoothA2DPSink a2dp_sink;
/*************************            Bluetooth audio and LCD on core 0       ************************************/

void avrc_metadata_callback(uint8_t data1, const uint8_t *data2) {
  Serial.printf("AVRC metadata rsp: attribute id 0x%x, %s\n", data1, data2);
}

void read_data_stream(const uint8_t *data, uint32_t length)
{
  // Do something with the data packet
}

void confirm() {
 a2dp_sink.confirm_pin_code();
}

void btTASK( void * pvParameters ){
  static i2s_config_t i2s_config = {
    .mode = (i2s_mode_t) (I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = 44100, // updated automatically by A2DP
    .bits_per_sample = (i2s_bits_per_sample_t)32,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = (i2s_comm_format_t) (I2S_COMM_FORMAT_STAND_I2S),
    .intr_alloc_flags = 0, // default interrupt priority
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = true,
    .tx_desc_auto_clear = true // avoiding noise in case of data unavailability
  };
  i2s_pin_config_t my_pin_config = {
    .bck_io_num = 27,   //    BCK
    .ws_io_num = 32,    //    LRCK
    .data_out_num = 33,   //    DIN
    .data_in_num = I2S_PIN_NO_CHANGE
  };
  a2dp_sink.set_pin_config(my_pin_config);
  a2dp_sink.set_stream_reader(read_data_stream);
  a2dp_sink.set_avrc_metadata_callback(avrc_metadata_callback);
  a2dp_sink.set_volume(85);
  a2dp_sink.start(btDeviceName);
//  a2dp_sink.confirm_pin_code();
  for(;;){
  ArduinoOTA.handle();
  delay(100);
  }
}
