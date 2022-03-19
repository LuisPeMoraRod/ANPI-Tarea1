# -*- coding: utf-8 -*-
"""
Estimacioón de la distancia en redes de sensores inalámbricos.
Usando un método de Newton modificado.
"""
import sympy as sy
# Método Newton modificado
def newton_modificado(x0, tol, iterMax):
    if tol <= 0 or iterMax <= 0:
        print("La tolerancia e Iteraciones Maximas deben ser mayor que 0")
        return [0,0]
    print('Metodo Newton Modificado')
    print("Donde x0 =", x0)
    # Se asigna como variable de la función la d
    d = sy.Symbol('d')   
    # parametros dados
    r = 10
    α = 4
    σdB = 4
    λ = 1
    x1 = 7
    x2 = 6
    # parámetros complejos
    σ2R = (σdB)**2/(10*α)**2
    S = sy.pi.evalf()*r**2
    k = (10*α)/(sy.log(10).evalf())
    gd = (2*S/sy.pi.evalf()) * sy.sympify('acos(d/(2*10))') - \
        sy.sympify('d*(sqrt(10**2-(d**2)/4))')  # ???
    σ2C = (gd**2/2*λ*k**2) * ((1/gd + (1/S)))

    # Aquí se arma la función como se indica en el enunciado
    func = ((sy.log((x1/d), 10)) / (σ2R * sy.log(10))) + (d*(x2-d) / σ2C)
    error = 0 #Inicializamos el porcentaje de error
    Df = sy.diff(func)  # derivada de la funcion
    xk = x0
    for k in range(0, iterMax):  # iteraciones maximas
            # Se evalúa la funcion en X0
        fxk = func.evalf(subs={d: xk})
        if abs(fxk) < tol:
            print('Se aproxima una solucion luego de', k, 'iteraciones')
            print("Aproximacion de la solucion: xk =", xk)
            print('El porcentajer de error es ',error)
            return xk
        Dfxk = Df.evalf(subs={d: xk})  # Se evalua la derivada
        if Dfxk == 0:  # condicion a cumplir/denominador diferente a cero
            print('No hay solución ya que la derivada es igual a cero')
            print('\n')
            return None
        k = fxk/Dfxk
        xk1 = xk - k #Formula de Newton
        error = abs(xk1-xk)
        xk = xk1
    print('No hay solucion, alcanzado el máximo numero de iteraciones')
    print('\n')
    return None


newton_modificado(1, 1e-5, 100)

