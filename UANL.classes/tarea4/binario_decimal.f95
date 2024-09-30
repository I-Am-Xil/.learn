!Haga un programa en fortran que pida al usuario un numero binario desde (0000000000 hasta 1111111111) y lo convierta
!imprima su correspondiente número decimal.

program diecinueve
    implicit none
    character, dimension(10) :: binario
    integer i, decimal

    i = 1
    decimal = 0

    write(*,*) "Este programa lee un numero binario entre '0000000000' y '1111111111'"

    do while(i <= 10)
        write(*,*) "Ingrese de derecha a izquierda el termino numero", i;
        read(*,*) binario(i)

        if ( binario(i) == '0' .or. binario(i) == '1' ) then
            if ( binario(i) == '1' ) then
                decimal = decimal + 2**(i-1);
            end if
            i = i + 1;
        else
            write(*,*) "El numero ingresado no es valido, favor de ingresar solo unos y ceros"
            exit 
        end if

        write(*,*) decimal
    end do

end program diecinueve