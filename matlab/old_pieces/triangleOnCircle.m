clear;
clf('reset');

offset = 150;
depth = 300;

r = sqrt(offset^2+(2*depth^2)-2*offset*sqrt(2*depth^2)*cos(135*pi/180));
theta = linspace(-pi,pi);
xc = [r*cos(theta); offset*cos(theta)];
yc = [-r*sin(theta); -offset*sin(theta)];

obst = 50;
px = 1:obst;
py = 1:obst;
for i = 1:obst
    px(i) = randi([-1000,1000]);
    py(i) = randi([-1000,1000]);
end
points = fliplr(rot90(vertcat(px,py,zeros(1, obst)),3));

for t =  0:5*pi/180:2*pi
    thigh = t + asin(depth/r);
    tlow = thigh -2*asin(depth/r);
    x = [offset*cos(t) r*cos(thigh) r*cos(tlow) offset*cos(t)];
    y = [offset*sin(t) r*sin(thigh) r*sin(tlow) offset*sin(t)];
    z = zeros(1,4);
    cone = fliplr(rot90(vertcat(x,y,z),3));
    detected = detectRotated(points, cone);
    plot(cone(:,1),cone(:,2));
    hold on
    grid on 
    grid minor
    xlim([-1000 1000])
    ylim([-1000 1000])
    plot(xc(1,:),yc(1,:));
    plot(xc(2,:),yc(2,:));
    plot(px(detected==1),py(detected==1), 'r*');
    plot(px(detected==0),py(detected==0), 'k*');
    drawnow
    hold off 
end



% line1 = [0,150,0; 300,450,0;];
% line2 = [0,150,0; -300,450,0;];
% line3 = [-300,450,0; 300,450,0;];
% triangle = vertcat(line1, line2, line3);
% plot(triangle(:,1),triangle(:,2));
hold off