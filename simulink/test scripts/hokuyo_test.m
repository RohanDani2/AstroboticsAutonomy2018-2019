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

%Communicating with instrument object, obj1.
disp('*******************************************************************');
for i = 1:13
    if i == 1
        fprintf(obj1, 'RS');
    elseif i == 4
        fprintf(obj1, 'TM0');
    elseif i == 7
        fprintf(obj1, 'TM1');
    elseif i == 11
        fprintf(obj1, 'TM2');
    end
    reset = fscanf(obj1);
    reset = reset(1:end-1);
    disp(reset);
end
disp('*******************************************************************');

scan_encoded = blanks(3243);
num_scans = 1;
corrupted_scans = 0;
corrupted = 0;

while 1
    fprintf(obj1, 'MD0000108001101');
    while 1
        check = fscanf(obj1);
        check = check(1:end-1);
        disp(check);

        if strcmp(check, '99b')
            fscanf(obj1);
            break;
        end 
    end 
    for i = 1:51
        dblock = fscanf(obj1);
        dblock = dblock(1:end-2);
        blockSize = size(dblock, 2);
        disp([int2str(i) '. ' dblock]);
        if (i == 51) && (blockSize == 43)
            scan_encoded(3201:3243) = dblock;
        elseif blockSize == 64
            scan_encoded((64*i-63):(64*i)) = dblock;
        else
            corrupted = 1;
            corrupted_scans = corrupted_scans + 1;
        end

        if i == 51 
            disp(['scan number: ' int2str(num_scans) '  corrupted scans: ' int2str(corrupted_scans)]);
            num_scans = num_scans + 1;
            if corrupted == 0 
                scan_decoded = decoder(scan_encoded);
                plotter(scan_decoded);
            else
                corrupted = 0;
            end
            scan_encoded = blanks(3243);
        end
    end
end
