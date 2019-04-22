function [pos, theta] = getPozyxData(obj)
    coder.extrinsic('readasync', 'strsplit', 'fscanf', 'flushinput')
    persistent posP thetaP numP count 
    
    if isempty(count)
        numP = 0;
        posP = [0 0];
        thetaP = 0;
        count = 0;
    end
    
    avail = 0; % known type 
    
    while 1
        count = count + 1;
%         readasync(obj)
%         get(obj, 'BytesAvailable');
        % wait for some reads to pass 
        if count > 3
            avail = get(obj, 'BytesAvailable');
            if 	avail > 0 || count == 4
                raw = fscanf(obj);
                flushinput(obj);
                split = strsplit(raw, ',');
                data = str2double(split);
                dataSize = 0; % set to known type 
                dataSize = size(data, 2);
                if dataSize == 4
                    num = data(1);
                    pos = [data(2) data(3)];
                    theta = data(4);
                    numP = num;
                    posP = pos;
                    thetaP = theta;
                    fprintf('%d. xPos: %.2f yPos: %.2f theta: %.2f\n', num, pos(1), pos(2), theta);
                    return
                end
            else
                num = numP;
                pos = posP;
                theta = thetaP;
                fprintf('%d. xPos: %.2f yPos: %.2f theta: %.2f\n', num, pos(1), pos(2), theta);
                return
            end
        else
            trash = fscanf(obj);
            fprintf(strip(trash));
        end
    end
end