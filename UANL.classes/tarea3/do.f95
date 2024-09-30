!hacer un programa que utilizando un 'do', llene un vector de 10 posiciones
!imprima el vector

    program diez
        implicit none

        integer, dimension(10) :: v
        integer :: i

        do i = 1, 10, 1
            write(*,*) "ingrese la componente ", i, "del vector v"; read(*,*) v(i);
        end do
        
        write(*,*) v
        
    end program diez