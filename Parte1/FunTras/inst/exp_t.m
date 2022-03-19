#Function that computes the exponential of base e for a given number.
#parameters: 
  # @x : preimage
#output: result of the operation e^x
function [result] = exp_t(x)
  tol = 1e-8; # generic tolerance defined for the package
  iterMax = 2500; # generic maximum iterations defined for the package
  a = x;
  
  #Function that returns s_k based on a for the value of n
  #parameters:
    # @n : preimage
  #output: @s_k
  function [s_k] = get_S_k(n)
    s_k = a^(n) * div_t(factorial(n)); # defined succession for aproximation
  endfunction
  
  max_den = factorial(100); # maximum denominator accepted by div_t
  s_k = get_S_k(0); #define initial x value
  for n = 1 : iterMax -1
    if factorial(n) > max_den
      break;
    end
    s_kp1 = s_k + get_S_k(n); # defined succession for aproximation
    error = abs(s_kp1 - s_k); # error calculation
    s_k = s_kp1;
    if (error < tol) # stop condition
      break
    endif
  endfor
  result = s_k;
  endfunction

