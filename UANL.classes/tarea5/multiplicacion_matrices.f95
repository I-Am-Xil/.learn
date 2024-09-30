!Haga un programa en fortran que lea dos matrices
!verifique si pueden multiplicarse
!las multiplique e imprima la matriz resultante

program veintiuno
    implicit none
    integer n, m, i, j, k
    real m1, m2, m3
    allocatable m1(:,:), m2(:,:), m3(:,:)

    write(*,*) "Este programa lee e imprime el producto de 2 matrices de tamaño n*m"
    write(*,*) ""
    write(*,*) "Ingrese el numero de filas de la primera matriz"
    write(*,*) "El cual será el numero de columnas de la segunda matriz"
    read(*,*) n
    write(*,*) "Ingrese el numero de columnas de la primera matriz"
    write(*,*) "El cual será el numero de filas de la segunda matriz"
    read(*,*) m

    allocate(m1(n,m), m2(m,n), m3(n,n))
    
    m3 = 0


    do i = 1, m
        do j = 1, n
            write(*,*) "Ingrese el valor de la columna", i, "fila", j, "de la matriz A"
            read(*,*) m1(j,i)
            write(*,*) "Ingrese los valores de la fila", i,  "columna", j, "de la matriz B"
            read(*,*) m2(i,j)
        end do
    end do


    do i = 1, n
        write(*,*) m1(i,:)
    end do

    write(*,*) ""

    do i = 1, m
        write(*,*) m2(i,:)
    end do

    write(*,*) ""

    do k = 1, n
        do j = 1, n
            do i = 1, m
                write(*,*) "k,j,i", k, j, i, "=>", m3(k,j), " + ", m1(k,i), " * ", m2(i,j), " = ", m3(k,j) + m1(k,i)*m2(i,j)
                m3(k,j) = m3(k,j) + m1(k,i)*m2(i,j)
            end do
        end do
    end do

    do i = 1, n
        write(*,*) m3(i,:)
    end do

end program veintiuno