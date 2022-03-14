#Function that computes tan(x) 
#parameters: 
  # @x : preimage
#output: result of the operation tan(x)
#restrictions: x must be different than a multiple of +-pi/2
function [result] = tan_t(x)
  a = sin_t(x);
  b = cos_t(x);
  if abs(b) < 1e-10
    error('x must be different than a multiple of +-pi/2');
  end
  result = a / b;