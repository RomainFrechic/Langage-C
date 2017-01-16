#include <stdio.h>


int main()
{
    int c;
    printf("j'attends trois lettres :");
    c = getc(stdin);
    printf("les trois lettres sont 'a','b', et 'c'.\n");
    return 0;
}
