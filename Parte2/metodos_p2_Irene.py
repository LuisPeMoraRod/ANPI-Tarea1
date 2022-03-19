# -*- coding: utf-8 -*-
"""
Métodos de fórmula iterativa (4)
"""
import sympy as sy
#Método Newton H(u) = 1
def newton_H_m1(fun, x0, tol, iterMax):
    if tol <= 0 or iterMax <= 0:
        print("La tolerancia e Iteraciones Maximas deben ser mayor que 0")
        return [0,0]
    fun = sy.sympify(fun) #funcion 
    Df = sy.diff(fun)   #derivada de la funcion 
    x = sy.Symbol('x')
    xk = x0
    error = tol + 1
    for k in range(0, iterMax): #iteraciones maximas
        fxk = fun.evalf(subs={x:xk}) #evaluamos la funcion en el punto X0
        if abs(fxk) < tol:
            return [xk,error]
        Dfxk = Df.evalf(subs={x:xk}) #se evalua la derivada
        if Dfxk == 0: #condicion que se tiene que cumplir, denominador diferente a cero
            print('Derivada es igual a cero, por lo tanto no hay solucion')
            print('\n')
            return [xk,error]
        k = fxk/Dfxk
        xk = xk - k
        error = abs(fxk)
    print('No hay solucion, alcanzado el máximo numero de iteraciones')
    print('\n')
    return [0,0]

#Método Kanwar–Tomar H(u) = 1 / (1+Bu)
def newton_H_m2(fun, x0, tol, iterMax):
    if tol <= 0 or iterMax <= 0:
        print("La tolerancia e Iteraciones Maximas deben ser mayor que 0")
        return [0,0]
    fun = sy.sympify(fun) #funcion 
    Df = sy.diff(fun)   #derivada de la funcion 
    x = sy.Symbol('x')
    xk = x0
    error = tol + 1
    for k in range(0, iterMax): #iteraciones maximas
        fxk = fun.evalf(subs={x:xk}) #evaluamos la funcion en el punto X0
        if abs(fxk) < tol: #Se busca que el error sea menor que la tolerancia
            return [xk,error]
        Dfxk = Df.evalf(subs={x:xk}) #se evalua la derivada
        if Dfxk == 0: #condicion que se tiene que cumplir, denominador diferente a cero
            print('Derivada es igual a cero, por lo tanto no hay solucion')
            print('\n')
            return [xk,error]
        k = fxk/Dfxk
        Beta = 1.5
        xk = xk - (1 / (1 + Beta * (k)) * (k))
        error = abs(fxk)
    print('No hay solucion, alcanzado el máximo numero de iteraciones')
    print('\n')
    return [0,0]
