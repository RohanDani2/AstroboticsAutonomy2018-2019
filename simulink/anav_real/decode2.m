function [out] = decode2(raw)
    coder.extrinsic('reshape')

    len = length(raw);
    numbits = 6;
    numchars = 3;
    
    data = raw; 
    data = uint8(data);
    data = data - uint8('0');
    data = dec2bin(data, numbits);
    combined = reshape(data',numbits*numchars,len/numchars)';
    
    dec = bin2dec(combined);
    out = zeros(len/3, 1); % known type 
    out = dec;
    out(out == 1) = 30000;
   
end 