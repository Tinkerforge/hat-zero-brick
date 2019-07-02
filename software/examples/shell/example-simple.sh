#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XXYYZZ # Change XXYYZZ to the UID of your HAT Zero Brick

# Get current voltage
tinkerforge call hat-zero-brick $uid get-usb-voltage
