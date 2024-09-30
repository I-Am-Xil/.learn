!Un gas ideal es aquel en el cual todas las colisiones entre moléculas son perfectamente elásticas.
!Tal gas puede ser caracterizado por tres cantidades, Presión absoluta (P), Volumen (v) y temperatura absoluta (T).
!La relación entre estas tres cantidades se conoce como Ley del gas Ideal y es: PV=nRT

!Donde P esta en kPa (kilo pascales) , V en litros, T en Kelvin, n es la cantidad de moléculas en moles y R la constante Universal de los Gases  8.314 L .KPa/mol. K
!Asuma que una muestra de un gas ideal contiene 1 mol de moléculas a 273 K
!Haga un programa en fortran que calcule e imprima el Volumen de este gas si la presión se varia de 1 kPa  a 1001 kPa en pasos de 100 kPa.
!Hágalo con un ciclo do normal y con un ciclo do while(

program dieciseis
    implicit none
    real v, t, n, r
    integer p

    n = 1
    r = 8.314 !KPa/mol
    t = 273
    p = 1 !Aumentar hasta 1001 en pasos de 100

    do p = 1, 1001, 100
        v = (n*r*t)/p

        write(*,*) "El volumen del gas para p = ", p, "es de: ", v
    end do

end program dieciseis