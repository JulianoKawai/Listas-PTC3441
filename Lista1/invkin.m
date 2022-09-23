function [near,far,sol]=invkin(wrelb,current,L,thetalim)
    sol = 0;
    coord = itou(wrelb);
    c2 = (coord(1)^2 + coord(2)^2 - L(1)^2 - L(2)^2)/(2*L(1)*L(2));
    coord(3) =  coord(3)*pi()/180;
    s2 = [sqrt(abs(1-c2^2)) -sqrt(abs(1-c2^2))];
    display(s2);
    k1 = L(1) + L(2)*c2;
    k2 = L(2)*s2;
    gamma = atan2(k2,k1);
    theta2 = atan2(s2,c2);
    theta1 = atan2(coord(2),coord(1)) - gamma;
    theta3 = coord(3) - theta1 - theta2;
    theta1 = theta1*180/pi();
    theta2 = theta2*180/pi();
    theta3 = theta3*180/pi();
    display(theta1);
    display(theta2);
    display(theta3);
    if thetalim(1,1) < theta1(1) && theta1(1) < thetalim(1,2)
        if thetalim(2,1) < theta2(1) && theta2(1) < thetalim(2,2)
            if thetalim(3,1) < theta3(1) && theta3(1) < thetalim(3,2)
                sol = 1;
            end
        end  
    end
    if thetalim(1,1) < theta1(2) && theta1(2) < thetalim(1,2)
        if thetalim(2,1) < theta2(2) && theta2(2) < thetalim(2,2)
            if thetalim(3,1) < theta3(2) && theta3(2) < thetalim(3,2)
                sol = 1;
            end
        end  
    end
    if abs(current(1) - theta1(1)) > abs(current(1) - theta1(2))
        near = [theta1(2) theta2(2) theta3(2)];
        far = [theta1(1) theta2(1) theta3(1)];
    else
        near = [theta1(1) theta2(1) theta3(1)];
        far = [theta1(2) theta2(2) theta3(2)];    
    end
end