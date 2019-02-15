function [data] = decoder(in)
    i = 1; 
    j = 1;
    size1 = size(in);
    while i <= size1(2)
        data1 = uint8(in(i)) - uint8('0');
        data2 = uint8(in(i+1)) - uint8('0');
        data3 = uint8(in(i+2)) - uint8('0');
        data1 = dec2bin(data1,6);
        data2 = dec2bin(data2,6);
        data3 = dec2bin(data3,6);
        
        BinaryData = horzcat(data1,data2,data3);
        measure = bin2dec(BinaryData);
        data(j) = measure; 
        i = i+3;
        j = j+1; 
    end
end 