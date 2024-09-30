!haga un programa que imprima sin formato los sig. numeros y palabras
!14352, -4356, -3890.567798, 56789999.00097, formato ,fin
!despues imprimirlas con el sig formato: formato(i5,1x,i4,1x,2f10.2,2x,2A7)
!despues imprimirlas con el formato mas conveniente

program veintidos
    implicit none

    101 format(i5,1x,i4,1x,2f10.2,2x,2A7)
    102 format(i5,1x,i5,1x,f8.2,1x,f11.2,x,2A7)
    
    write(*,*) 14352, -4356, -3890.567798, 56789999.00097, "formato" ,"fin"
    write(*,101) 14352, -4356, -3890.567798, 56789999.00097, "formato" ,"fin"
    write(*,102) 14352, -4356, -3890.567798, 56789999.00097, "formato" ,"fin"

end program veintidos