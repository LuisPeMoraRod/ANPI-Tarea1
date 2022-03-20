#Function that computes sin(x) 
#parameters: 
  # @x : preimage
#output: result of the operation sin(x)
function [result] = sin_t(x)
  tol = 1e-8; # generic tolerance defined for the package
  iterMax = 2500; # generic maximum iterations defined for the package
  a = rebase_x(x);
  
  # Function that converts a number to its equivalent in the range of [0, 2pi] or [-2pi, 0] (for negative values)   
  function [x_rebased] = rebase_x(x)
    is_negative = false;
    if x < 0 #sign validation
      is_negative = true;
      x = abs(x);
    end
    n = 1;
    two_pi = 2*pi_t();
    while x * div_t(n*two_pi) > 1 #find the biggest multiple of 2pi that fits in x
      n += 1;
    end
    x_rebased = x - (n-1)*two_pi; #convert x in a number in range [0, 2pi]
    if is_negative
      x_rebased = -1 * x_rebased; #convert to negative if required
    end
  end
  
  function [s_k] = get_S_k(n)
    s_k = (-1)^n * a^(2*n+1) * div_t(factorial(2*n+1)); # defined succession for aproximation
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