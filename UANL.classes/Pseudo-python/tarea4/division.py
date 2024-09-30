#Escriba un programa que pida al usuario 2 numeros e imprima en pantalla su division.
#Si su divisor es 0 que imprima un mensaje  de "Error"



dividendo = float(input("Ingrese el dividendo\n"))
divisor = float(input("Ingrese el divisor\n"))

if divisor == 0:
    print("ERROR")
    exit()

resultado = dividendo/divisor

print("El resultado es: ", resultado)

