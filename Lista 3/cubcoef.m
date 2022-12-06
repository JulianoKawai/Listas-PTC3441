%% CUBECOEF  
%  Calcula os coeficientes do polinômio de terceiro grau descrito pelas
%  posições e velocidades iniciais e finais de um determinado segmento,
%  assim como a duração do segmento.
% 
%% Calling Syntax
%  cc=cubcoef(th0,thdot0,thf,thdotf,T);
%
%% I/O Variables
%  |IN 1 Double| *th0*: joint angle at t=0 [deg]
%
%  |IN 2 Double| *thdot0*: joint angular velocity at t=0 [deg/s]
%
%  |IN 3 Double| *thf*:  joint angle at t=T [deg]
% 
%  |IN 4 Double| *thdotf*: joint angular velocity at t=T [deg/s]
%
%  |IN 5 Double| *T*: trajectory segment duration [seconds]
%
%  |OUT 1 Double Array| *cc*: cubic equation coefficients [a0 a1 a2 a3]
%
%% Example
%  th0 = 0;
%  thdot0 = 0;
%  thf = 4;
%  thdotf = 0;
%  T = 3;
%  [cc]=cubcoef(th0,thdot0,thf,thdotf,T);
%
%% Hypothesis
%  Calcula polinômio da tragetória de juntas rotacionais
%
%% Limitations
%  O polinômio é limitado a 4 coeficientes.
%  As posições e velocidades utilizadas devem ser referentes aos instantes 
%  t=0 e t=T, respectivamente.
%
%% Function

function [cc]=cubcoef(th0,thdot0,thf,thdotf,T)

a0 = th0;
a1 = thdot0;
a2 = (3/(T^2))*(thf-th0) - (2*thdot0/T)-(thdotf/T);
a3 = -(2/(T^3))*(thf-th0) + (thdotf+thdot0)/(T^2);
cc = [a0 a1 a2 a3];

end