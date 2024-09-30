    program cuatro
        implicit none
        real, dimension(3) :: v
        real suma

        v(1) = 3.1415
        v(2) = 41
        v(3) = 0.0021

        suma = v(1) + v(2)

        write(*,*) suma
    end program cuatro