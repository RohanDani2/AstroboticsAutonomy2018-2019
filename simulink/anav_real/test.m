pos = [20 10];
theta = 0;
scale = 100;
goal = [70 30];
vehicleRad = 2;
detectedList = scan_decoded;

[costs, mapGrid] = buildMapTest(pos, theta, detectedList, scale, goal, vehicleRad,...
                                        limit, mode);
                                    