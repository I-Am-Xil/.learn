#Integracion numerica mediante la regla del trapecio

import numpy as np

s = input("Ingrese la funcion: ")
s = "lambda x: "+s
f = eval(s)

a = int(input("Ingrese el limite inferior del dominio: "))
b = int(input("Ingrese el limite superior del dominio: "))
n = int(input("Ingrese el numero de subintervalos: "))

h = (b-a)/n
y = 0

for i in np.arange(1, n):
    y += f(a + i*h)

g = h*((f(a)+f(b))/2 + y)

print("La regla de simpson da una aproximacion de: ", g)