#Utilizar el metodo de Newton-Raphson
#Pedir la funcion
#Pedir el dominio

import numpy as np
import matplotlib.pyplot as plt

#entrada y almacenamiento de la funcion
s = input("Ingrese la funcion: ")
s = "lambda x: "+s
f = eval(s)

a = int(input("Ingrese el limite inferior del dominio: "))
b = int(input("Ingrese el limite superior del dominio: "))


def derivada(a, b, f):
    return (f(b)-f(a))/(b-a)

def x_n(a, f):
    n = a
    while (np.abs(f(n)) >= 1E-7):
        d = derivada(n, b, f)
        n = n - f(n)/d
    return n

n = x_n(a, f)
print("El metodo de Newton-Raphson da raiz en x =", n)

x = np.linspace(a, b, 100)
plt.plot(x, f(x))
plt.grid()
plt.show()