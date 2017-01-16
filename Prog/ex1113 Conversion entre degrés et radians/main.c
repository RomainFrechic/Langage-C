#include <stdio.h>

int main()
{
    float degres, radians;
    printf("Indiquez un angle en degres : ");
    scanf("%f", &degres);
    radians = 0.0174532925*degres;
    printf("%.2f degres valent %.2f radians.\n", degres, radians);
    return 0;
}
