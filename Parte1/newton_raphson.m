%Function that computes the zero of a given function based on the Newton-Raphson method

%parameters:
% f = function (as a string)
% x0 = starting x point
% tol = tolerance
% iterMax = max number of iterations

%outputs:
% x_k = aproximated zero
% error = final error
% k = number of iterations executed
function [x_k]= newton_raphson(f_in, x0, tol, iterMax)

pkg load symbolic

syms x; 
f_sym = sym(f_in); %numeric to symbolic function
f_prime_sym = diff(f_sym, x); % function derivate in terms of x

f = matlabFunction(f_sym); %symbolic to numeric representation
f_prime = matlabFunction(f_prime_sym);

x_k = x0;

for k=0 : iterMax -1 
  if abs(f_prime(x_k)) < 1e-15 
    error('derivate evaluated in x_%d = %.4f equals to zero', k, x_k);
    break;
  else
    x_kp1 = x_k - f(x_k)/f_prime(x_k); %Newton-Raphson iterative formula
    error = abs(x_kp1 - x_k); % relative error
    x_k = x_kp1;
    if error < tol * abs(x_kp1);
      break;
    end
  end
end


