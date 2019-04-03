% W = evalin('caller','whos'); %or 'base'
% doesExist = ismember('a',{W(:).name});
% if doesExist
%     stopasync(a)
%     fclose(a);
%     delete(a) 
% end

clear 
a = serial('/dev/ttyUSB0');
a.InputBufferSize = 128;
fopen(a);
set(a, 'BaudRate', 115200);
a.ReadAsyncMode = 'manual';

figure(1)
clf

eps = 0.5;
i = 0;
while 1
    readasync(a)
    a.BytesAvailable;
    out = fscanf(a);
    if i > 10
        split = strsplit(out(1:end-2), ',');
        data0 = str2double(split)
        if size(data0, 2) == 3
            data1 = [data0(1)+eps*cos(data0(3)) data0(2)+eps*sin(data0(3))];
            vectarrow(data0(1:2), data1);
            hold on; xlim([0 30]); ylim([0 20]); grid on; grid minor; hold off
        end
        drawnow
    end
    i = i + 1;
end  

stopasync(a)
fclose(a);
delete(a)