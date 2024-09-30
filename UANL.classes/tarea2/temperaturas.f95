    !Leer 5 temperaturas en Fahrenheit y convertirlas a Celsius y Kelvin
    
    program ocho
        implicit none
        real, dimension(5) :: fahrenheit, celsius, kelvin

        write(*,*) "Este programa lee temperaturas en Fahrenheit e imprime la temperatura en grados centigrados y en Kelvin"
        write(*,*) "Ingrese las 5 temperatura en grados Fahrenheit: "; read(*,*) fahrenheit
        celsius = (fahrenheit-32)*5/9
        kelvin = celsius + 273.15
        write(*,*) "La temperatura en grados fahrenheit  es: ", fahrenheit
        write(*,*) "La temperatura en grados centigrados es: ", celsius
        write(*,*) "La temperatura en kelvin es:             ", kelvin
    end program ocho