#include <Arduino.h>
#include <SevSeg.h>
#include <SHT3x.h>

SHT3x sht;

SevSeg sevseg;

void setup() {
    byte numDigits = 4;
    byte digitPins[] = {2, 3, 4, 5};
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
    sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, true);
    sevseg.setBrightness(100);

    sht.Begin();
}

void loop() {
    sht.UpdateData();
    int temp = sht.GetTemperature();
    int hum = sht.GetRelHumidity();
    char outBuff[8];
    sprintf(outBuff, "%d.%d", temp, hum);
    sevseg.setChars(outBuff);
    sevseg.refreshDisplay();
}
