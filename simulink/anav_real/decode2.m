function [out] = decode2(raw)
    coder.extrinsic('reshape')

    len = length(raw);
    numbits = 6;
    numchars = 3;
    
    data = raw; 
    data1 = uint8(data);
    data2 = data1 - uint8('0');
    data3 = dec2bin(data2, numbits);
    combined = reshape(data3',numbits*numchars,len/numchars)';
    
    dec = bin2dec(combined);
    out = zeros(len/3, 1); % known type 
    out = dec;
    out(out == 1) = 30000;
   
end 