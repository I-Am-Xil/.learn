#include<stdio.h>

int comparador();
int divisor(int n);



int primo[20];
int no_primo[20];

int main()
{	
    int k = 0, s = 0;
    int n = 20, cont = 0, i;
    if (n > 1)
	{
		int j = 2;
		do{
			for (i = 2; i <= j; ++i)
			{
				if (j%i==0)
				{
					cont++;
				}
			}

			if (cont < 2)
			{
                primo[k] = j;
                printf("%i Es primo\n", primo[k]);
                k++;
			}else
            {
                no_primo[s] = j;
                printf("%i No es primo\n", no_primo[s]);
                s++;
            }
            
			cont = 0;
			j++;
		}while(j <= n);

    }     
    divisor(n);
    return 0;
}

int divisor(int n)
{
    int i = 0, j = 0;
    int factor = 1;
    int s = 0;
    while (s < n)
    {
        j = 0;
        while (j <= s)
        {
            factor = 1;
            while (factor <= no_primo[j])
            {
                if (factor < no_primo[j])
                {
                    factor = factor * primo[i];
                }

                if(factor == no_primo[j])
                {
                    int contador = 20;
                    while (!no_primo[contador])
                    {
                        contador--;
                    }

                    while (no_primo[contador])
                    {
                        if (factor > no_primo[contador])
                        {
                            printf("Valor maximo: %i\n", factor);
                            i++;
                            contador = 20;
                            break;
                        }else
                        {
                            if (no_primo[contador] > factor)
                            {
                                break;
                            }
                            
                        }
                        
                        contador--;
                    }
                    break;
                }
            }
            j++;
        }
        s++;
    }

    return 0;
}

int comparador()
{
    
    return 0;
}