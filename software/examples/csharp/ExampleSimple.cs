using System;
using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XXYYZZ"; // Change XXYYZZ to the UID of your HAT Zero Brick

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickHATZero hz = new BrickHATZero(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get current voltage
		int voltage = hz.GetUSBVoltage();
		Console.WriteLine("Voltage: " + voltage/1000.0 + " V");

		Console.WriteLine("Press enter to exit");
		Console.ReadLine();
		ipcon.Disconnect();
	}
}
