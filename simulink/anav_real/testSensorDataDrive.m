clear testSensorData getHokuyoScan

n = 50;
t = zeros(1, n);
for i = 1:n
    tic
    [pos, theta, detectedList, visArea] = testSensorData(zeros(2,3), 0);
    t(i) = toc;
%     polar(detectedList(:,1), detectedList(:,2), 'b.')
%     drawnow
end
mean(t(2:end))

pozyx = instrfind('Port', '/dev/ttyUSB0');
if ~isempty(pozyx)
  stopasync(pozyx)
  fclose(pozyx);
  delete(pozyx)
end

hokuyo = instrfind('Port', '/dev/ttyACM1');
if ~isempty(hokuyo)
  fclose(hokuyo);
  delete(hokuyo)
end
