# Function that returns an aproximation of Pi based Ramanujan formula
# which is an aproximation that converges way more faster than other aproximations
function [pi_result] = pi_t()
  #Series constants
  k1 = 545140134;
  k2 = 13591409;
  k3 = 640320;
  k4 = 100100025;
  k5 = 327843840;
  k6 = 53360;
  
  iter = 5; #number of iterations for the series
  
  function [S] = get_S(k)
    S = 0;
    for n = 0 : k
      S = S + (-1)^n * factorial(6*n) * (k2 + n*k1) * div_t(factorial(n)^3 * factorial(3*n) * (8*k4*k5)^n);
    end
    endfunction
    
  S = get_S(iter);
  pi_result = k6 * root_t(k3, 2) * div_t(S); #pi formula
  
  endfunction