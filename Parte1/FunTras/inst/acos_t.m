#Function that computes acos(x) 
#parameters: 
  # @x : preimage
#output: result of the operation arccos(x)
#restrictions: x must be part of range [-1,1]
function [result] = acos_t(x)
  pi_t = pi_t();
  result = pi_t / 2 - asin_t(x);
  