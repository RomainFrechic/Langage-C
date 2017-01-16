#include <stdio.h>

float convertir(float f);

int main()
{
    float temp_f;
    printf("Temperature en Fahrenheit:");
    scanf("%f", &temp_f);
    printf("%.1fF vaut %.1fC\n", temp_f, convertir(temp_f));
    return 0;

}
float convertir(float f)
{
    return(f-32)/1.8;
}
