# -*- coding: utf-8 -*-
"""
Prueba de métodos implementados
"""
from metodos_p2 import *


def p_newton_H_m1():
    f_prueba = 'cos(x)-x'
    n_metodo = "Kanwar-Tomar"
    sol = newton_H_m1(f_prueba,1,10**-5,500)
    print("Función a calcular el cero: f(x) =",f_prueba)
    print("Utilizando Método",n_metodo)
    print("Aproximación de la solución: xk =", sol[0])
    print("Con un error de ", sol[1])
    print('\n')
    
def p_newton_H_m2():
    f_prueba = 'cos(x)-x'
    n_metodo = "Newton"
    sol = newton_H_m2(f_prueba,1,10**-5,500)
    print("Función a calcular el cero: f(x) = ",f_prueba)
    print("Utilizando Método",n_metodo)
    print("Aproximación de la solución: xk = ", sol[0])
    print("Con un error de", sol[1])
    print('\n')

def p_newton_G_m1():
    f_prueba = 'cos(x)-x'
    n_metodo = "Halley"
    print("Función a calcular el cero: f(x) =",f_prueba)
    print("Utilizando Método",n_metodo)
    print("Aproximacion de la solucion: xk =",newton_G_m1(f_prueba,1,10**-5,500)[0])
    print("Con un error de",newton_G_m1(f_prueba,1,10**-5,500)[1])
    print('\n')

def p_newton_G_m2():
    f_prueba = 'cos(x)-x'
    n_metodo = "Chebyshev"
    print("Función a calcular el cero: f(x) =",f_prueba)
    print("Utilizando Método",n_metodo)
    print("Aproximacion de la solucion: xk = ",newton_G_m2(f_prueba,1,10**-5,500)[0])
    print("Con un error de",newton_G_m2(f_prueba,1,10**-5,500)[1])

p_newton_H_m1()
p_newton_H_m2()
p_newton_G_m1()
p_newton_G_m2()
