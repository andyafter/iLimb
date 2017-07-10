force_sensor = serial('COM6');

set(force_sensor, 'BaudRate', 115200);
fopen(force_sensor);
size = 100;

data = zeros(size,1);

for i = 1:size
    tline = fgets(force_sensor);
    data(i) = str2double(tline);
    disp(tline);
end

fclose(force_sensor);