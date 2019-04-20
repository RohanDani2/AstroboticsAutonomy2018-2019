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
        % wait for 20 reads to pass 
        if count > 10 
            raw = fscanf(obj);
            split = strsplit(raw, ',');
            data = str2double(split);
            dataSize = 0; % set to known type 
            dataSize = size(data, 2);
            if dataSize == 3
                pos = [data(1) data(2)];
                theta = data(3);
                disp([pos theta]);
                return
            end
        else
            trash = fscanf(obj);
        end
    end
end