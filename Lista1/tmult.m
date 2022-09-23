%% TMULT   
% Multiplica duas matrizes de transforma��o com um sistema de coordenadas
% em comum, obtendo a matriz de transforma��o equivalente. 
% 
%% Calling Syntax
% crela=tmult(brela,crelb)
%
%% I/O Variables
% |IN 1 Double Matrix| *brela*: _B relative to A_  Homogeneous Transformation Matrix 4x4
% |IN 2 Double Matrix| *crelb*: _C relative to B_  Homogeneous Transformation Matrix 4x4
% 
% |OUT Double Matrix| *crela*: _C relative to A_  Homogeneous Transformation Matrix 4x4
%
%% Example
%  brela = [0 -1  0  1;
%           1  0  0  0;
%           0  0  1  0;
%           0  0  0  1];
%  crelb = [0.7071   0.7071  0  1;
%           -0.7071  0.7071  0  2;
%           0        0       1  0;
%           0        0       0  1];
%  crela = tmult(brela,crelb);
%
%% Hypothesis
% As duas matrizes de transforma��o homog�nea s�o de mesma dimens�o.
%
%% Limitations
% As duas matrizes de entrada devem ser as transforma��es homog�neas do "sistema de coordenadas 1"
% para o "sistema de coordenadas 2" e do "sistema de coordenadas 2" para o
% "sistema de coordenadas 3", respectivamente.
%
%% Function
function [crela]=tmult(brela,crelb)
    crela = brela*crelb;
end