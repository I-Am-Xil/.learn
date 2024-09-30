!Utilizar el metodo de Newton-Raphson
!Pedir la funcion
!Pedir el dominio

program Newton
    implicit none
    real a, b, d

    write(*,*) "Ingrese el valor de a y b"
    read(*,*) a, b
    call x_n(a, b, d)
end program Newton


subroutine f(x)
implicit none
real x
x = x**3 + 1
end subroutine f


subroutine derivada(a, b, d_x)
implicit none
real f_b, f_a, a, b, d_x
f_a = a
f_b = b
call f(f_a)
call f(f_b)
d_x = (f_b-f_a)/(b-a)
end subroutine derivada


subroutine x_n(n, b, d)
implicit none
real b, n, f_n, d
f_n = n
do while(abs(f_n) >= 1E-5)
    f_n = n
    call derivada(n, b, d)              
    call f(f_n)
    n = n - f_n/d
end do

write(*,*) "El metodo de Newton-Raphson da raiz en x =", n

end subroutine x_n