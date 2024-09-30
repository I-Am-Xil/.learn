!Evaluar una funcion y(x) = ln(1(1-x))
!Para cualquier valor de x especificado por el usuario.
!Escriba el programa con un ciclo while de tal manera que el programa repita el calculo siempre que el valor de x sea válido.
!Y cuando un valor ilegal de x sea dado el programa termine.
!Vaya imprimiendo el valor de “x” y “y” y cuando el programa termine diga que fue por usar un valor de x no valido.

program diecisiete
    implicit none
    real x, y
    
    write(*,*) "Este programa lee un valor para 'x' menor que 1 e imptrime el resultado de una cierta funcion 'y' "
    write(*,*) "Ingrese un valor para 'x' "

    read(*,*) x

    if ( x < 1 ) then
        do while(x < 1)
            y = log(1/(1-x))
            write(*,*) "El valor de y para el valor de x =", x, "Es igual a:", y;
            write(*,*) "Ingrese el siguiente valor de x"
            read(*,*) x
        end do
    end if

    if ( x >= 1 ) then
        write(*,*) "Valor no valido. Fin del programa"
    end if

end program diecisiete