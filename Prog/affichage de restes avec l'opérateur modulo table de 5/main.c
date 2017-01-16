#include <stdio.h>
#define VALEUR 5
int main()
{
    int a;
    printf("Modulus %d:\n", VALEUR);
    for(a=0;a<30;a++)
        printf("%d %% %d = %d\n",a,VALEUR,a%VALEUR);
    return 0;
}
