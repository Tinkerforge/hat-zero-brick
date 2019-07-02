function matlab_example_simple()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickHATZero;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XXYYZZ'; % Change XXYYZZ to the UID of your HAT Zero Brick

    ipcon = IPConnection(); % Create IP connection
    hz = handle(BrickHATZero(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current voltage
    voltage = hz.getUSBVoltage();
    fprintf('Voltage: %g V\n', voltage/1000.0);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end
