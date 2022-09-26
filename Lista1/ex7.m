%% EX7  
%  Resolve os problemas demonstrados no exercicio 7 da lista
%% Code
L = [0.5 0.3];
srelb = utoi([-0.1, 0.3, 0]);
trelw = utoi([0.1 0.2 30]);

theta1 = [0 90 -90];

[trels] = where_robot(theta1,trelw,srelb,L);

disp("caso 1:");
disp(itou(trels));

theta2 = [-23.6 -30.3 48];

[trels] = where_robot(theta2,trelw,srelb,L);

disp('caso 2:');
disp(itou(trels));

theta3 = [130 40 12];

[trels] = where_robot(theta3,trelw,srelb,L);

disp('caso 3:');
disp(itou(trels));