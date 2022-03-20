#Function that computes the logarithm based 'a' of x 
#parameters: 
  # @x : preimage
  # @a : base
#output: result of the operation log_a(x)
#restrictions: dominium of x is R+ and base should be part of R+ except 1
function [result] = log_t(x,a)
  if (x <= 0)
    error('x value out of dominium'); # non zero value validation
  elseif or(a <= 0, a == 1)
    error('invalid base'); # base value validation
  endif
  num = ln_t(x);
  den = ln_t(a);
  result = num / den;