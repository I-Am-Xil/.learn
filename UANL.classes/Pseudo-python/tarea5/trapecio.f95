program trapecio
    implicit none
    real a, b, h;
    integer n

    write(*,*) "Ingrese el limite inferior";    read(*,*) a
    write(*,*) "Ingrese el limite superior";    read(*,*) b
    write(*,*) "Ingrese el numero de subintervalos";    read(*,*) n

    h = (b - a)/n

    call ftrapecio(a, b, h, n)

end program trapecio

subroutine f(x)
implicit none
real x
x = x**3
end subroutine f


subroutine sxi(a, h, n, y)
implicit none
real a, xi, y, h
integer i, n

do i = 1, n-1
    xi = a + i*h
    call f(xi)
    y = y + xi
end do
end subroutine sxi


subroutine ftrapecio(a, b, h, n)
    implicit none
    real a, b, fa, fb, h, y, g
    integer n
    y = 0
    fa = a
    fb = b

    call sxi(a, h, n, y)
    call f(fa)
    call f(fb)
    
    g = h*((fa+fb)/2 + y)

    write(*,*) "La regla del trapecio da una aproximacion de: ", g
end subroutine ftrapecio