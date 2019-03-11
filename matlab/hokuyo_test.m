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
while obj1 ~= 0
    fscanf(obj1)
end