function scan_decoded = getHokuyoScan(obj)
    coder.extrinsic('pad', 'fscanf', 'fprintf', 'regexprep')
    persistent num_scans corrupted_scans

    if isempty(num_scans)
        disp('*******************************************************************');
        for i = 1:13
            if i == 1
                fprintf(obj, 'RS');
            elseif i == 4
                fprintf(obj, 'TM0');
            elseif i == 7
                fprintf(obj, 'TM1');
            elseif i == 11
                fprintf(obj, 'TM2');
            end
            disp(fscanf(obj));
        end
        disp('*******************************************************************');
        num_scans = 1;
        corrupted_scans = 0;
    end
    
    scan_encoded = blanks(3243);
    scan_decoded = zeros(1081, 2); 
    scan_decoded(:,1) = linspace(deg2rad(-45), deg2rad(225), 1081);
    padSize = 100; % max is 66 
    flag_corrupted = 0;
    flag_header = 0;

    while 1
        fprintf(obj, 'MD0000108001101');
        while ~flag_header
            if strcmp(strip(fscanf(obj)), '99b')
                fscanf(obj);
                flag_header = 1;
                break;
            end 
        end 
        for i = 1:51
            
            dblock = blanks(padSize); % set to known type 
            dblockTemp = blanks(padSize); % set to known type 
            blockSize = 0; % set to known type 
            dblockTemp = pad(fscanf(obj), padSize, 'right');
            dblock = pad(regexprep(strip(dblockTemp), '.$', '', 'lineanchors'), padSize, 'right');
            %disp(dblock);
            blockSize = size(strip(dblock), 2);
            if (i == 51) && (blockSize == 43)
                scan_encoded(3201:3243) = strip(dblock);
            elseif blockSize == 64
                scan_encoded((64*i-63):(64*i)) = strip(dblock);
            else
                flag_corrupted = 1;
                corrupted_scans = corrupted_scans + 1;
            end

            if i == 51 
                disp(['scan number: ' int2str(num_scans) '  corrupted scans: ' int2str(corrupted_scans)]);
                num_scans = num_scans + 1;
                if ~flag_corrupted 
                    scan_decoded(:,2) = decoder(scan_encoded);
                    return
                else
                    flag_corrupted = 0;
                end
                scan_encoded = blanks(3243);
            end
        end
    end
    
end