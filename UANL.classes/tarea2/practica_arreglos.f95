    !vector int 5 posiciones y matriz real 2x2
    !imprima la suma 5 elementos del vector
    ! imprimir los 4 elementos matriz
    
    program cinco
        implicit none
        integer, dimension(5) :: v
        real, dimension(2,2) :: m
        integer suma_v

        write(*,*) "Ingrese los 5 datos enteros del vector separados por espacios"
        read(*,*) v(1), v(2), v(3), v(4), v(5)

        suma_v = v(1) + v(2) + v(3) + v(4) + v(5)

        write(*,*) "Ingrese los 2 elementos de la primera fila de la matriz separados por espacios"
        read(*,*) m(1,1), m(1,2)

        write(*,*) "Ingrese los 2 elementos de la segunda fila de la matriz separados por espacios"
        read(*,*) m(2,1), m(2,2)


        write(*,*) "Suma elementos del vector: ", suma_v
        
        write(*,*) "Elementos de la matriz: ", m(1,1), m(1,2), m(2,1), m(2,2)
    end program cinco