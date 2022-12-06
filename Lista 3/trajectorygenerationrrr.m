%% CUBECOEF  
% Calcula os coeficientes do polinômio de terceiro grau descrito pelas
% posições e velocidades iniciais e finais de um determinado segmento,
% assim como a duração do segmento.
% 
%% Calling Syntax
% cc=cubcoef(th0,thdot0,thf,thdotf,T);
%
%% I/O Variables
% |IN 1 Double| *th0*: 
%
% |IN 2 Double| *thdot0*: 
%
% |IN 3 Double| *thf*: 
% 
% |IN 4 Double| *thdotf*: 
%
% |IN 5 Double| *T*: 
%
% |OUT 1 Double Array| *cc*: coeficientes da equação cúbica [a0 a1 a2 a3]
%
%% Example
%  
%
%% Hypothesis
% 
%
%% Limitations
% 
%
%% Function

function [thpath]=trajectorygenerationrrr(uform_vec, trelw, srelb, T, Ts)

L = [0.5 0.3];
thetalim = [-170 170;-170 170;-170 170];
srelb = utoi(srelb);
trelw = utoi(trelw);
start_point = kin([0 0 0],L);
goal = utoi(uform_vec(1,:));
[near,far,sol] = solve_robot(goal,start_point,trelw,srelb,L,thetalim);
traj_points = near;

for a = 1:length(uform_vec(:,1))-1  
    current = utoi(uform_vec(a,:));
    goal = utoi(uform_vec(a+1,:));
    [near,far,sol] = solve_robot(goal,current,trelw,srelb,L,thetalim);
    traj_points = [traj_points;near];
end

thpath = zeros((T/Ts)*(length(traj_points(:,1))-1),3,3);

for b = 1:3
    
    thpath(:,:,b)=trajectorygeneration(traj_points(:,b), T, Ts);
end

x = linspace(0,(length(traj_points(:,1))-1)*T, (length(traj_points(:,1))-1)*T/Ts);
subplot(3,1,1);
plot(x,thpath(:,1,1),x,thpath(:,1,2),x,thpath(:,1,3))
grid on
subplot(3,1,2);
plot(x,thpath(:,2,1),x,thpath(:,2,2),x,thpath(:,2,3))
grid on
subplot(3,1,3);
plot(x,thpath(:,3,1),x,thpath(:,3,2),x,thpath(:,3,3))
grid on
end