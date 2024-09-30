!Haga un programa en fortran que lea un conjunto de puntos
!       y encuentre la ecuación lineal que los representa por medio
!       de mínimos cuadrados. De tal manera que al final imprima dicha
!       ecuación que tiene la forma y=mx+b, donde m es la pendiente y b
!       la intersección con el origen. El calculo de m se deberá hacer
!       en una subrutina y el calculo de b en otra, por lo que en el
!       programa principal solo se lee el numero de puntos que se darán N
!       y dichos puntos (xi,yi)  (i=1,N).

program veintiseis
    implicit none
    integer n
    real x, y, suma_x, suma_y, suma_xy, suma_xx, m, b

    suma_x = 0
    suma_y = 0
    suma_xy = 0

    write(*,*) "Este programa lee un conjunto de longitud n tanto para 'x' como para 'y' y hace una regresion lineal"
    write(*,*) "Ingrese el numero de datos a ingresar para 'x' y 'y' "

    read(*,*) n

    call sumas(n, x, y, suma_x, suma_y, suma_xy, suma_xx)

    !write(*,*) "La suma de y = ", suma_y
    !write(*,*) "La suma de x = ", suma_x
    !write(*,*) "La suma de xy = ", suma_xy
    !write(*,*) "La suma de xx = ", suma_xx
    
    call pendiente(n, suma_x, suma_y, suma_xy, suma_xx, m)
    call interseccion_y(n, suma_x, suma_y, suma_xy, suma_xx, b)

    125 format(A,1f6.3,A,1f6.3,A)
    write(*,125) "y =", m, "x+(", b,")"
    
end program veintiseis


subroutine pendiente(n, s_x, s_y, s_xy, s_xx, m)
    implicit none
    integer n
    real s_x, s_y, s_xy, s_xx
    real, intent(out) :: m
    m = 0
    m = (n*s_xy-s_x*s_y)/(n*s_xx-s_x**2)

end subroutine


subroutine interseccion_y(n, s_x, s_y, s_xy, s_xx, b)
    implicit none
    integer n
    real s_x, s_y, s_xy, s_xx
    real, intent(out) :: b
    b = 0
    b = (s_y*s_xx-s_x*s_xy)/(n*s_xx-s_x**2)

end subroutine


subroutine sumas(n, x, y, s_x, s_y, s_xy, s_xx)
    implicit none
    integer n, i
    real x, y, s_x, s_y, s_xy, s_xx

    write(*,*) "Ingrese los valores de x"
    do i = 1, n
        read(*,*) x
        s_x = s_x + x
    end do
    

    write(*,*) "Ingrese los valores de y"
    do i = 1, n
        read(*,*) y
        s_y = s_y + y
    end do


    do i = 1, n
        s_xy = s_xy + x*y
    end do

    
    do i = 1, n
        s_xx = s_xx + x*x
    end do
end subroutine