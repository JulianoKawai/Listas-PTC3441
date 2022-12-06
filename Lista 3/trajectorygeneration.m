%% CUBECOEF  
% Calcula os coeficientes do polin�mio de terceiro grau descrito pelas
% posi��es e velocidades iniciais e finais de um determinado segmento,
% assim como a dura��o do segmento.
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
% |OUT 1 Double Array| *cc*: coeficientes da equa��o c�bica [a0 a1 a2 a3]
%
%% Example
%  
%
%% Hypothesis
% 
%
%% Limitations
%  T deve ser divis�vel por Ts
%
%% Function

function [thpathi]=trajectorygeneration(traj_points, T, Ts)

cctot = trajectoryplanning(traj_points,T);
thpathi = zeros([(T/Ts)*length(cctot(:,1)),3]);
pps = T/Ts;

for a=1:length(cctot(:,1))
    for b=1:pps
        td = (b-1)*Ts;
        thpathi((a-1)*pps+b,1) = cctot(a,1) + cctot(a,2)*td + cctot(a,3)*td^2 + cctot(a,4)*td^3; 
        thpathi((a-1)*pps+b,2) = cctot(a,2) + 2*cctot(a,3)*td + 3*cctot(a,4)*td^2;
        thpathi((a-1)*pps+b,3) = 2*cctot(a,3) + 6*cctot(a,4)*td;
    end  
end
end