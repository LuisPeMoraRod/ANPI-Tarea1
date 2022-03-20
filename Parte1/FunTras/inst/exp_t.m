#Function that computes the exponential of base e for a given number.
#parameters: 
  # @x : preimage
#output: result of the operation e^x
function [result] = exp_t(x)
  tol = 1e-8; # generic tolerance defined for the package
  iterMax = 2500; # generic maximum iterations defined for the package
  a = x;
  max_den = factorial(100); # maximum denominator accepted by div_t
  
  function [s_k] = get_S_k(n)
    s_k = a^(n) * div_t(factorial(n)); # defined succession for aproximation
  endfunction
 
  s_k = get_S_k(0); #define initial x value
  for n = 1 : iterMax -1
    if factorial(n) > max_den # stop condition for maximum denominator value supported by div_t
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

