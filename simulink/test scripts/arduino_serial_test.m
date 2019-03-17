a = serial('/dev/cu.usbmodem1421');
a.InputBufferSize = 128;
fopen(a);
set(a, 'BaudRate', 115200);
a.ReadAsyncMode = 'manual';

figure(1)
clf
xlim([-15 25])
ylim([-5 15])
hold on 
grid on 
grid minor

for i = 1:200
    readasync(a)
    a.BytesAvailable;
    out = fscanf(a);
    if i > 5
        split = strsplit(out(1:end-2), ',');
        data = str2double(split);
        plot(data(1), data(2), 'b.')
        drawnow
    end
end

hold off
stopasync(a)
fclose(a);
delete(a) 
clear a   