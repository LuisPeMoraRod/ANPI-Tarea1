#Function that computes sin(x) 
#parameters: 
  # @x : preimage
#output: result of the operation power_t(x,a)

#La funci�n propuesta posee la siguiente propiedad logar�tmica: log_a(a^x )=x
#Tambi�n se sabe que: log_a(x)=ln(x)/ln(a)
#Entonces: log_a(a^x )=x=ln(a^x )/ln(a).....x=ln(a^x )/ln(a)
#Despejando ln(ax): ln(a^x )=x�ln(a)
#Aplicando exponencial a ambos lados:  a^x=e^(x�ln(a) )
#Donde, ya se tienen funciones definidas para el exponencial de un n�mero
#y el logaritmo natural de un n�mero
function [result] = power_t(x,a)
  result = exp_t(x*ln_t(a));
  endfunction