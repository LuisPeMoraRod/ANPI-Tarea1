#Function that computes power(x,a) 
#parameters: 
  # @a : base
  # @x : power
#output: result of the 'x' power of 'a'
#restrictions: 'a' must be part of R+

#The proposed function has the following logarithmic property: log_a(a^x )=x
#We also know that log_a(x)=ln(x)/ln(a)
#Then, we can state that: log_a(a^x )= x = ln(a^x )/ln(a)
#  ln(a^x )=x*ln(a)
#Applying exponential to both sides: a^x=e^(x*ln(a))
function [result] = power_t(x,a)
  result = exp_t(x*ln_t(a));
  endfunction