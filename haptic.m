haptic_sensor = serial('COM7');

set(haptic_sensor, 'BaudRate', 115200);
fopen(haptic_sensor);

for i = 1:1000
    tline = fgets(haptic_sensor);
    tline = fgets(haptic_sensor);
    disp(tline);
end

fclose(haptic_sensor);