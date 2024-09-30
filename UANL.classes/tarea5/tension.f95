!Un objeto de 200kg cuelga al final de una barra rígida de tres metros de largo y de peso despreciable como se muestra en la figura.
!La barra esta fija a la pared por un pivote y esta soportada por un cable de 3 metros también fijo a la pared pero en un punto más alto.
!La tensión sobre este cable está dada por la ecuación *Ver Imagen* Donde T es la tensión sobre el cable, W es el peso del objeto, lc es la longitud del cable, lp es la longitud de la barra y d es la distancia de la pared a donde se une la barra con el cable.
!Haga un programa que determine la distancia d que minimice la tensión en el cable.
!Para hacer esto, el programa va a calcular la tensión en el cable variando d desde 0.5m hasta 2.8m variando de 0.1m en 0.1 m.

program veinte
    implicit none
    real lc, lp, d, t, w

    w = 200*9.8
    lc = 3
    lp = 3
    d = 0.5

    do while(d <= 2.8)
        t = (w*lc*lp)/(d*sqrt(lp**2-d**2))
        write(*,*) "El Valor de la tension en el cable con d = ", d, "m, es:", t;
        d = d + 0.1
    end do
end program veinte