from metodos_p2 import *

def p_newton_G_m1():
    f_prueba = 'cos(x)-x'
    n_metodo = "Halley"
    print("La función a la que se le calculara el cero es:",f_prueba)
    print("El método usado es: ",n_metodo)
    print("La aproximacion de la solucion es: xk = ",newton_G_m1(f_prueba,1,10**-5,500)[0])
    print("El error es: ",newton_G_m1(f_prueba,1,10**-5,500)[1])

def p_newton_G_m2():
    f_prueba = 'cos(x)-x'
    n_metodo = "Chebyshev"
    print("La función a la que se le calculara el cero es:",f_prueba)
    print("El método usado es: ",n_metodo)
    print("La aproximacion de la solucion es: xk = ",newton_G_m2(f_prueba,1,10**-5,500)[0])
    print("El error es: ",newton_G_m2(f_prueba,1,10**-5,500)[1])

p_newton_G_m1()
p_newton_G_m2()