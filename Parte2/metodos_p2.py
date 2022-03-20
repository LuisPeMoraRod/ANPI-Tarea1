import sympy as sy

"""
Métodos de fórmula iterativa (4)
"""

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

#Metodo Halley G(w)= 2/(2-w)
def newton_G_m1(fun,x0,tol,iterMax):
    # la tolerancia y numero de iteraciones maximas no pueden ser negativas
    if tol <= 0 or iterMax <= 0:
        print("La tolerancia e Iteraciones Maximas deben ser mayor que 0")
        return [0,0]
    f = sy.sympify(fun) #Se maneja la funcion dada como string de forma que pueda ser usada como parte de SymPy
    x = sy.Symbol('x') #Se define una variable simbolica
    d1f = sy.diff(f,x) #Se calcula la primer derivada de la funcion
    d2f = sy.diff(d1f,x) #Se calcula la segunda derivada de la funcion
    error = tol + 1
    k = 0
    xk = x0
    #Se tiene como condiciones de parada cuando el error sea menor que la tolerancia dada o cuando se superen las iteraciones maximas
    while error > tol and k < iterMax:
        k = k + 1
        #Condiciones que harian que se indefina la funcion al darse un denominador igual a cero
        if abs(sy.N(d1f.subs(x,xk))) < 10^-15 or abs((sy.N(d1f.subs(x,xk)))**2) < 10^-15:
            print ("El valor del denominador es 0")
            return [0,0]
        w = (sy.N(f.subs(x,xk)) * sy.N(d2f.subs(x,xk)))/(sy.N(d1f.subs(x,xk)))**2 #Calculo del valor de w usando la funcion y sus derivadas
        if w == 2:
            print ("El valor del denominador en G(w) es 0")
            return [0,0]
        g = 2 / (2 - w) #Funcion de peso para calcular la aproximacion al cero
        xk = xk - g*(sy.N(f.subs(x,xk))/sy.N(d1f.subs(x,xk))) #Calculo de la aproximacion del cero de forma iterativa
        error = abs(sy.N(f.subs(x,xk))) #Calculo del error con el nuevo valor de la aproximacion
    #Si se da la condicion de superacion de las iteraciones maximas se indica el valor al que se llego y se indica que se superaron las iteraciones maximas
    if k >= iterMax:
        print ("Se supero el limete de iteraciones")
        return [xk,error]
    #Si se da la condicion de un error menor a la tolerancia se obtuvo la aproximacion
    if error <= tol:
        return [xk,error]

#Metodo Chevyshev G(w) = 1 + (w/2)
def newton_G_m2(fun,x0,tol,iterMax):
    if tol <= 0 or iterMax <= 0:
        print("La tolerancia e Iteraciones Maximas deben ser mayor que 0")
        return [0,0]
    f = sy.sympify(fun) #Se maneja la funcion dada como string de forma que pueda ser usada como parte de SymPy
    x = sy.Symbol('x') #Se define una variable simbolica
    d1f = sy.diff(f,x) #Se calcula la primer derivada de la funcion
    d2f = sy.diff(d1f,x) #Se calcula la segunda derivada de la funcion
    error = tol + 1
    k = 0
    xk = x0
    # Se tiene como condiciones de parada cuando el error sea menor que la tolerancia dada o cuando se superen las iteraciones maximas
    while error > tol and k < iterMax:
        k += 1
        # Condicion que haria que se indefina la funcion al darse un denominador igual a cero
        if abs(sy.N(d1f.subs(x,xk))) < 10^-15 or abs((sy.N(d1f.subs(x,xk)))**2) < 10^-15:
            print ("El valor del denominador es 0")
            return [0,0]
        w = (sy.N(f.subs(x,xk)) * sy.N(d2f.subs(x,xk)))/((sy.N(d1f.subs(x,xk)))**2) #Calculo del valor de w usando la funcion y sus derivadas
        g = 1 + (w/2) #Funcion de peso para calcular la aproximacion al cero
        xk = xk - g*(sy.N(f.subs(x,xk))/sy.N(d1f.subs(x,xk))) #Calculo de la aproximacion del cero de forma iterativa
        error = abs(sy.N(f.subs(x,xk))) #Calculo del error con el nuevo valor de la aproximacion
    # Si se da la condicion de superacion de las iteraciones maximas se indica el valor al que se llego y se indica que se superaron las iteraciones maximas
    if k >= iterMax:
        print ("Se supero el limete de iteraciones")
        return [xk,error]
    # Si se da la condicion de un error menor a la tolerancia se obtuvo la aproximacion
    if error <= tol:
        return [xk,error]

