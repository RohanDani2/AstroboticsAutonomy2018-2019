% Goal for next week is to move robot around obstacle field forever without
% collision and vison cone shown 

% Clear workspace and reinitialize random number generator 
clear;
clf('reset')
rng('shuffle') 

% User defined variables
% Optional manual control 
% Add obstacle size 
xmax = 180;
ymax = 180;
obstacle_count = 10;

% Generate field wall
xwall = 0:xmax;
ywall = 0:ymax;
xmax_vector = xmax*ones(1, ymax+1);
ymax_vector = ymax*ones(1, xmax+1);

% Generate x, y coordiantes of each obstacle 
xcoord = 1:obstacle_count;
ycoord = 1:obstacle_count;
for i = 1:obstacle_count
    xcoord(i) = randi([0,xmax]);
    ycoord(i) = randi([80,120]);
end

% Visualize data 
% Increase wall thickness


hold on
grid on
grid minor
S = 'c+-';
plot(xwall, zeros(1, xmax+1), S);
plot(xwall, ymax_vector, S);
plot(zeros(1, ymax+1), ywall, S);
plot(xmax_vector, ywall, S);
%this plots the squares

plot(xcoord, ycoord, 'ks')
hold off

x = [10 10 15 15];
y = [62 68 68 62];
g = hgtransform;
patch('XData',x,'YData',y,'FaceColor','yellow','Parent',g)
%directions
up = 1; 
down = 2;
left = 3;
right = 4; 
direction = up; 

a = 0; %loop counting variable
x = 1; %plotted x coordinate
y = 68; %plotted y coordinate
xfactor = 5; %used to show whether the robot runs into something
yfactor = 5;
speed = 1;
while (a<1000)
  switch (direction)
      case up
          g.Matrix = makehgtform('translate',x,y,0);
          y = y+speed;
          if y == 107
              if x == -3
                  choices = [down,right];
                  pos = randi(2);
                  direction = choices(pos);
              elseif x == 160
                  choices = [down,left];
                  pos = randi(2);
                  direction = choices(pos);
                  
              else
                  choices = [down,left,right];
                  pos = randi(3);
                  direction = choices(pos); 
                  
                  
% %                   for i = 1:obstacle_count
% %                       xobjcoord = xcoord(i);
% %                       for j = 1:obstacle_count
% %                           yobjcoord = ycoord(j);
% %                           if (x+xfactor == xobjcoord) && (y+yfactor == yobjcoord)
% %                               choices = [down,left,right];
% %                               pos = randi(3);
% %                               direction = choices(pos);  
% %                           else
% %                               choices = [down,left,right];
% %                               pos = randi(3);
% %                               direction = choices(pos);  
% %                           end
% %                       end
% %                   end
              end
          end
      case down
          g.Matrix = makehgtform('translate',x,y,0);
          y = y - speed; 
          if y == -58
              if x == -3
                  choices = [up,right];
                  pos = randi(2);
                  direction = choices(pos);
              elseif x == 160
                  choices = [up,left];
                  pos = randi(2);
                  direction = choices(pos);
              else
                   choices = [up,left,right];
                   pos = randi(3);
                   direction = choices(pos);
              end
          end
      case left
          g.Matrix = makehgtform('translate',x,y,0);
          x = x-speed;
          if x == -3
              if y == -58
                  choices = [up,right];
                  pos = randi(2);
                  direction = choices(pos);
              elseif y == 107
                  choices = [down,right];
                  pos = randi(2);
                  direction = choices(pos);
              else
                  choices = [up,down,right];
                  pos = randi(3);
                  direction = choices(pos);
              end
          end
      case right
          g.Matrix = makehgtform('translate',x,y,0);
          x = x+speed;   
          if x == 160
              if y == -58
                  choices = [up,left];
                  pos = randi(2);
                  direction = choices(pos);
              elseif y == 107
                  choices = [down,left];
                  pos = randi(2);
                  direction = choices(pos);
              else 
                 choices = [up,down,left];
                 pos = randi(3);
                 direction = choices(pos);
              end
          end
  end
  
  drawnow
  a = a+1; 
end




% Add virtual boarder for operation area, reject all data outside (can't detect
% wall) based on known positions 

% Generate random start and finish location  

% Find ideal path withought obstacles 

% Place robot on start location with orientation ^, v, <, > 

% Manual control 

% Auto-pilot without prior knowledge of obstacles or learning

% Collect data from test 

% Alert when finished or stuck 