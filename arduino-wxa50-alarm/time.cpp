#include <TimeLib.h>  // https://github.com/PaulStoffregen/Time
#include <Timezone.h>  // https://github.com/JChristensen/Timezone
#include <NTPClient.h>  // https://github.com/arduino-libraries/NTPClient

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// for time-change rules see
// https://github.com/JChristensen/Timezone/blob/7cf1425b4ee598573e85b6fa124d4514f71c2586/examples/WorldClock/WorldClock.ino
TimeChangeRule CEST = {"CEST", Last, Sun, Mar, 2, 120};  // Central European Summer Time
TimeChangeRule CET = {"CET ", Last, Sun, Oct, 3, 60};  // Central European Standard Time
Timezone timezone(CEST, CET);

TimeChangeRule *tcr;  // pointer to the time change rule, use to get TZ abbrev

/**
 * Keep the clock up to date. Call this when you need up-to-date time.
 * Afterwards local time is available via
 * - timeClient.getHours(); // NTPClient
 * - hour(); // TimeLib
 */
void update_time() {
    timeClient.update();
    setTime(timeClient.getEpochTime());

    // doing this is required, the esp crashes otherwise
    time_t local = timezone.toLocal(timeClient.getEpochTime(), &tcr);

    timeClient.setTimeOffset(tcr->offset * 60);
}
