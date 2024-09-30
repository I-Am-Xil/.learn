#Escriba un programa en Python.
#Asuma que el volumen de un mol de un gas ideal tiene un volumen fijo de 10 litros.
#Calcule e imprima la presión del gas si la temperatura está cambiando de 250 hasta 400 Kelvin en pasos de medio grado.
#PV=nRT; V=10, n = 1[mol], R=8.314

import matplotlib.pyplot as plt
import numpy as np

T = np.arange(250, 401, 0.5)
P = (8.314*T)/10
for i in range(301):
    print("Temperatura: ", T[i], "      Presion: ", P[i])

plt.plot(T, P)
plt.xlabel("Temperatura (K)")
plt.ylabel("Presion")
plt.show()
