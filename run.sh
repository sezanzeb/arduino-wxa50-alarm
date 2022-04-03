set -e
arduino-cli compile --fqbn esp32:esp32:esp32-poe-iso .
arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32-poe-iso .
screen /dev/ttyUSB0 115200
