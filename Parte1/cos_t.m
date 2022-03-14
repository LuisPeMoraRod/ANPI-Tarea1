#Function that computes cos(x) 
#parameters: 
  # @x : preimage
#output: result of the operation cos(x)
function [result] = cos_t(x)
  tol = 1e-8; # generic tolerance defined for the package
  iterMax = 2500; # generic maximum iterations defined for the package
  a = x;
  
  #Function that returns s_k based on a for the value of n
  #parameters:
    # @n : preimage
  #output: @s_k
  function [s_k] = get_S_k(n)
    s_k = (-1)^n * a^(2*n) * div_t(factorial(2*n)); # defined succession for aproximation
  endfunction
  
  s_k = get_S_k(0); #initial S_0
  for n = 1 : iterMax -1
      s_kp1 = s_k + get_S_k(n); #sum of last value and new value of the iteration
      error = abs(s_kp1 - s_k); # error calculation
      s_k = s_kp1;
      if (error < tol ) # stopping condition
        break;
      endif
    endfor
  result = s_k;
  endfunction