program simpson
    implicit none
    real a, b, h;
    integer n

    write(*,*) "Ingrese el limite inferior";    read(*,*) a
    write(*,*) "Ingrese el limite superior";    read(*,*) b
    write(*,*) "Ingrese el numero de subintervalos";    read(*,*) n

    h = (b - a)/n

    call split(a, b, h, n)

end program simpson


subroutine f(x)
implicit none
real x
x = x**3
end subroutine f


subroutine fsimpson(a, b, I, P, h)
implicit none
real I, P, g, fa, fb, h, a, b
fa = a
fb = b

call f(fa)
call f(fb)

g = (h/3)*(fa + 4*I + 2*P + fb)

write(*,*) "La regla de simpson da una aproximacion de: ", g
end subroutine fsimpson


subroutine split(a, b, h, n)
implicit none
integer n, j
real h, xi, I, P, a, b
I = 0
P = 0

do j = 1, n-1
    xi = a + j*h
    call f(xi)
    if ( mod(j, 2) == 0 ) then
        P = P + xi
    else
        I = I + xi
    end if
end do

call fsimpson(a, b, I, P, h)
end subroutine split