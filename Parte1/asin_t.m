#Function that computes asin(x) 
#parameters: 
  # @x : preimage
#output: result of the operation arcsin(x)
function [result] = asin_t(x)
  tol = 1e-8; # generic tolerance defined for the package
  iterMax = 2500; # generic maximum iterations defined for the package
  a = x;
  
  #Function that returns s_k based on a for the value of n
  #parameters:
    # @n : preimage
  #output: @s_k
  function [s_k] = get_S_k(n) 
    denominador = 4^(n)*factorial(n)^(2)*(2*n + 1);
    s_k = (factorial(2*n)*div_t(denominador))*a^(2*n + 1); # defined succession for aproximation
  endfunction
  
  if or(x <= -1, x >= 1)
      error('x value out of dominium'); # non zero value validation
    return;
  else
    s_k = get_S_k(0); #initial S_0
    for n = 1 : iterMax -1
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