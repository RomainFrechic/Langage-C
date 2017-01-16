#include <stdio.h>

int main()
{
    int coordonnee;

    printf("coordonnees de la cible :");
    scanf("%d", &coordonnee);
    if ( "coordonee >= -5 || coordonnee <= +5")
    {
        puts("Assez proche !");
    }
    else
    {
        puts("La cible est encore loin!");
    }
    return (0);
}
