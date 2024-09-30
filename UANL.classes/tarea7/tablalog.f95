!Escriba un programa en fortran que genere una tabla de logaritmos base 10 entre 1 y 10 en pasos de 0.1.
!Esta tabla debe de tener la siguiente forma:
!Debe guardarla en un archivo que tenga como nombre tablalog-(iniciales de su nombre).dat

program veinticuatro
    implicit none
    integer i, k
    real j
    real, dimension(10) :: l

    101 format(i2, 4x, f8.6, 1x, f8.6, 1x, f8.6, 1x, f8.6, 1x, f8.6, 1x, f8.6, 1x, f8.6, 1x, f8.6, 1x, f8.6, 1x, f8.6)
    102 format(6x, A, 6x, A, 6x, A, 6x, A, 6x, A, 6x, A, 6x, A, 6x, A, 6x, A, 6x, A)
    
    write(*,*) "Este programa genera una archivo .dat con una tabla de logaritmos base 10 en el dominio [1,11) a pasos de 0.1"

    j = 1;

    open(unit=7, file='tablalog-LAMP.dat', status='unknown')
    
    write(7,102) "X.0", "X.1", "X.2", "X.3", "X.4", "X.5", "X.6", "X.7", "X.8", "X.9"

    do i = 1, 10
        do k = 1, 10

            l(k) = log10(j)        
            j = j + 0.1

        end do
        write(7,101) i, l
    end do

    close(7)

end program veinticuatro