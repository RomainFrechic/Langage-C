#include <stdio.h>
#include <stdlib.h>

int main()
{

    char prenom [16];
    printf("quel est votre prenom ?");
    fgets(prenom,16, stdin);
    printf("ravi de vous rencontrer, %s\n", prenom);
    return 0;
}
