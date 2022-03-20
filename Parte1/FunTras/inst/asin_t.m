#Function that computes asin(x) 
#parameters: 
  # @x : preimage
#output: result of the operation arcsin(x)
#restrictions: x must be part of range [-1,1]
function [result] = asin_t(x)
  tol = 1e-8; # generic tolerance defined for the package
  iterMax = 2500; # generic maximum iterations defined for the package
  a = x;
  max_den = factorial(100); # maximum denominator accepted by div_t

  function [s_k] = get_S_k(n) 
    denom = 4^(n)*(factorial(n))^(2)*(2*n + 1);
    s_k = (factorial(2*n)*div_t(denom))*a^(2*n + 1); # defined succession for aproximation
  endfunction
  
  if or(x < -1, x > 1)
    error('x value out of dominium, must be part of range [-1,1]'); # non zero value validation
    return;
  else
    s_k = get_S_k(0); #initial S_0
    for n = 1 : iterMax -1
      denom = 4^(n)*(factorial(n))^(2)*(2*n + 1);
      if denom > max_den # stop condition for maximum denominator value supported by div_t
        break;
      end
      s_kp1 = s_k + get_S_k(n); #sum of last value and new value of the iteration
      error = abs(s_kp1 - s_k); # error calculation
      s_k = s_kp1;
      if (error < tol ) # stopping condition
        break;
      endif
    endfor
  endif
  result = s_k;
  endfunction