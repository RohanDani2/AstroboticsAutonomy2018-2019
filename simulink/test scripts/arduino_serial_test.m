a = serial('/dev/cu.usbmodem1421');
a.InputBufferSize = 128;
fopen(a);
set(a, 'BaudRate', 115200);
a.ReadAsyncMode = 'manual';

for i = 1:15
    readasync(a)
    a.BytesAvailable
    fscanf(a)
    pause
end

stopasync(a)
fclose(a);
delete(a) 
clear a   