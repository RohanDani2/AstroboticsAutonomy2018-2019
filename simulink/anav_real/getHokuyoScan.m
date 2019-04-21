function scan_decoded = getHokuyoScan(obj)
    coder.extrinsic('fscanf', 'fprintf', 'sscanf')
    persistent num_scans
    
    if isempty(num_scans)
        fprintf('***************************************************\n');
        fprintf('LIDAR Sync Begin\n');
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
            fscanf(obj);
        end
        fprintf('LIDAR Sync Complete\n');
        fprintf('***************************************************\n');
        num_scans = 1;
    end
    
    file = load('indicies.mat', 'indicies');
    indicies = file.indicies;
    scan_decoded = zeros(1081, 2); 
    scan_decoded(:,1) = linspace(deg2rad(-45), deg2rad(225), 1081);
    num_header_chars = 47;
    num_scan_chars = 3*1081+2*51+1;
        
    
    
    fprintf(obj, 'MD0000108001101');
    
%     trash = blanks(num_header_chars);
%     header = fread(obj, num_header_chars, 'char');
%     header2 = char(header);
%     trash = sscanf(header2,'%c');

    raw1 = char(fread(obj, num_scan_chars+num_header_chars, 'char'));
    raw2 = blanks(num_scan_chars+num_header_chars); % known type 
    raw2 = sscanf(raw1,'%c');
    raw3 = raw2(num_header_chars+1:end);
    raw4 = strip(raw3);
    data = raw4(indicies);
    scan_decoded(:,2) = decode2(data);
    
    num_scans = num_scans + 1;
end