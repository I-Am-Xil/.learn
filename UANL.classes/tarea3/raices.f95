!Haga un programa en fortan que lea los coeficientes de una eq. cuadratica
!Imprima el tipo de raices que tiene esa eq. sin resolver la eq.

program doce
    implicit none
    integer, dimension(3) :: coef
    integer discriminante

    write(*,*) "Este programa lee los coeficientes de una ecuacion cuadratica e imprime el tipo de racies que posee"
    write(*,*) "Ingrese los coeficientes de la ecuación cuadratica que desea resolver"
    read(*,*) coef

    discriminante = coef(2)**2 - 4*coef(1)*coef(3)

    if (discriminante > 0) then
        write(*,*) "Las raices son reales y diferentes"
    end if

    if (discriminante == 0) then
        write(*,*) "Las raices son reales e iguales"
    end if

    if (discriminante < 0) then
        write(*,*) "Las raices son complejas"
    end if

end program doce