!El n-ésimo numero de Fibonacci está definido por las siguientes ecuaciones recursivas:
!f(1)=1
!f(2)=2
!f(n)=f(n-1)+f(n-2)
!Escriba un programa que calcule e imprima hasta el n-ésimo termino de Fibonacci , para n>2 , donde n es dado por el usuario.
!Utilice un ciclo while para llevar a cabo los cálculos.

program dieciocho
    implicit none
    integer x, y, z, i, n

    write(*,*) "Ingrese el n-ecimo numero fibonacci que desea calcular"
    read(*,*) n

    x = 0
    y = 1
    z = 1

    if ( n > 2 ) then
        do i = 1, n
            z = y + x
            x = y
            y = z
            write(*,*) z
        end do
    end if
end program dieciocho