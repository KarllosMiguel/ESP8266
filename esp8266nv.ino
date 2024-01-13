#include "ESP8266WiFi.h"

void setup() {
  Serial.begin(9600);
  Serial.println();
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}
void printScanResult(int networksFound) {
  Serial.printf("\n");
  Serial.printf("%d Networks found\n", networksFound);

  for (int i = 0; i < networksFound; i++) {

    Serial.printf("%d: %s, Ch:%d (%ddBm) %s\n", i + 1, WiFi.SSID(i).c_str(),
                  WiFi.channel(i), WiFi.RSSI(i), WiFi.encryptionType(i) == ENC_TYPE_NONE ? "OPEN" : "");
  }
}


void loop() {
  WiFi.scanNetworksAsync(printScanResult);
  delay(100);
}
