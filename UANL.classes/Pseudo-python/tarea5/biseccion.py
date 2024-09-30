#Utilizar el metodo de biseccion
#Pedir la funcion
#Pedir el dominio
#Verificar que en el invervalo hay un cambio de signo

import numpy as np
import matplotlib.pyplot as plt

#entrada y almacenamiento de la funcion
s = input("Ingrese la funcion: ")
s = "lambda x: "+s
f = eval(s)

a = int(input("Ingrese el limite inferior del dominio: "))
b = int(input("Ingrese el limite superior del dominio: "))

if f(a)*f(b) > 0:
    print("Funcion no valida para el rango seleccionado")
    exit()

def biseccion(f, a, b, tol):
    xl = a
    xr = b
    while (np.abs(xl-xr) >= tol):
        c = (xl+xr)/2
        prod = f(xl)*f(c)
        if prod > tol:
            xl = c
        elif (prod < tol):
            xr = c
    return c

answer = biseccion(f, a, b, 1E-7)

print("El metodo de biseccion da raiz en x =", answer)

x = np.linspace(a, b, 100)
plt.plot(x, f(x))
plt.grid()
plt.show()
            