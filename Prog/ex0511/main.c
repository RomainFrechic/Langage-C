#include <stdio.h>

#define VALEUR 5

int main()
{
    printf("La valeur est %d\n",          VALEUR);
    printf("et %d est bien la valeur \n",      VALEUR);
    printf("Ce n'est pas %d, \n",    VALEUR+1);
    printf("Ni %d non plus.\n",          VALEUR-1);
    printf("Non, la valeur reste %d. \n",    VALEUR);

    return 0;
}
