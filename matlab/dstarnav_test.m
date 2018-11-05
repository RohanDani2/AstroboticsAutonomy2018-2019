%%begin

% Our robot will operate within a grid world that contains free
% space where it can drive and obstacles.  We load a map of the world
%load map1
% which loads a variable called map

map = initDstarMap();
map = accumarray([map(:,2),map(:,1)],1,[36 57]);
about map
% The elements of the obstacle map are converted into traversibility values, an
% obstacle has an infinite traversibility while free space has a nominal
% travesibility of 1.

% Now we create an instance of a robot with the D* navigation algorithm
dstar = Dstar(map, 'quiet');

% Now we define the goal and start coordinates
goal = [randi([2,56]),randi([30,35])];
start = [randi([2,56]),randi([2,5])];

% then ask the robot to plan a path to goal (it will take few seconds)
tic; dstar.plan(goal); toc

% Now we can display the obstacles and the cost to reach the goal from every
% point in the world
dstar.plot()
% where the cost scale is shown by the bar to the right.

% Now we can execute the planned path, it will be animated with green dots
dstar.query(start, 'animate')

% Now lets change the difficulty of some of the terrain, make it more costly
% to travese
for r=10:15
    for c=10:15
        dstar.modify_cost([c; r], inf); 
    end
end

% Now we can replan, but D* does this in an incremental way which is faster than
% recomputing the whole plan from scratch
tic; dstar.plan(); toc
% that took less time than before...

% and the best path is now
dstar.query(start, 'animate')
% we can see that the path has avoided the high cost region we added
