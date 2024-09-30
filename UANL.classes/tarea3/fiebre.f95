!Haga un programa en fortran que lea la temperatura corporal del usuario en (C)
!imprima si C < 36 temperatura baja, 36-37.5  temperatura normal, 37.5- 39  fiebre, C > 39 fiebre muy alta

program trece
    implicit none
    real C

    write(*,*) "Este programa lee la temperatura del usuario y determina en caso de tener fiebre el tipo de esta"
    write(*,*) "Ingrese su temperatura corporal en grados centigrados: "
    read(*,*) C

    if (C < 36) then
        write(*,*) "Temperatura baja"
    else if (C >= 36 .and. C <= 37.5) then
        write(*,*) "Temperatura normal"
    else if (C > 37.5 .and. C <= 39) then
        write(*,*) "Fiebre"
    else
        write(*,*) "Fiebre muy alta"
    end if

end program trece