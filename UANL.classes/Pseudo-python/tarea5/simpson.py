#Integracion numerica mediante la regla de simpson

import numpy as np

s = input("Ingrese la funcion: ")
s = "lambda x: "+s
f = eval(s)

a = int(input("Ingrese el limite inferior del dominio: "))
b = int(input("Ingrese el limite superior del dominio: "))
n = int(input("Ingrese el numero de subintervalos: "))

h = (b-a)/n
P = 0
I = 0

for i in np.arange(1, n):
    xi = a + i*h
    if i%2 == 0:
        P += f(xi)
    else:
        I += f(xi)

g = (h/3)*(f(a) + 4*I + 2*P + f(b))

print("La regla de simpson da una aproximacion de: ", g)