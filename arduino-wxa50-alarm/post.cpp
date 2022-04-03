#include <string>

using namespace std;

/**
 * Send a message to the amplifier
 */
string post(string body) {
    const uint16_t port = 80;

    WiFiClient client;

    if (client.connect(WXA_HOSTNAME, port)) {
        Serial.print("Sending \"");
        Serial.print(body.c_str());
        Serial.println("\"");

        client.println("POST /YamahaRemoteControl/ctrl HTTP/1.1");
        client.println("Connection: close");
        client.print("Content-Length: ");
        client.println(body.length());
        client.println();
        client.println(body.c_str());
    } else {
        Serial.println("Failed to connect to amplifier");
        return "";
    }

    int loops = 0;
    while (!client.available() && loops < 1000) {
        loops++;
        delay(1);
    }

    if (client.available() > 0) {
        string response = client.readString().c_str();
        client.stop();
        return response;
    } else {
        Serial.println("client.available() timed out");
        client.stop();
        return "";
    }
}
