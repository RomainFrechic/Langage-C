#include <stdio.h>

void vegas(void);

int main()
{
    int a;
    a=365;
    printf("Dans la fonction main(),a=%d\n", a);
    vegas();
    printf("De retour dans main(), a=%d\n", a);
    return 0;
}
void vegas(void)
{
    int a;
    a=-10;
    printf("Dans la fonction  vegas(), a=%d\n", a);
}
