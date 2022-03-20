#Function that computes the 'a' root of a number 'x'

#parameters:
  # @x : number which root will be computed
  # @a : root

#output: 'a' root of 'x'
#restriction: x must a positive number for even roots

function [result] =  root_t(x,a)
  pkg load symbolic
  tol = 1e-8; # generic tolerance defined for the package
  iterMax = 2500; # generic maximum iterations defined for the package
  
  function [even] = is_even(n) # checks if number is even or odd 
    toggle_num = (-1)^(n);
    if toggle_num == -1
      even = false;
    else
      even = true;
    end   
  end
 
  if and(is_even(a), x < 0)
    error("x value for even roots can't be negative");
  else
    a_nr = x; # 'a' parametpier for Newton-Raphson method
    p_nr = a; # 'p' parameter for Newton-Raphson method
    
    syms x; # x variable for Newton-Raphson method
    x_0 = a_nr / 2; # initial value
    
    result = newton_raphson(x^(p_nr) - a_nr, x_0, tol, iterMax);
  end  
  endfunction