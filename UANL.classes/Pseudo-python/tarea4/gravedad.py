#Escribe un programa que calcule la aceleracion de la gravedad a pasos de 500 desde 0 a 40,000
#Imprima El resultado en una tabla De altura contra aceleracion
# a = -Gm/(r+h)^2

import numpy as np
import matplotlib.pyplot as plt

h = np.arange(0, 40001, 500)*1000+6371E3

a = -(6.672E-11)*(5.98E24)/(h)**2

print("Altura (m)       Aceleracion (m/s^2)")

for i in range(81):
    print("%8.0f         %5.3f" % (h[i], a[i]))

plt.plot(a, h)
plt.xlabel("Altura (m)")
plt.ylabel("Aceleracion (m/s^2)")
plt.show()
