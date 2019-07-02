#!/usr/bin/perl

use strict;
use Tinkerforge::IPConnection;
use Tinkerforge::BrickHATZero;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XXYYZZ'; # Change XXYYZZ to the UID of your HAT Zero Brick

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $hz = Tinkerforge::BrickHATZero->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get current voltage
my $voltage = $hz->get_usb_voltage();
print "Voltage: " . $voltage/1000.0 . " V\n";

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
