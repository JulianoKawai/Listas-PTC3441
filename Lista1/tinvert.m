function [arelb]=tinvert(brela)
    arelb = [brela(1:3,1:3).' -brela(1:3,1:3).'*brela(1:3,4); 0 0 0 1];
end