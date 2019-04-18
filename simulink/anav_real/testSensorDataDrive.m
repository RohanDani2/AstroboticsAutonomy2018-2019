
% Find a serial port object.
obj1 = instrfind('Type', 'serial', 'Port', '/dev/ttyACM1', 'Tag', '');

% Create the serial port object if it does not exist
% otherwise use the object that was found.
if isempty(obj1)
    obj1 = serial('/dev/ttyACM1');
else
    fclose(obj1);
    obj1 = obj1(1);
end

% Connect to instrument object, obj1.
fopen(obj1);

n = 50;
t = zeros(1, n);
for i = 1:n
    tic
    [pos, theta, detectedList, visArea] = testSensorData(zeros(2,3), 0);
    t(i) = toc;
end
mean(t)