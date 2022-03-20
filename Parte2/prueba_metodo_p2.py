from metodos_p2 import *

"""
Prueba de métodos implementados
"""

"""
 Se utiliza como funcion de prueba cos(x)-x para todos los metodos
 Se utiliza como tolerancia 10**-5 para todos los metodos
 Se utilizan 500 iteraciones maximas para todos los metodos
"""

f_prueba = 'cos(x)-x'

def p_newton_H_m1():
    n_metodo = "Kanwar-Tomar"
    sol = newton_H_m1(f_prueba, 2.1, 10 ** -5, 500)
    print("Función a calcular el cero: f(x) =", f_prueba)
    print("Utilizando Método", n_metodo)
    print("Aproximación de la solución: xk =", sol[0])
    print("Con un error de ", sol[1])
    print('\n')


def p_newton_H_m2():
    n_metodo = "Newton"
    sol = newton_H_m2(f_prueba, 2.1, 10 ** -5, 500)
    print("Función a calcular el cero: f(x) = ", f_prueba)
    print("Utilizando Método", n_metodo)
    print("Aproximación de la solución: xk = ", sol[0])
    print("Con un error de", sol[1])
    print('\n')


def p_newton_G_m1():
    n_metodo = "Halley"
    sol = newton_G_m1(f_prueba,2.1,10 ** -5, 500)
    print("Función a calcular el cero: f(x) =", f_prueba)
    print("Utilizando Método", n_metodo)
    print("Aproximacion de la solucion: xk =", sol[0])
    print("Con un error de", sol[1])
    print('\n')


def p_newton_G_m2():
    n_metodo = "Chebyshev"
    sol = newton_G_m2(f_prueba, 2.1, 10 ** -5, 500)
    print("Función a calcular el cero: f(x) =", f_prueba)
    print("Utilizando Método", n_metodo)
    print("Aproximacion de la solucion: xk = ", sol[0])
    print("Con un error de", sol[1])

p_newton_H_m1()
p_newton_H_m2()
p_newton_G_m1()
p_newton_G_m2()