clear;
clf('reset');

line1 = [2000,2000,0; 2300,2300,0;];
line2 = [2000,2000,0; 1700,2300,0;];
line3 = [1700,2300,0; 2300,2300,0;];
triangle = vertcat(line1, line2, line3);
triangle(:,[1 2]) = triangle(:,[2 1]);


x=randi([1600,2400]);
y=randi([1900,2400]);
pt1 = [x,y,0];
% pt2 = [0,350,0];
% pt3 = [200,150,0];
% pt4 = [-200,150,0];
points = vertcat(pt1);

detected = detectObject(points,triangle); 

hold on
plot(triangle(:,1), triangle(:,2), 'co-');
if detected
    plot(points(:,1), points(:,2), 'r*');
else
    plot(points(:,1), points(:,2), 'k*');
end
hold off
