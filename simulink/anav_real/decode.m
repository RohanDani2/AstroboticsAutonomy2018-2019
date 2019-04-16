function [data] = decode(in)
    %num1s1 = 0;

    i = 1; 
    j = 1;
    len = size(in, 2);
    data = zeros(1081,1); 
    while i <= len
        data1 = in(i);
        data2 = in(i+1);
        data3 = in(i+2);
        dec1 = uint8(data1);
        dec2 = uint8(data2);
        dec3 = uint8(data3);
        sub1 = dec1 - uint8('0');
        sub2 = dec2 - uint8('0');
        sub3 = dec3 - uint8('0');
        bin1 = dec2bin(sub1,6);
        bin2 = dec2bin(sub2,6);
        bin3 = dec2bin(sub3,6);
        
        binaryData = [bin1 bin2 bin3];
        measure = bin2dec(binaryData);
        if measure == 1
            data(j, 1) = 30000; % max value 
            %num1s1 = num1s1 + 1;
            %disp([data1 data2 data3])
        else
            data(j, 1) = measure; 
        end
        i = i+3;
        j = j+1; 
    end
    %disp(['number of output ones: ' int2str(num1s1)]);
end 