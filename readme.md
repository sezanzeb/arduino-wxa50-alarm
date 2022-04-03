# Arduino WXA-50 Alarm

Triggers USB playback of a yamaha WXA-50 amplifier at a specified time.

The timezone is fixed to german as of now. I used this on an esp32, I guess it would work with
various other boards as well if WiFiMulti is changed to something generic.

```
Waiting for WiFi...
WiFi connected, IP: 192.168.178.75
Time: 21:36:03, alarm triggers in 1 Minutes
Time: 21:37:58, alarm triggers in 0 Minutes
Alarm triggers now
Sending "<YAMAHA_AV cmd="PUT"><Main_Zone><Power_Control><Power>On</Power></Power_Control></Main_Zone></YAMAHA_AV>"
Sending "<YAMAHA_AV cmd="PUT"><Main_Zone><Input><Input_Sel>USB</Input_Sel></Input></Main_Zone></YAMAHA_AV>"
Sending "<YAMAHA_AV cmd="PUT"><USB><List_Control><Direct_Sel>Line_1</Direct_Sel></List_Control></USB></YAMAHA_AV>"
Sending "<YAMAHA_AV cmd="PUT"><USB><Play_Control><Play_Mode><Shuffle>On</Shuffle></Play_Mode></Play_Control></USB></YAMAHA_AV>"
Sending "<YAMAHA_AV cmd="PUT"><USB><Play_Control><Playback>Skip Fwd</Playback></Play_Control></USB></YAMAHA_AV>"
Time: 21:38:09, alarm triggers in -1 Minutes
```

## Dependencies

- https://www.arduino.cc/reference/en/libraries/ntpclient/
- https://www.arduino.cc/reference/en/libraries/timezone/

## Configuration

put

```cpp
#define WIFI_SSID "foo"
#define WIFI_PASSWORD "bar"
#define ALARM_HOUR 8
#define ALARM_MINUTE 0
#define WXA_HOSTNAME "WXA-50"
```

into `arduino-wxa50-alarm/config.cpp`

## Building and Flashing

```bash
./run.sh
```

press and hold the BOOT button on the esp32 so that it starts flashing.

ctrl + a, then k and then y to stop the log output. It needs to be stopped before flashing again.

## Resources

- https://dev.to/stepanvrany/esp32-with-arduino-cli-36mh < actually good
- https://arduino.github.io/arduino-cli/0.19/getting-started/
- https://docs.espressif.com/projects/arduino-esp32/en/latest/getting_started.html
- examples: https://github.com/espressif/arduino-esp32/tree/master/libraries
- https://github.com/arduino-libraries/NTPClient/blob/master/NTPClient.h
