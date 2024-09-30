    !dos vectores de 3 componentes v1, v2
    !2 matrices 2x2 a, b, c
    !Asigne el valor 1 a la componente 1-v1
    !Asigne el valor 2 a la componente 2-v1
    !Asigne el valor 3 a la componente 3-v1
    !Asigne el valor 4 a todas las componentes de v2
    !Matriz b[][] {1,2}{3,4}
    !Matriz c[][] {2,2}{2,2}
    !cada componente de la matriz a será => a_ij = b_ij/c_ij
    !imprimir v1 completo (Como cadena)
    !imprimir v2 por componentes

    program seis
        implicit none
        integer, dimension(3) :: v1
        integer, dimension(3) :: v2
        real, dimension(2,2) :: a
        real, dimension(2,2) :: b
        real, dimension(2,2) :: c

        v1(1) = 1
        v1(2) = 2
        v1(3) = 3

        v2 = 4

        b(1,1) = 1
        b(1,2) = 2
        b(2,1) = 3
        b(2,2) = 4

        c = 2

        a(1,1) = b(1,1)/c(1,1)
        a(1,2) = b(1,2)/c(1,2)
        a(2,1) = b(2,1)/c(2,1)
        a(2,2) = b(2,2)/c(2,2)

        write(*,*) "Vector v1:                  ", v1
        write(*,*) "Vector v1 por componente:   ", v2(1), v2(2), v2(3)
        write(*,*) "Matriz a:                   ", a
        write(*,*) "Componente (1,1) Matriz b:  ", b(1,1)
        write(*,*) "Componente (1,1) Matriz c:  ", c(1,1)


    end program seis