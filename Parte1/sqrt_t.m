#Function that computes sin(x) 
#parameters: 
  # @x : preimage
#output: result of the operation sqrt_t(x)

#La función propuesta posee la siguiente propiedad: a^(1/2) = sqrt(a)
function [result] = sqrt_t(x)
  
  if (x == 0)
    result = 0
    return;
  
  elseif (x < 0)
    error('x value can`t be negative'); # non negative value validation
    return;
  else
     result = power_t(1/2,x);
  endif
  endfunction