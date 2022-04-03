#include <string>
#include <math.h>
#include "config.cpp"
#include "wifi.cpp"
#include "post.cpp"
#include "time.cpp"

using namespace std;

// don't trigger that many minutes after the supposed triggertime.
// If the esp is turned on during this time, it will trigger the alarm.
const int MAX_DELTA = 5;

bool triggered = false;

/**
 * Switch to usb and start playing music
 */
void play() {
    // TODO only continue if response OK
    post(R"(<YAMAHA_AV cmd="PUT"><Main_Zone><Power_Control><Power>On</Power></Power_Control></Main_Zone></YAMAHA_AV>)");
    post(R"(<YAMAHA_AV cmd="PUT"><Main_Zone><Input><Input_Sel>USB</Input_Sel></Input></Main_Zone></YAMAHA_AV>)");
    // it won't start playing until any song selected. this also starts playing
    post(R"(<YAMAHA_AV cmd="PUT"><USB><List_Control><Direct_Sel>Line_1</Direct_Sel></List_Control></USB></YAMAHA_AV>)");
    // shuffle
    post(R"(<YAMAHA_AV cmd="PUT"><USB><Play_Control><Play_Mode><Shuffle>On</Shuffle></Play_Mode></Play_Control></USB></YAMAHA_AV>)");
    // next song will be randomly due to shuffle
    post(R"(<YAMAHA_AV cmd="PUT"><USB><Play_Control><Playback>Skip Fwd</Playback></Play_Control></USB></YAMAHA_AV>)");
}

void setup() {
    connectWiFi();
}

void loop() {
    update_time();

    int hours = timeClient.getHours();
    int minutes = timeClient.getMinutes();
    int seconds = timeClient.getSeconds();

    // calculate how many minutes ago the alarm was supposed to trigger
    int deltaMinutes = (hours - ALARM_HOUR) * 60 + (minutes - ALARM_MINUTE);

    if (!triggered && deltaMinutes < MAX_DELTA && deltaMinutes > 0) {
        // TODO check amplifier response
        Serial.println("Alarm triggers now");
        play();

        // make sure to only talk to the amplifier once
        triggered = true;
    }

    if (deltaMinutes > MAX_DELTA) {
        triggered = false;
    }

    Serial.print("Time: ");
    Serial.print(timeClient.getFormattedTime());
    Serial.print(", alarm triggers in ");
    Serial.print(-deltaMinutes);
    Serial.println(" Minutes");

    delay(5000);
}
