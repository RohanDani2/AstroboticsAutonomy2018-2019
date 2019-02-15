clear
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
fprintf(obj1, 'MD0000108001100');

scan_encoded = blanks(0);
while 1
    wait = fscanf(obj1);
    
    % waiting for rx 99b\n (no error checking)
    if size(wait,2) == 4 
        fscanf(obj1);
        break;
    end 
end 

while 1
    for i = 1:51
        dblock = fscanf(obj1);
        dblock = dblock(1:end-2)
        scan_encoded = [scan_encoded dblock];
        len = size(scan_encoded, 2);

        if i == 51
            scan_decoded = decoder(scan_encoded);
            plotter(scan_decoded);
            scan_encoded = blanks(0);
            for j = 1:4
                fscanf(obj1)
            end
        end
    end
end
