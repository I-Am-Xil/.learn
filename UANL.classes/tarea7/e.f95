!Este programa realiza una aproximacion a 'e'
!Por medio de una sumatoria del inverso de un factorial
!Usar al menos una funcion

program veinticinco
    implicit none

    write(*,*) "Este programa hace una aproximacion del numero 'e'"

    call factorial

end program veinticinco

subroutine factorial()

    integer i, j
    real e, n
    e = 0 

    do i = 1, 9
        n = 1
        do j = 1, i
            n = n*j
        end do
        e = e + 1/n
    end do

        write(*,*) "e es aproximadamente igual a ", e

    return

end subroutine factorial



