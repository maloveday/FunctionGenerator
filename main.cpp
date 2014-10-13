#include <Arduino.h>
#include <waveforms.h>

extern HardwareSerial Serial;

unsigned int waveformDigitalPins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
unsigned int digitalPinsMask[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800};
unsigned int waveformBits = 12;
unsigned int waveformSample = 0;

void setup() {
  for (unsigned int i = 0; i < waveformBits; i++) {
    pinMode(waveformDigitalPins[i], OUTPUT);
  }
}

void loop() {
  unsigned int sample = pgm_read_word_near(sawWave + waveformSample);
  writeWaveformSample(sample);
  delay(100);
  waveformSample++;
  if (waveformSample > MAX_SAMPLE_NUM) {
    waveformSample = 0;
  }
}

void writeWaveformSample(unsigned int sample) {
  unsigned int output = ((sample & 0x1) == 0x1) ? HIGH : LOW;
  digitalWrite(0, output);
  output = ((sample & 0x2) == 0x2) ? HIGH : LOW;
  digitalWrite(1, output);
  output = ((sample & 0x4) == 0x4) ? HIGH : LOW;
  digitalWrite(2, output);
  output = ((sample & 0x8) == 0x8) ? HIGH : LOW;
  digitalWrite(3, output);
  output = ((sample & 0x10) == 0x10) ? HIGH : LOW;
  digitalWrite(4, output);
  output = ((sample & 0x20) == 0x20) ? HIGH : LOW;
  digitalWrite(5, output);
  output = ((sample & 0x40) == 0x40) ? HIGH : LOW;
  digitalWrite(6, output);
  output = ((sample & 0x80) == 0x80) ? HIGH : LOW;
  digitalWrite(7, output);
}