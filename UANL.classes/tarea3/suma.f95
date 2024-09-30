!Realiza la suma de todos los numeros desde el 1 al 100 con un ciclo
    program once
        implicit none
        integer i, suma
        suma = 0

        do i = 1, 100, 1
            suma = suma + i
        end do
        write(*,*) suma
    end program once