#Function that computes the 'a' root of a number 'x'

#parameters:
  # @x : number which root will be computed
  # @a : root

#output: 'a' root of 'x'
#restriction: 0 <= x

function [result] =  root_t(x,a)
  tol = 1e-8; # generic tolerance defined for the package
  iterMax = 2500; # generic maximum iterations defined for the package
  
  if x < 0
    error("x value cant be negative");
  else
    a_nr = x; # 'a' parametpier for Newton-Raphson method
    p_nr = a; # 'p' parameter for Newton-Raphson method
    
    syms x; # x variable for Newton-Raphson method
    x_0 = a_nr / 2; # initial value
    
    result = newton_raphson(x^(p_nr) - a_nr, x_0, tol, iterMax);
  end  
  endfunction