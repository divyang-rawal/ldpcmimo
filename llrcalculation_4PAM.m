%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%% LLR calculation Example for 4 PAM %%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%% Prepared By : D.Rawal (Team LNMIIT)%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%% Date : 27/03/2020 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clc;
clear all;
close all;

N = 10^4;
M_ary = 2;
x1 = randi(2,1,2*N)-1;

%%% Bitmaps =       [ 00,   01,   11,   10 ]
Const = (1/sqrt(5))*[-3,-1,1,3];
snr = [0:20];

for ind = 1:length(snr)
   snrdB = snr(ind); 
k = 1;
for i = 1:N
    if( (x1(k) == 0 ) && ( x1(k+1) == 0 ) )
    x(i) = Const(1);%-3;
    elseif( (x1(k) == 0 ) && ( x1(k+1) == 1 ) )
    x(i) = Const(2);%-1;
    elseif( (x1(k) == 1 ) && ( x1(k+1) == 1 ) )
    x(i) = Const(3);%1;
    else
    x(i) = Const(4);%3;
    end; 
    k = k+2;
end;

snrlin = 10^(snrdB/10);
noise = (1/sqrt(snrlin))*(1/sqrt(2))*complex(randn(1,N),randn(1,N));
y = x + 1*noise;

k=1;
for i=1:N
    if(y(i) < (-2/sqrt(5)))
        Det(k) = 0;
        Det(k+1) = 0;
    elseif((y(i) >= (-2/sqrt(5))) &&(y(i) < 0))
        Det(k) = 0;
        Det(k+1) = 1;
    elseif((y(i) >= 0) && (y(i) < (2/sqrt(5))))
        Det(k) = 1;
        Det(k+1) = 1;
    else
        Det(k) = 1;
        Det(k+1) = 0;
    end;
    k = k+2;
end;

k=1;
for i=1:N
    Symbol_err(i) = ( (abs(Det(k) - x1(k))) || (abs(Det(k+1) - x1(k+1)) ));
    k=k+2;
end;

Symerr(ind) = sum(Symbol_err)/N

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%% LLR calculation %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%  Mapping is like bit2,bit1 = 11 or 01 or 00 or 10 %%%%%%%%%%%%%%%%%%%%%
LLRBitstream = [];
for i=1:N
%LLR_bit1(i) = log( ((exp(-((y(i)-(1/sqrt(5)))^2))) + (exp(-((y(i)+(1/sqrt(5)))^2)))) / ((exp(-((y(i)-(3/sqrt(5)))^2))) + (exp(-((y(i)+(3/sqrt(5)))^2)))) ); 
%LLR_bit2(i) = log( ((exp(-((y(i)-(1/sqrt(5)))^2))) + (exp(-((y(i)-(3/sqrt(5)))^2)))) / ((exp(-((y(i)+(1/sqrt(5)))^2))) + (exp(-((y(i)+(3/sqrt(5)))^2)))) );

%ynorm = sqrt(5)*y;
%LLR_bit1(i) = log( ((exp(-((-2*ynorm(i)+(1))))) + (exp(-((2*ynorm(i)+(1)))))) / ((exp(-((-6*ynorm(i)+(9))))) + (exp(-((6*ynorm(i)+(9)))))) ); 
%LLR_bit2(i) = log( ((exp(-((-2*ynorm(i)+(1))))) + (exp(-((-2*ynorm(i)+(9)))))) / ((exp(-((2*ynorm(i)+(1))))) + (exp(-((6*ynorm(i)+(9)))))) );

ynorm = sqrt(5)*y;
if(ynorm(i) < -2)
    LLR_bit1(i) = 2*ynorm(i)+4;
    LLR_bit2(i) = 2*(ynorm(i)+1);
elseif((ynorm(i) >= -2) && (ynorm(i) < 0))
    LLR_bit1(i) = 2*ynorm(i)+4;
    LLR_bit2(i) = 1*ynorm(i);
elseif((ynorm(i) >= 0) && (ynorm(i) < 2))
    LLR_bit1(i) = -2*ynorm(i)+4;
    LLR_bit2(i) = 1*ynorm(i);
else
    LLR_bit1(i) = -2*ynorm(i)+4;
    LLR_bit2(i) = 4*(ynorm(i)-1);
end;    

LLRBitstream = [LLRBitstream,LLR_bit2(i),LLR_bit1(i)];
end;

DetectLLR = (LLRBitstream > 0);

k=1;
for i=1:N
    LLRSymbol_err(i) = ( (abs(DetectLLR(k) - x1(k))) || (abs(DetectLLR(k+1) - x1(k+1)) ));
    k=k+2;
end;

LLRSymerr(ind) = sum(LLRSymbol_err)/N

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

end;

theo = 0.75*erfc(sqrt(0.2*(10.^(snr/10))));
semilogy(snr,Symerr,'-+',snr,theo,'-o',snr,LLRSymerr,'->');
grid on;

