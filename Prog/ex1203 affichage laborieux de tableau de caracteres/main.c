#include <stdio.h>
#include <stdlib.h>

int main()
{
    char phrase[] = "texte insignifiant";
    int index;

    index = 0;
    while(phrase[index] != '\0')
{
    putchar(phrase[index]);
    index++;
}
    putchar('\n');
    return 0;
}
