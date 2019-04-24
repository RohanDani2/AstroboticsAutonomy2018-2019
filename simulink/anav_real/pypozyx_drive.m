clear classes
clf
mod = py.importlib.import_module('pypozyx_test');
py.importlib.reload(mod)

local = py.pypozyx_test.init;
py.pypozyx_test.setup(local)

runtime = 10; % seconds
xyz = struct('x', nan(1, runtime*100*2), 'y', nan(1, runtime*100*2), 'z', nan(1, runtime*100*2));
xyz.x(1) = 0; xyz.y(1) = 0; xyz.z(1) = 0;
avd = struct('a', xyz, 'v', xyz, 'd', xyz);
emptys = 0;
total = tic;
idx = 2;
t = tic;
while (toc(total) < runtime)
    dt = toc(t);
    t = tic;
    fprintf("dt: %fms\n", dt*1000);
    data = py.pypozyx_test.run_once(local);
    if (~py.pypozyx_test.is_none(data))
        a = data.linear_acceleration;

        avd.a.x(idx) = a.x;  
        avd.a.y(idx) = a.y;  
        avd.a.z(idx) = a.z; 
        
        avd.v.x(idx) = a.x*dt + avd.v.x(idx - 1); 
        avd.v.y(idx) = a.y*dt + avd.v.y(idx - 1); 
        avd.v.z(idx) = a.z*dt + avd.v.z(idx - 1);   
        
        avd.d.x(idx) = avd.v.x(idx)*dt + avd.d.x(idx - 1); 
        avd.d.y(idx) = avd.v.y(idx)*dt + avd.d.y(idx - 1); 
        avd.d.z(idx) = avd.v.z(idx)*dt + avd.d.z(idx - 1);
        
        subplot(3,1,1)
        hold on
        %xlim([-500 500]); ylim([-500 500]); zlim([-500 500]);
        plot3(avd.d.x(1:idx), avd.d.y(1:idx), avd.d.z(1:idx), 'b.-')
        hold off
        
        subplot(3,1,2)
        hold on 
        plot(avd.a.x, 'r')
        plot(avd.a.y, 'g')
        plot(avd.a.z, 'b')
        hold off
        
        subplot(3,1,3)
        hold on 
        plot(avd.v.x, 'r')
        plot(avd.v.y, 'g')
        plot(avd.v.z, 'b')
        hold off 
        
        drawnow
    else
        emptys = emptys + 1;
    end
    idx = idx + 1;
end
