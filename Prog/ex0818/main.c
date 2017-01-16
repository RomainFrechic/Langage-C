#include <stdio.h>

int main()
{

    int code;

    printf("Indiquez le code erreur (A-B):");
    scanf("%c",&code);

    switch(code)
    {
    case 'A':
        puts("Erreur disque, vous n'y pouvez rien.");
        break;
    case 'B':
        puts("Format invalide, appelez votre avocat.");
    case 'C':
        puts("Nom de fichier incorrect, spank it.");
        break;
    default:
        puts("Haha, ni A, ni B, ni C ?");
    }
    return 0;
}
