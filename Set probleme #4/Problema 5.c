#include <stdio.h>

int main()
{
	int v[10], n, i, j, aux, OK;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    ///Metoda Interschimbarii:
    /**
    for(i = 0; i < n; i++)
        for(j = i + 1; j < n - 1; j++)
            if(v[i] < v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    **/
    ///Metoda Bulelor

    do{
        OK = 1;
        for(i = 0; i < n - 1; i++)
            if(v[i] < v[i+1])
            {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                OK = 0;
            }
    }while(OK == 0);

    for(i = 0; i < n; i++)
        printf("%d ", v[i]);

	return 0;
}
