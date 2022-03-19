 #Function that computes the testing script indicated in the tarea 1 documment.
#parameters: No parameters
#output: result of some testing fuctions built in this packaged.
#restrictions: N/A
function [result] = test_funtras()
  g = 3*div_t(7);           
  h = sqrt_t(2);
  a = sin_t(g);
  b = ln_t(2.0);
  c = root_t((a+b), 3.0);
  d = sinh_t(h);
  e = c*div_t(d);
  d = exp_t(-1.0);
  f = atan_t(d);
  result = e + f;
endfunction