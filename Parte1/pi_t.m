# Function that returns an aproximation of Pi based Ramanujan formula
# which is an aproximation that converges way more faster than other aproximations
function [pi_result] = pi_t()
  pkg load symbolic
  tol = 1e-8; # generic tolerance defined for the package
  iterMax = 2500; # generic maximum iterations defined for the package
  
  #Series constants
  k1 = 545140134;
  k2 = 13591409;
  k3 = 640320;
  k4 = 100100025;
  k5 = 327843840;
  k6 = 53360;

  function [s_k] = get_S(n) #Returns n value of the series used as the denominator value of the expression that defines pi
    s_k = (-1)^n * factorial(6*n) * (k2 + n*k1) * div_t(factorial(n)^3 * factorial(3*n) * (8*k4*k5)^n);
  endfunction
  
  function [pi_k] = get_pi(s_k) # compute pi
    pi_k = k6 * root_t(k3, 2) * div_t(s_k); #pi formula
  endfunction
  
  s_k = get_S(0); #initial S0
  pi_k = get_pi(s_k); #inital pi value
  
  for n = 1 : iterMax - 1
    s_k = s_k + get_S(n); #sum of last value and new value of the iteration
    pi_kp1 = get_pi(s_k); #pi value calculation
    error = abs(pi_kp1 - pi_k); #error calculation
    pi_k = pi_kp1;
    if (error < tol)
      n
      break;
    end
  end
  pi_result = pi_k;
  endfunction