"""
todo: solucion numerica para el periodo de un pendulo simple
"""
import math as m

def isfloat(value):
  try:
    float(value)
    return True
  except ValueError:
    return False

def legendre(n, theta):
    k = 1
    for i in range(1, n+1):
        div = 1
        for j in range(1, i+1):
            fac = 2*j
            div *= (fac-1)/fac
        k += div**2 * m.sin(theta/2)**(2*i)
    return k



theta = input("Ingrese el angulo inicial en grados: ")
while True :
    if isfloat(theta) == True:
        theta = float(theta)
        if theta < 180 or theta > 0:
            break
        else:
            print("Valor invalido, favor de ingresar un numero entre 0 y 180")
            theta = input("Ingrese el angulo inicial en grados: ")
    else:
            print("Valor invalido, favor de ingresar un numero entre 0 y 180")
            theta = input("Ingrese el angulo inicial en grados: ")
if theta == 0 or theta == 180:
    print("El periodo del pendulo es idefinido")
    exit(0)


g = input("Ingrese el valor de la gravedad en m/s^2: ")
while True:
    if isfloat(g) == True:
        g = float(g)
        if g >= 0:
            break
        else:
            print("valor invalido, favor de elegir un valor mayor o igual a 0")
            g = input("Ingrese el valor de la gravedad en m/s^2: ")
    else:
        print("valor invalido, favor de elegir un valor mayor o igual a 0")
        g = input("Ingrese el valor de la gravedad en m/s^2: ")
if g == 0:
    print("El periodo del pendulo es idefinido")
    exit(0)


l = input("Ingrese la longitud de la cuerda en m: ")
while True:
    if isfloat(l) == True:
        l = float(l)
        if l >= 0:
            break
        else:
            print("Valor invalido, favor de ingresar un numero mayor o igual a 0")
            l = input("Ingrese la longitud de la cuerda en m: ")
    else:
        print("Valor invalido, favor de ingresar un numero mayor o igual a 0")
        l = input("Ingrese la longitud de la cuerda en m: ")


n = input("Ingrese un numero entero de iteraciones que desea realizar: ")
while True:
    if isfloat(n) == True:
        n = float(n)
        if float.is_integer(n) != False and n > 0:
            n = int(n)
            break
        else:
            print("Valor invalido, favor de ingresar un entero mayor a 0")
            n = input("Ingrese el numero de iteraciones que desea realizar: ")
    else:
        print("Valor invalido, favor de ingresar un entero mayor a 0")
        n = input("Ingrese el numero de iteraciones que desea realizar: ")


theta = (theta*m.pi)/180

T = 2*m.pi*m.sqrt(l/g)*legendre(n, theta)

print("El periodo del pendulo es aproximadamente %fs" %T)