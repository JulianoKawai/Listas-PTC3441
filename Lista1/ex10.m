%% EX10 
%  Resolve os problemas demonstrados no exercicio 10 da lista
%% Code
L = [0.5 0.3];
current = [0 0 0];
thetalim = [-170 170;-170 170;-170 170];
srelb = utoi([-0.1, 0.3, 0]);
trelw = utoi([0.1 0.2 30]);

goal1 = utoi([0, 0, -90]);

[near,far,sol] = solve_robot(goal1,current,trelw,srelb,L,thetalim);
disp('Solução primeira posição:');
disp(near);

current = near;
goal2 = utoi([0.6, -0.3, 45]);

[near,far,sol] = solve_robot(goal2,current,trelw,srelb,L,thetalim);
disp('Solução segunda posição:');
disp(near);

current = near;
goal3 = utoi([-0.4, 0.3, 120]);

[near,far,sol] = solve_robot(goal3,current,trelw,srelb,L,thetalim);
disp('Solução terceira posição:');
disp(near);

current = near;
goal4 = utoi([0.8, 1.4, 30]);

[near,far,sol] = solve_robot(goal4,current,trelw,srelb,L,thetalim);
disp('Solução quarta posição:');
disp(near);

