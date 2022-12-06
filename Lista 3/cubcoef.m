%% CUBECOEF  
% Calcula os coeficientes do polinômio de terceiro grau descrito pelas
% posições e velocidades iniciais e finais de um determinado segmento,
% assim como a duração do segmento.
% 
%% Calling Syntax
% cc=cubcoef(th0,thdot0,thf,thdotf,T);
%
%% I/O Variables
% |IN 1 Double| *th0*: posição $\theta$ no instante inicial $t=0$ do
% segmento [deg]
%
% |IN 2 Double| *thdot0*: velocidade $\dot{\theta}$ no instante inicial
% $t=0$ do segmento [deg/s]
%
% |IN 3 Double| *thf*: posição $\theta$ no instante final $t=T$ do segmento
% [deg]
% 
% |IN 4 Double| *thdotf*: velocidade $\dot{\theta}$ no instante final $t=T$
% do segmento [deg/s]
%
% |IN 5 Double| *T*: duração do segmento da trajetória [seg]
%
% |OUT 1 Double Array| *cc*: coeficientes da equação cúbica [a0 a1 a2 a3]
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