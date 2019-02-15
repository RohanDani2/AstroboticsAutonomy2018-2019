%% Instrument Connection

% Find a serial port object.
obj1 = instrfind('Type', 'serial', 'Port', '/dev/tty.usbmodem1411', 'Tag', '');

% Create the serial port object if it does not exist
% otherwise use the object that was found.
if isempty(obj1)
    obj1 = serial('/dev/tty.usbmodem1411');
else
    fclose(obj1);
    obj1 = obj1(1);
end

% Connect to instrument object, obj1.
fopen(obj1);

%% Instrument Configuration and Control

% Communicating with instrument object, obj1.
fprintf(obj1, 'MD0000108001101');

count = 0;
scan_encoded = blanks(0);
for i = 1:6
    fscanf(obj1);
end
for i = 1:51
    dblock = fscanf(obj1);
    dblock = dblock(1:end-2);
    scan_encoded = [scan_encoded dblock];
end
scan_encoded
size(scan_encoded, 2)

scan_decoded = decoder(scan_encoded);
plotter(scan_decoded)
   