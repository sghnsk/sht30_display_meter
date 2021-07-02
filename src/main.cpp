#include <Arduino.h>
#include <SevSeg.h>
#include <Wire.h>
#include <SHT31.h>

SHT31 sht;

SevSeg sevseg;

void setup() {
    byte numDigits = 4;
    byte digitPins[] = {2, 3, 4, 5};
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
    sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, true);
    sevseg.setBrightness(100);

    Wire.begin();
    sht.begin(0x44);
    // Wire.setClock(100000);
}

void loop() {
    sht.read();
    int temp = sht.getTemperature();
    int hum = sht.getHumidity();
    char outBuff[8];
    sprintf(outBuff, "%d.%d", temp, hum);
    sevseg.setChars(outBuff);
    sevseg.refreshDisplay();
}
