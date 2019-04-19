clear

%% Instrument Connection

% Find a serial port object.
obj1 = instrfind('Type', 'serial', 'Port', '/dev/ttyACM1', 'Tag', '');

% Create the serial port object if it does not exist
% otherwise use the object that was found.
if isempty(obj1)
    obj1 = serial('/dev/ttyACM1');
    set(obj1, 'InputBufferSize', 4096)
    set(obj1, 'Terminator', {'LF', 'LF'});
else
    fclose(obj1);
    obj1 = obj1(1);
    set(obj1, 'InputBufferSize', 4096)
    set(obj1, 'Terminator', {'LF', 'LF'});
end

% Connect to instrument object, obj1.
fopen(obj1);

%% Instrument Configuration and Control

%Communicating with instrument object, obj1.
%disp('*******************************************************************');
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
    reset = strip(reset);
    %disp(reset);
end
%disp('*******************************************************************');

scan_encoded = blanks(3243);
thetas = linspace(deg2rad(-45), deg2rad(225), 1081);
indicies = [];
for p = 1:51
    new = 1+(p-1)*66:64+(p-1)*66;
    indicies = [indicies new];
end
indicies = indicies(1:3243);
num_scans = 1;
corrupted_scans = 0;
corrupted = 0;

while 1
    fprintf(obj1, 'MD0000108001101');

    header = char(fread(obj1, 47));
    sscanf(header,'%c');
    
    raw = char(fread(obj1, 3*1081+2*51+1));
    raw2 = sscanf(raw,'%c');
    raw3 = strip(raw2);
    data = raw3(indicies);
    decoded(:,1) = thetas;
    decoded(:,2) = decode2(data);
    polar(decoded(:,1), decoded(:,2), 'b.')
    drawnow
end
        
        
%         dblock = fscanf(obj1);
%         dblock = strip(dblock);
%         dblock = regexprep(dblock, '.$', '', 'lineanchors');
%         blockSize = size(dblock, 2);
%         disp([int2str(i) '. ' dblock]);
%         if (i == 51) && (blockSize == 43)
%             scan_encoded(3201:3243) = dblock;
%         elseif blockSize == 64
%             scan_encoded((64*i-63):(64*i)) = dblock;
%         else
%             corrupted = 1;
%             corrupted_scans = corrupted_scans + 1;
%         end
% 
%         if i == 51 
%             disp(['scan number: ' int2str(num_scans) '  corrupted scans: ' int2str(corrupted_scans)]);
%             num_scans = num_scans + 1;
%             if ~corrupted 
%                 scan_decoded(:,1) = thetas;
%                 scan_decoded(:,2) = decode2(scan_encoded);
%                 m = min(scan_decoded(:,2));
%                 if m == 1
%                     polar(scan_decoded(2:end,1), scan_decoded(2:end,2), 'r.')
%                 else
%                     polar(scan_decoded(2:end,1), scan_decoded(2:end,2), 'b.')
%                 end
%                 drawnow
%             else
%                 corrupted = 0;
%             end
%             scan_encoded = blanks(3243);
%         end
%     end
% end
