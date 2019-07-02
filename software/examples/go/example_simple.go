package main

import (
	"fmt"
	"github.com/Tinkerforge/go-api-bindings/hat_zero_brick"
	"github.com/Tinkerforge/go-api-bindings/ipconnection"
)

const ADDR string = "localhost:4223"
const UID string = "XXYYZZ" // Change XXYYZZ to the UID of your HAT Zero Brick.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	hz, _ := hat_zero_brick.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	// Get current voltage.
	voltage, _ := hz.GetUSBVoltage()
	fmt.Printf("Voltage: %f V\n", float64(voltage)/1000.0)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()
}
