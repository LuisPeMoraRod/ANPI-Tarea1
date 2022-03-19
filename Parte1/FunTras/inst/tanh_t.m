#Function that computes tanh(x) 
#parameters: 
  # @x : preimage
#output: result of the operation tanh(x)
function [result] = tanh_t(x)
  a = sinh_t(x);
  b = cosh_t(x);
  result = a / b;