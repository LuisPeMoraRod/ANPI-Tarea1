#Function that computes the inverse of a number: x^1
#parameters: 
  # @x
#output: result of the operation x^-1
#restrictions: x must be different than zero
function [result] = div_t(x)
  tol = 1e-8; # generic tolerance defined for the package
  iterMax = 2500; # generic maximum iterations defined for the package
  a = x;

  #Function that returns x0 based on the value of @a
  #parameters:
    # @a
  #output: @x0
  function [x0]=get_x0 (a)
    if (factorial(0) < a <= factorial(20))
      x0 = eps^2;
    elseif (factorial(20) < a <= factorial(40))
      x0 = eps^4;
    elseif (factorial(40) < a <= factorial(60))
      x0 = eps^8;
    elseif (factorial(60) < a <= factorial(80))
      x0 = eps^11;
    elseif (factorial(80) < a <= factorial(100))
      x0 = eps^15;
    endif
  endfunction
  
  if (a == 0)
    error('x value can`t be zero'); # non zero value validation
    return;
  else
    [x_k] = get_x0(a); #define initial x value
    for k = 0 : iterMax -1
      x_kp1 = x_k * (2 - a * x_k); # defined succession for aproximation
      error = abs(x_kp1 - x_k); # error calculation
      x_k = x_kp1;
      if (error < tol * abs(x_kp1)) # stop condition
        break;
      endif
    endfor
    result = x_kp1;
  endif
endfunction
