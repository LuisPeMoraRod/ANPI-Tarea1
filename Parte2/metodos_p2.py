import sympy as sy

def newton_G_m1(fun,x0,tol,iterMax):
    if tol <= 0 or iterMax <= 0:
        print("La tolerancia e Iteraciones Maximas deben ser mayor que 0")
        return 0
    f = sy.sympify(fun)
    x = sy.Symbol('x')
    d1f = sy.diff(f,x)
    d2f = sy.diff(d1f,x)
    error = tol + 1
    k = 0
    xk = x0
    while error > tol and k < iterMax:
        k = k + 1
        if abs(sy.N(d1f.subs(x,xk))) < 10^-15 or abs((sy.N(d1f.subs(x,xk)))**2) < 10^-15:
            print ("El valor del denominador es 0")
            return 0
        w = (sy.N(f.subs(x,xk)) * sy.N(d2f.subs(x,xk)))/(sy.N(d1f.subs(x,xk)))**2
        if w == 2:
            print ("El valor del denominador en G(w) es 0")
            return 0
        g = 2 / (2 - w)
        xk = xk - g*(sy.N(f.subs(x,xk))/sy.N(d1f.subs(x,xk)))
        error = abs(sy.N(f.subs(x,xk)))
    if k >= iterMax:
        print ("Se supero el limete de iteraciones")
        print ("Se aproximó la solución: ",xk)
        print ("Obtenida luego de",k,"iteraciones")
        print ("Con un error de: ",error)
    if error <= tol:
        return [xk,error]


def newton_G_m2(fun,x0,tol,iterMax):
    if tol <= 0 or iterMax <= 0:
        print("La tolerancia e Iteraciones Maximas deben ser mayor que 0")
        return 0
    f = sy.sympify(fun)
    x = sy.Symbol('x')
    d1f = sy.diff(f,x)
    d2f = sy.diff(d1f,x)
    error = tol + 1
    k = 0
    xk = x0
    while error > tol and k < iterMax:
        k += 1
        if abs(sy.N(d1f.subs(x,xk))) < 10^-15 or abs((sy.N(d1f.subs(x,xk)))**2) < 10^-15:
            print ("El valor del denominador es 0")
            return 0
        w = (sy.N(f.subs(x,xk)) * sy.N(d2f.subs(x,xk)))/(sy.N(d1f.subs(x,xk)))**2
        g = 1 + (w/2)
        xk = xk - g*(sy.N(f.subs(x,xk))/sy.N(d1f.subs(x,xk)))
        error = abs(sy.N(f.subs(x,xk)))
    if k >= iterMax:
        print ("Se supero el limete de iteraciones")
        print ("Se aproximó la solución: ",xk)
        print ("Obtenida luego de",k,"iteraciones")
        print ("Con un error de: ",error)
    if error <= tol:
        return [xk,error]


