#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti WiFiMulti;

void connectWiFi() {
    Serial.begin(115200);
    delay(10);

    WiFiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);

    Serial.println("Waiting for WiFi...");

    while (WiFiMulti.run() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }

    Serial.print("WiFi connected, ");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
}
