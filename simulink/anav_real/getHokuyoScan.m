function scan = getHokuyoScan(obj)
    coder.extrinsic('fscanf', 'fprintf', 'regexprep')
    persistent num_scans corrupted_scans

    if isempty(num_scans)
        %disp('*******************************************************************');
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
            reset = fscanf(obj);
            reset = strip(reset);
            %disp(reset);
        end
        %disp('*******************************************************************');
        num_scans = 1;
        corrupted_scans = 0;
    end
    
    scan_encoded = blanks(3243);
    thetas = linspace(deg2rad(-45), deg2rad(225), 1081);
    corrupted = 0;

    while 1
        fprintf(obj, 'MD0000108001101');
        while 1
            check = fscanf(obj);
            check = strip(check);
            %disp(check);

            if strcmp(check, '99b')
                fscanf(obj);
                break;
            end 
        end 
        for i = 1:51
            dblock = fscanf(obj);
            dblock = strip(dblock);
            dblock = regexprep(dblock, '.$', '', 'lineanchors');
            blockSize = size(dblock, 2);
            %disp([int2str(i) '. ' dblock]);
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
                if ~corrupted 
                    scan(:,1) = thetas;
                    scan(:,2) = decoder(scan_encoded);
                    return
                else
                    corrupted = 0;
                end
                scan_encoded = blanks(3243);
            end
        end
    end
    
end