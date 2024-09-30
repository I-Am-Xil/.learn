


program veintitres
    implicit none

    

    100 format(30A)

    

    open(unit=7, file='prueba1.txt', status='unknown')

        write(*,*) "Logan Martinez"
        write(7,*) "Logan Martinez"
        write(7,100) "Logan Martinez"
    close(7)

end program veintitres