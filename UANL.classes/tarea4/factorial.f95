!Haga un programa en fortran que lea un numero entero y encuentre su factorial
!Como no hay factorial de numeros negativos, el programa debe de revisar que el numero sera positivo
!Si es negativo debe imprimir "Como el numero es negativo, no se puede entregar un factorial"

program catorce
    implicit none
    integer x, y, i
    y = 1

    write(*,*) "Este programa lee un numero e imprime su factorial, en caso de ser negativo, indica la imposibilidad"
    write(*,*) "Ingrese el numero del cual desea sacar su factorial"
    read(*,*) x

    if (x >= 0) then
        
        do i = 1, x
            y = y*i
        end do
        write(*,*) "El factorial de ", x, "es ", y;
    else
        write(*,*) "El numero es negativo, por lo tanto no se puede entregar un factorial"
    end if

end program catorce