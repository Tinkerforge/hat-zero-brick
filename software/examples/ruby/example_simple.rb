#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/brick_hat_zero'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XXYYZZ' # Change XXYYZZ to the UID of your HAT Zero Brick

ipcon = IPConnection.new # Create IP connection
hz = BrickHATZero.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Get current voltage
voltage = hz.get_usb_voltage
puts "Voltage: #{voltage/1000.0} V"

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
