#include <stdio.h>
#include <math.h>

int main()
{
    float resultat,valeur;
    printf("Indiquez une valeur fractionnaire : ");
    scanf("%f", &valeur);
    resultat = sqrt(valeur);
    printf("Racine carree de %.2f =%.2f\n", valeur, resultat);
    resultat = pow(valeur,3);
    printf("%.2f puissance cubique = %.2f =%.2f\n", valeur, resultat);
    resultat = floor(valeur);
    printf("Arrondi par defaut de %.2f) %.2f\n", valeur, resultat);
    resultat = ceil(valeur);
    printf("Arrondi par exces de %.2f =%.2f\n", valeur, resultat);

    return 0;
}
