!La teoria de la relatividad de einstein relaciona la masa y la energia en la ec.: E=mc^2
!Suponga que una estacion nuclear genera 400MW
!Escriba un programa en fortran que calcule la cantidad de masa consumida en el transcurso de un año

program nueve
    implicit none
    
    real E, c, m, tiempo, potencia
    potencia = 400E06 ![j/s]
    tiempo = 31536000 ![s]
    E = potencia*tiempo ![j]
    c = 2.9979E08 ![m/s]
    m = E/(c**2) ![kg]

    write(*,*) "La masa consumida por la planta en un año es: ", m, "kg"

end program nueve