Imports System
Imports Tinkerforge

Module ExampleSimple
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XXYYZZ" ' Change XXYYZZ to the UID of your HAT Zero Brick

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim hz As New BrickHATZero(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Get current voltage
        Dim voltage As Integer = hz.GetUSBVoltage()
        Console.WriteLine("Voltage: " + (voltage/1000.0).ToString() + " V")

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
