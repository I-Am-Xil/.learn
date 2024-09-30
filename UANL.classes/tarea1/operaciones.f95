    program cuatro
        implicit none
        real x
        real y

        !Entrada de datos
        print*, "Este programa lee 2 numeros e imprime su suma, resta, multipliacion, division y potenciacion"
        print*, "Ingrese el valor de x "
        read(*,*) x
        print*, "Ingrese el valor de y "
        read(*,*) y

        !Salida de operaciones
        write(*,*) "suma:           ", x + y
        write(*,*) "division:       ", x / y
        write(*,*) "Resta:          ", x - y
        write(*,*) "Multiplicacion: ", x * y
        !El resultado de esta operacion es infinito si x**y >= 2^128
        write(*,*) "Potenciacion:   ", x ** y

    end program cuatro