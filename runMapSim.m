% TODO 
% Obstacles of various shapes and sizes 
% Translate robot and vision matrix
% Scale robot
% Rotate robot and vision matrix
% Calculate collision 

% Clear workspace, clear plot, reinitialize random number generator 
clear;
clf('reset')
%rng('shuffle')

% User defined variables
xmax = 5756;
ymax = 3691;
offset = 300;
obstacle_count = 100;
vision_width = 300; % width = depth 
vision_depth = 300;

% Generate random start location, direction, and init robot vector 
xinitial = randi([2*offset, xmax-2*offset]);
yinitial = randi([2*offset, ymax-2*offset]);
% theta = randi([0, 3]);
% if theta == 0
% elseif theta == 1
%     theta = pi/2;
% elseif theta == 2
%     theta = pi;
% elseif theta == 3
%     theta = 3*pi/2;  
% end
xrobot = [xinitial, xinitial-100, xinitial-100, xinitial+100, xinitial+100];
yrobot = [yinitial+150, yinitial+50, yinitial-150, yinitial-150, yinitial+50];
g = hgtransform;

% Generate vision array 
partial(vision_depth, vision_width, 2, 2) = 0;
for r = 1:vision_depth
    for c = 1:vision_width
        partial(r,c,1,1) = -(vision_width-c);
        partial(r,c,2,1) = c-1;
        partial(r,c,1,2) = vision_depth-r;
        partial(r,c,2,2) = vision_depth-r;
    end
end

partial(:,:,:,1) = partial(:,:,:,1) + xinitial;
partial(:,:,:,2) = partial(:,:,:,2) + yinitial + 150;

partial(:,:,1,1) = triu(partial(:,:,1,1));
partial(:,:,1,2) = triu(partial(:,:,1,2));
partial(:,:,2,1) = flipud(tril(partial(:,:,2,1)));
partial(:,:,2,2) = fliplr(triu(partial(:,:,2,2)));

vision(vision_depth, vision_width*2, 2) = 0;
vision(:,:,1) = horzcat(partial(:,:,1,1), partial(:,:,2,1));
vision(:,:,2) = horzcat(partial(:,:,1,2), partial(:,:,2,2));
vision(vision == 0) = NaN;

% Generate random x, y coordiantes 
xobj = 1:obstacle_count;
yobj = 1:obstacle_count;
for i = 1:obstacle_count
    xobj(i) = randi([0,xmax]);
    yobj(i) = randi([0,ymax]);
end

% Generate virtual limit coordinates
xmax_new = xmax-offset;
ymax_new = ymax-offset;
xlimit = 1:((xmax_new+ymax_new)*2-4*offset);
ylimit = 1:((xmax_new+ymax_new)*2-4*offset);
for i = 1:(xmax_new-offset) %complete bottom
    xlimit(i) = i+offset;
    ylimit(i) = offset;
end
for i = (xmax_new-offset+1):(xmax_new+ymax_new-2*offset) %complete bottom, right 
    xlimit(i) = xmax_new;
    ylimit(i) = offset+(i-(xmax_new-offset));
end
for i = (xmax_new+ymax_new-2*offset+1):(2*xmax_new+ymax_new-3*offset) %complete bottom, right, top
    xlimit(i) = xmax_new-(i-(xmax_new+ymax_new))-2*offset;
    ylimit(i) = ymax_new;
end
for i = (2*xmax_new+ymax_new-3*offset+1):(2*(xmax_new+ymax_new)-4*offset) %complete bottom, right, top, left 
    xlimit(i) = offset;
    ylimit(i) = ymax_new-(i-(2*xmax_new+ymax_new)+3*offset);
end

% Generate field wall coordinates
xwall = 2:((xmax+ymax)*2);
ywall = 2:((xmax+ymax)*2);
for i = 1:xmax %complete bottom
    xwall(i) = i-1;
    ywall(i) = 0;
end
for i = (xmax+1):(xmax+ymax) %complete bottom, right 
    xwall(i) = xmax;
    ywall(i) = i-xmax-1;
end
for i = (xmax+ymax+1):(2*xmax+ymax) %complete bottom, right, top
    xwall(i) = xmax-(i-(xmax+ymax));
    ywall(i) = ymax;
end
for i = (2*xmax+ymax+1):(2*(xmax+ymax)-1) %complete bottom, right, top, left 
    xwall(i) = 0;
    ywall(i) = ymax-(i+1-(2*xmax+ymax));
end

% Detect objects

    obj_detected = 1;

% Visualize data 
hold on
grid on
grid minor
xlim([0 6600])
ylim([0 4400])
patch('XData',xrobot,'YData',yrobot,'FaceColor','black','Parent',g)
plot(vision(:,:,1), vision(:,:,2), 'y.-');
plot(xobj, yobj, 'bs');
plot(xlimit, ylimit, 'gs-');
plot(xwall, ywall, 'ks-');
if obj_detected == 1
    plot(6200, 4000, 'r*')
else
    plot(6200, 4000, 'g*')
end
hold off