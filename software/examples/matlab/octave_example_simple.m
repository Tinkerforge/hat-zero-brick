function octave_example_simple()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XXYYZZ"; % Change XXYYZZ to the UID of your HAT Zero Brick

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    hz = javaObject("com.tinkerforge.BrickHATZero", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current voltage
    voltage = hz.getUSBVoltage();
    fprintf("Voltage: %g V\n", voltage/1000.0);

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end
