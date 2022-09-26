%% TINVERT
% Retorna o inverso de uma transformação homogênea
% 
%% Calling Syntax
% function [arelb] = tinvert(brela)
%
%% I/O Variables
% |IN Double Matrix| *brela*: B relative to A Homogeneous Transformation Matrix 4x4
%
% |OU Double Matrix| *arelb*: A relative to B Homogeneous Transformation Matrix 4x4
% 
%% Example
%  brela = [0.866 -0.5  0  11;
%           0.5  0.866  0  -1;
%           0  0  1  8;
%           0  0  0  1];
%  [arelb] = tinvert(brela);
%
%% Hypothesis
% Matrix de tranformação homogênea válida
%
%% Function
function [arelb] = tinvert(brela)
    arelb = [brela(1:3,1:3).' -(brela(1:3,1:3).')*brela(1:3,4); 0 0 0 1];
end