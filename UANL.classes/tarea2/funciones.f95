    !Programa en fortran lea 3 numeros
    !Con funciones intrincecas en fortran, realize varias operaciones e imprima su resultado
    !utilize al menos 3 veces cada numero y 5 funciones intrinsecas
    
    program siete
        implicit none
        real a, b, c, x, y, z
        write(*,*) "Ingrese el valor de x"
        read(*,*) x
        write(*,*) "Ingrese el valor de y"
        read(*,*) y
        write(*,*) "Ingrese el valor de z"
        read(*,*) z

        a = sqrt(x**2 + y**2 + z**2)
        b = tan(mod(mod(x,y),z))
        c = z*(((sin(y)*cos(x)) + (sin(x)*cos(y))))

        write(*,*) "la longitud del vector a es: ", a
        write(*,*) "la Tangente del residuo de la divison de (x/y)/z es: ", b
        write(*,*) "z veces el producto de la suma del seno de x mas y es: ", c

        
    end program siete