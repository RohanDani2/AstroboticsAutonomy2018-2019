clear;
clf('reset');

offset = 150;
depth = 300;

r = sqrt(offset^2+(2*depth^2)-2*offset*sqrt(2*depth^2)*cos(135*pi/180));
theta = linspace(-pi,pi);
xc = [r*cos(theta); offset*cos(theta)];
yc = [-r*sin(theta); -offset*sin(theta)];

for t = 0:5*pi/180:2*pi
    th = t + asin(depth/r);
    tl = th - 2*asin(depth/r);
    x = [offset*cos(t) r*cos(th) r*cos(tl) offset*cos(t)];
    y = [offset*sin(t) r*sin(th) r*sin(tl) offset*sin(t)];
    plot(x,y);
    hold on
    plot(xc(1,:),yc(1,:));
    plot(xc(2,:),yc(2,:));
    xlim([-600 600]);
    ylim([-600 600]);
    drawnow
    hold off 
end



% line1 = [0,150,0; 300,450,0;];
% line2 = [0,150,0; -300,450,0;];
% line3 = [-300,450,0; 300,450,0;];
% triangle = vertcat(line1, line2, line3);
% plot(triangle(:,1),triangle(:,2));
hold off