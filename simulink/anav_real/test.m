pos = [20 10];
theta = 0;
scale = 100;
goal = [35 10];
vehicleRad = 2;
mode = 0;
detectedList = scan_decoded;

[costs, mapGrid] = buildMapTest(pos, theta, detectedList, scale, goal, vehicleRad,...
                                        limit, mode);
                                    