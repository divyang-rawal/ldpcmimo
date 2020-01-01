%LDPC Decoder Using Minsum Algorithm%
%LNMIIT%
%27/12/2019%

clc;
clear all;
close all;
% LLR = [0.2 -0.3 1.2 -0.5 0.8 0.6 -1.1];   %% Receivd codeword
 LLR = [0.4281 1.5147 -0.4577 0.3089 -0.6264 1.9481 -0.0228] %%%%  take received code word (LLR) of length 1X7.
Base_Mat = [1 1 1 0 1 0 0  ;    
            0 1 1 1 0 1 0  ;
            1 1 0 1 0 0 1  ;
            1 0 1 0 1 1 1] ;
[m,n] = size(Base_Mat);     
itermax = 1;        %%% No. of Iterations.
for iter = 1:itermax
    L_M = [];
r_new = LLR;
for i = 1:m
    L(i,:) = r_new.*Base_Mat(i,:); %In first iteration take LLR as received code word and multiply with base matrix
    Sgn(i,:) = sign(L(i,:));      %% Observe sign of the each row.
end;

for i=1:m
    for j = 1:n
    if(L(i,j) == 0)               %%% lets replace zeros with 100 (higher valus) to avoid 0 to be minimum
        L(i,j) = 100;
    end;
    end;
end;

for i = 1:m     %row-wise operation
    S = prod(sign(L(i,:)));    %%%take product of sign of all the elements 
    [Lmin1(i),Pos1(i)] = min(abs(L(i,:))); %% find 1st minimum value and postion from the row.
    Lmin1(i) = L(i,Pos1(i));       
    Temp = L(i,Pos1(i));
    L(i,Pos1(i)) = 100;        %%replace minimum value with 100
    [Lmin2(i),Pos2(i)] = min(abs(L(i,:)));   %%find 2nd minimum values and postion from the same row.
    Lmin2(i) = L(i,Pos2(i));   
    L(i,Pos1(i)) = Temp;    
    for j =1:n
        if(j == Pos1(i))
          L(i,j) = Lmin2(i);  %%%place 2nd min value at the postion of 1st minimum
        else
            if(L(i,j)~=100)   %%% values which are not equal to 100, replace them with 1st min value
               L(i,j) = Lmin1(i);
            end;
        end;        
    end;
    L(i,:) = abs(L(i,:));
    if(S == -1)               
       L(i,:) = ((S.*Sgn(i,:)).*(L(i,:)));  %multiplying parity S with the old sign of the elemetns 
    else
       L(i,:) = (Sgn(i,:)).*(L(i,:));
    end;
end;
%%%%%%%%%%%%Extrinsic from Repetition code %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
L = L.*Base_Mat;
L_Matrix = L;
L_M = [L_M ; L_Matrix]
for i =1:n
    LLR(i) = r_new(i) + sum(L_M(:,i))   % New LLR values, adding elements coloumn-wise
end;
LLR>0  %Thresholding
end;