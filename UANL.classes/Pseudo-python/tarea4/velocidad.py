#La velocidad angular vectorial ω de un objeto que se mueve con
#una velocidad v a una distancia r del origen del sistema de coordenadas es
#dado por la ecuación
#v = r × ω
#donde r es la distancia en metros, ω es la velocidad angular en radianes por segundo y v
#es la velocidad en metros por segundo. Si la distancia desde el centro de la tierra a un
#el satélite en órbita es r = 300,000i + 400,000j + 50,000k metros, y la velocidad angular
#del satélite es ω = −6 x 10−3i + 2 x 10−3j - 9 x 10–4k radianes por segundo, ¿cuál es el
#velocidad del satélite en metros por segundo? Haga un programa en python para calcular la respuesta.
#O la de cualquier otra combinacion de r y ω que el usuario quiera!

import numpy as np

w = np.array([-6*10**-3,2*10**-3,-9*10**-4])
r = [300000, 400000, 50000]

v = [r[1]*w[2]-r[2]*w[1], r[0]*w[2]-r[2]*w[0], r[0]*w[1]-r[1]*w[0]]

print("(%4.0fi+%2.0fj+%4.0fk)m/s" % (v[0], v[1], v[2]))