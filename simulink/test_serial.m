port_arduino_motors = '/dev/ttyACM0';
global COM_arduino_motors

if ~isempty(COM_arduino_motors)
    fclose(COM_arduino_motors);
    delete(COM_arduino_motors) 
end

COM_arduino_motors = serial(port_arduino_motors);
set(COM_arduino_motors, 'Timeout', 10)
set(COM_arduino_motors, 'BaudRate', 115200)
COM_arduino_motors.Terminator = {'CR/LF', 0};

fopen(COM_arduino_motors);