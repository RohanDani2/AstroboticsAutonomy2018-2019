% calculate or load base list from file once and change wiper position on each line
% 1 faster for big r, 1 and 2 "same" for big t
% test horzcat/vertcat vs [A B]/[A; B] speed
% add test lidar mode 

clear
a = zeros(100,1);
for i = 1:100
    clear t r lines
    tic
    t = linspace(-pi/4, 5*pi/4, 1081);
    r = linspace(0, 30, 600);
    lines = vertcat(repelem(t, length(r)), repmat(r, 1, length(t)));
    a(i) = toc;
end
disp(mean(a))
figure(1)
polar(lines(1,:), lines(2,:), 'b.')

clear
b = zeros(100,1);
for i = 1:100
    clear t r lent lenr linez
    tic
    t = linspace(-pi/4, 5*pi/4, 1081);
    r = linspace(0, 30, 600);
    lent = length(t); 
    lenr = length(r);
    linez = zeros(2, lent*lenr);
    for j = 0:lenr-1
        linez(1, j*lent+1:j*lent+lent) = t;
        linez(2, j*lent+1:j*lent+lent) = r(j+1)*ones(1, lent);
    end
    b(i) = toc;
end
disp(mean(b))
figure(2)
polar(linez(1,:), linez(2,:), 'b.')
