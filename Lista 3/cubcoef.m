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
%  th0 = 0;
%  thdot0 = 0;
%  thf = 4;
%  thdotf = 0;
%  T = 3;
%  [cc]=cubcoefV1(th0,thdot0,thf,thdotf,T);
%
%% Hypothesis
%  Calcula polin�mio da traget�ria de juntas rotacionais
%
%% Limitations
%  o polin�mio � limitado a 4 coeficientes
%  exige raizes reais de do polin�mio
%
%% Function

function [cc]=cubcoef(th0,thdot0,thf,thdotf,T)

a0 = th0;
a1 = thdot0;
a2 = (3/(T^2))*(thf-th0) - (2*thdot0/T)-(thdotf/T);
a3 = -(2/(T^3))*(thf-th0) + (thdotf+thdot0)/(T^2);
cc = [a0 a1 a2 a3];

end