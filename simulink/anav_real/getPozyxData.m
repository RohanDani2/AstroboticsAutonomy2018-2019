function [pos, theta] = getPozyxData(obj)
    coder.extrinsic('readasync', 'strsplit', 'fscanf')
    persistent count
    
    if isempty(count)
        count = 0;
    end
    
    while 1
        count = count + 1;
%         readasync(obj)
%         get(obj, 'BytesAvailable');
        % wait for some reads to pass 
        if count > 3
            get(obj, 'BytesAvailable')
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
                fprintf('%d. xPos: %.2f yPos: %.2f theta: %.2f\n', num, pos(1), pos(2), theta);
                return
            end
        else
            trash = fscanf(obj);
            fprintf(trash(1:end-1));
        end
    end
end