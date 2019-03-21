% calculate or load base list from file once and change wiper position on each line
% 1 faster for big r, 1 and 2 "same" for big t
% test horzcat/vertcat vs [A B]/[A; B] speed
% add test lidar mode 
% real should have 1081 radii and 600 points per radii 

clear
numLines = 50;
numPoints = 20;

a = zeros(100,1);
for i = 1:100
    %clear t r lines
    tic
    t = linspace(-pi/4, 5*pi/4, numLines);
    r = linspace(0, 30, numPoints);
    lines = vertcat(repelem(t, length(r)), repmat(r, 1, length(t)));
    a(i) = toc;
end
disp(mean(a))
figure(1)
polar(lines(1,:), lines(2,:), 'b.')

input = [-pi/4 randi([0 30]);...
         0 randi([0 30]);...
         pi/6 randi([0 30]);...
         pi/2 randi([0 30]);...
         3*pi/4 randi([0 30])];

values = zeros(1, numLines*numPoints);
%   for each radius value 
%     if radius value not in inputs, set all points of line to 0
%     if radius value in inputs
%       set minimum distance through distance - 1 to 0
%       set point at distance value to 1
%       set point at distance + 1 through max distance to nan   




% clear
% b = zeros(100,1);
% for i = 1:100
%     clear t r lent lenr linez
%     tic
%     t = linspace(-pi/4, 5*pi/4, 50);
%     r = linspace(0, 30, 20);
%     lent = length(t); 
%     lenr = length(r);
%     linez = zeros(2, lent*lenr);
%     for j = 0:lenr-1
%         linez(1, j*lent+1:j*lent+lent) = t;
%         linez(2, j*lent+1:j*lent+lent) = r(j+1)*ones(1, lent);
%     end
%     b(i) = toc;
% end
% disp(mean(b))
% figure(2)
% polar(linez(1,:), linez(2,:), 'b.')
