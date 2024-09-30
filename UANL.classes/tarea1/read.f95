    program tres
        implicit none
        character*20 nombre
        integer numero

        print*, "Este programa lee un nombre y un numero"
        write(*,*) "Escriba su nombre"
        read (*,*) nombre

        write(*,*) "Dame un numero entero en el rango [0-100]"
        read(*,*) numero

        !write(*,*) "Su nombre es: ", nombre
        !write(*,*) "Su numero es: ", numero

    end program tres