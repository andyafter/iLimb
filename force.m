force_sensor = serial('COM6');

set(force_sensor, 'BaudRate', 115200);
fopen(force_sensor);

% stores all the data
dat = [];

for i = 1:1000
    tline = fgets(force_sensor);
    disp(tline);
end

fclose(force_sensor);