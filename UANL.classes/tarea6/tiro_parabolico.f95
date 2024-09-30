!Haga un programa en fortran que calcule lo que se pide en el siguiente problema considerando los ángulos:  θ = 20°, 36.9°, 45°, 57.8°, 72° y 80.3°
!imprima los resultados en una tabla utilizando formato.

!Una persona lanza una piedra al aire con una velocidad inicial de 45m/s, formando un ángulo de θ grados con la horizontal.
!Si alguien la recoge a la misma altura desde donde fue lanzada.
!Determine el tiempo total que la piedra esta en el aire y la distancia horizontal recorrida.

program veintidos
    implicit none
    integer i
    real v_x, v_y, t, x;
    real, dimension(6) :: angulo

    write(*,*) "Este programa calcula la distancia recorrida en un tiro parabolico para ciertos angulos a 45m/s"
    write(*,*) ""

    angulo(1) = 20
    angulo(2) = 36.9
    angulo(3) = 45
    angulo(4) = 57.8
    angulo(5) = 72
    angulo(6) = 80.3

    121 format(1x, f6.4, 13x, A1, 1x, f5.1, A1)

    write(*,*) "Angulo en radianes | distancia recorrida"

    do i = 1, 6
        angulo(i) = angulo(i)*3.14/180
        v_x = 45*cos(angulo(i))
        v_y = 45*sin(angulo(i))
    
        t = 2*v_y/9.8
        
        x = t*v_x

        write(*,121) angulo(i) ,"|", x, "m"
    end do

end program veintidos