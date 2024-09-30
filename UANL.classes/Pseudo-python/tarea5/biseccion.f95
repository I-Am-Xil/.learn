!Utilizar el metodo de biseccion
!Pedir la funcion
!Pedir el dominio
!Verificar que en el invervalo hay un cambio de signo


!No he podido resolver el problema del parser para fortran

program biseccion
    implicit none
    real x, y, a, b

    write(*,*) "Ingrese el valor de a y b"
    read(*,*) a, b
    x = a
    y = b

    call f(x)
    call f(y)

    if (x*y > 0) then
        write(*,*) "Metodo no valido para encontrar raices en el dominio dado para la funcion: y = x**3+1"
        write(*,*) "y(a) = ", x
        write(*,*) "y(b) = ", y

        stop

    else if(x*y == 0) then
        if (x == 0) then
            write(*,*) "Una raiz está en:", a
        end if

        if (y == 0) then
            write(*,*) "Una raiz está en:", b
        end if
    end if

    call raiz(a, b, y)
    write(*,*) "El metodo de biseccion da raiz en x =", y

end program biseccion


subroutine f(x)
implicit none
real x
x = x**3 + 1
end subroutine f


subroutine raiz(a, b, c)
implicit none
real a, b, y, prod, tol, c
tol = 1E-7

do while (abs(a-b) >= tol )
    y = (a + b)/2
    c = y
    call f(a)
    call f(y)
    prod = a*y
    if (prod > tol) then
        a = c
    else if (prod < tol) then
        b = c
    end if
end do
end subroutine raiz