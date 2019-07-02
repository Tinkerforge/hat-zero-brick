<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickHATZero.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickHATZero;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XXYYZZ'; // Change XXYYZZ to the UID of your HAT Zero Brick

$ipcon = new IPConnection(); // Create IP connection
$hz = new BrickHATZero(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get current voltage
$voltage = $hz->getUSBVoltage();
echo "Voltage: " . $voltage/1000.0 . " V\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
