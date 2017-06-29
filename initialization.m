
%Initialize i-limb
copyfile('Nucleo_LDA.bin','e:/');    % Change the directory e:/ to the directory created when you plug in i-limb controller USB cable 

s = serial('COM6');   % Change to the corresponding serial port
set(s,'BaudRate',115200);  % BaudRate don't change
fopen(s);

beep;
display('Please turn off and on the power');    % You have to turn off the power and turn it on again. Once the light becomes green, it means the connection is sucessful
pause(5);

% The following commands are default to read set-up information set by iBT. The hand will rotate in one direction and then the other, and opens the palm and the closes.
tline = fgets(s)
tline = fgets(s)
fprintf(s,'y')
tline = fgets(s)
tline = fgets(s)
tline = fgets(s)


tline = fgets(s)
tline = fgets(s)
fprintf(s,'%s','0\r')
tline = fgets(s)
tline = fgets(s)
fprintf(s,'%s','c\r')
tline = fgets(s)
tline = fgets(s)
fprintf(s,'%s','o\r')
tline = fgets(s)
tline = fgets(s)
% 
% fprintf(s,'%s','d\r')
% 
% timer_period = 0.01;
% total_time_data_recording = 0.1;
% tasks_execute = total_time_data_recording/timer_period;
% t = timer('StartDelay', 0, 'Period', timer_period, 'TasksToExecute', tasks_execute, ...
%           'ExecutionMode', 'fixedRate');
% t.TimerFcn = @(x,y)gripper_read_data();
% start(t);

