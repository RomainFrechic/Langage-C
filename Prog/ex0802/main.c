#include <stdio.h>
#include <stdlib.h>

int main()
{
    int premier, second;
    printf("Indiquer la valeur de premier : ");
    scanf("%d",&premier);
    printf("Indiquer la valeur de second : ");
    scanf("%d", &second);
    puts("Evaluation en cours...");
    if(premier<second)
    {
        printf("%d est plus petit que %d\n", premier,second);
    }
    else
    {
        printf("%d est plus grand que %d\n", premier,second);
    }
    return 0;
}
