#Function that computes the logarithm based 'a' of x 
#parameters: 
  # @x : preimage
  # @a : base
#output: result of the operation log_a(x)
#restrictions: a and x values must be greater than 0
function [result] = log_t(x,a)
  if (x <= 0)
    error('x value out of dominium'); # non zero value validation
  elseif (a <= 0)
    error('a value out of dominium'); # non zero value validation
  endif
  num = ln_t(x);
  den = ln_t(a);
  result = num / den;