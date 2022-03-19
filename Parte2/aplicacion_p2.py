# -*- coding: utf-8 -*-
"""
Estimacioón de la distancia en redes de sensores inalámbricos.
Usando un método de Newton modificado.
"""
# Método Newton modificado
def newton_modificado(x0, tol, iterMax):
    import sympy as sy
    print('Metodo Newton Modificado')

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
    xn = x0
    for n in range(0, iterMax):  # iteraciones maximas
            # Se evalúa la funcion en X0
        fxn = func.evalf(subs={d: xn})
        if abs(fxn) < tol:
            print('Se aproxima una solucion despues de', n, 'iteraciones')
            print(xn)
            print('\n')
            print('El porcentajer de error es ',error)
            return xn
        Dfxn = Df.evalf(subs={d: xn})  # Se evalua la derivada
        if Dfxn == 0:  # condicion a cumplir/denominador diferente a cero
            print('No hay solución ya que la derivada es igual a cero')
            print('\n')
            return None
        n = fxn/Dfxn
        xn1 = xn - n #Formula de Newton
        error = abs(xn1-xn)
        xn = xn1
    print('No hay solucion, alcanzado el máximo numero de iteraciones')
    print('\n')
    return None


newton_modificado(1, 1e-5, 100)

