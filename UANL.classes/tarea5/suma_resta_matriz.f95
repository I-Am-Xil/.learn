!Haga un programa en fortran que le pida al usuario el tamaño de 2 matrices cuadradas
!luego lee las matrices (usando ciclos) y suma y resta las matrices e imprime las matrices resultantes

program veinte
    implicit none
    integer n, i, j
    real m1, m2
    allocatable m1(:,:), m2(:,:)
    write(*,*) "Este programa lee e imprime la suma de 2 matrices cuadradas de igual tamaño"
    write(*,*) "Ingrese el valor de las 2 matrices cuadradas"
    read(*,*) n
    allocate(m1(n,n), m2(n,n))

    do i = 1, n
        do j = 1, n
            write(*,*) "Ingrese los valores de la fila", i, "columna", j, "de la matriz A"
            read(*,*) m1(i,j)
            write(*,*) "Ingrese los valores de la fila", i,  "columna", j, "de la matriz B"
            read(*,*) m2(i,j)
        end do
    end do

    write(*,*) "Suma de matrices:"
    do i = 1, n
        write(*,*) m1(i,:) + m2(i,:)
    end do

    write(*,*) "Resta de matrices:"
    do i = 1, n
        write(*,*) m1(i,:) - m2(i,:)
    end do

end program veinte