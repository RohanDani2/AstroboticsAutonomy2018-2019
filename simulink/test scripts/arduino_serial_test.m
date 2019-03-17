clear 
a = serial('/dev/cu.usbmodem1421');
a.InputBufferSize = 128;
fopen(a);
set(a, 'BaudRate', 115200);
a.ReadAsyncMode = 'manual';

figure(1)
clf
xlim([10 20])
ylim([-45 -35])
hold on 
grid on 
grid minor

for i = 1:1000
    readasync(a)
    a.BytesAvailable;
    out = fscanf(a);
    if i > 5
        split = strsplit(out(1:end-2), ',');
        data = str2double(split)
        if size(data, 2) == 3
            plot(data(1), data(2), 'bo', 'MarkerSize', 1)
        end
        drawnow
    end
end

hold off
stopasync(a)
fclose(a);
delete(a) 
clear a   