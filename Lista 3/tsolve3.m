%% TSOLVE3
%  Converte o formato das entrada de dados do usuário
%  $(x,y,\theta)$
%  para o formato interno (matriz de transformação homogênea)
%  para um manipulador RRR planar. Então realiza a inversão das matrizes de  
%  transformação que estiverem invertidas e, por fim, multiplica elas de
%  forma a obter a matriz de transformação equivalente, que é impresso na 
%  janela de comando, e em seguida retorná-la em formato de usuário. 
% 
%% Calling Syntax
%  crelb=tsolve3(crelu,urela,arelb,is_inv);
%
%% I/O Variables
%  |IN 1 Double Array| *crelu*: _C relative to U_  _User form_  [x y theta]
%  |IN 2 Double Array| *urela*: _U relative to A_  _User form_  [x y theta]
%  |IN 3 Double Array| *arelb*: _A relative to B_  _User form_  [x y theta]
%  |IN 4 Int Array| *is_inv*: _is [crelu,urela,arelb] inverted?_ 1 if true,
% 0 if false
%
%  |OUT 2 Double Array| *crelb*: _C relative to B_ _User form_  [x y theta]
%
%% Example
%  crelb = tsolve3([-3 -3 -30],[11 -1 30],[0 7 45],[1 1 0]);
%
%% Hypothesis
%  Robô RRR planar. As 3 matrizes de transformação homogênea devem
%  representar o o sistema intermediário em relação aos 2 sistemas da
%  transformação equivalente.
%
%% Limitations
%  A "Forma do usuário" é específica para o exercício de simulação e não tem
%  validade para qualquer configuração de robô. As matrizes de transformação
%  devem estar ordenadas e a necessidade de inversão de cada uma delas deve
%  ser conhecida.
%
%% Function
function [crelb]=tsolve3(crelu,urela,arelb,is_inv)
    crelu = utoi(crelu);
    urela = utoi(urela);
    arelb = utoi(arelb);
    if is_inv(1) == 1
        crelu = tinvert(crelu);
    end
    if is_inv(2) == 1
        urela = tinvert(urela);
    end
    if is_inv(3) == 1
        arelb = tinvert(arelb);
    end
    crela = tmult(urela,crelu);
    crelb = tmult(arelb,crela);
    disp(crelb);
    crelb = itou(crelb);
end