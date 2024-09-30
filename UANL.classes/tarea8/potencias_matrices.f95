!Haga un programa en fortran que calcule la potencia k de una matriz cuadrada nxn, donde n, los datos de la matriz y k están dados por el usuario.

program veintisiete
    implicit none
    integer n, i, j, potencia, contador_potencia
    real m1, m2, m3

    allocatable m1(:,:), m2(:,:), m3(:,:)

    write(*,*) "Ingrese el numero de filas de la matriz cuadrada"
    read(*,*) n
    allocate(m1(n,n), m2(n,n), m3(n,n))

    potencia = 1

    do while(potencia <= 1)
        write(*,*) "Ingrese la potencia a la que desea elevar la matriz"
        read(*,*) potencia
    end do

    do i = 1, n
        do j = 1, n
            write(*,*) "Ingrese el valor de la fila ", i, "columna", j
            read(*,*) m1(i,j)   
        end do
    end do

    m2 = m1

    do contador_potencia = 1, potencia-1
        call multiplicacion(n, m1, m2, m3)
    end do


end program veintisiete

subroutine multiplicacion(n, m1, m2, m3)
    implicit none

    integer n, k, i, j
    real, dimension(n,n) :: m1, m2, m3

    m3 = 0

    do k = 1, n
        do j = 1, n
            do i = 1, n
                write(*,*) "k,j,i", k, j, i, "=>", m3(k,j), " + ", m1(k,i), " * ", m2(i,j), " = ", m3(k,j) + m1(k,i)*m2(i,j)
                m3(k,j) = m3(k,j) + m1(k,i)*m2(i,j)
            end do
        end do
    end do

    do i = 1, n
        write(*,*) m3(i,:)
    end do

    m2 = m3

end subroutine