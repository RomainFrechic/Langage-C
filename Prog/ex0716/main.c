#include <stdio.h>


int main()
{
    char personne [10];

    printf("Qui etes-vous \? ");
    fgets(personne, 10, stdin);
    printf("Heureux de vous rencontrez, %s\n", personne);
    return 0;
}
