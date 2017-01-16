#include <stdio.h>

#define SECRET 17
int main()
{
    int premier, second;

    printf("indiquer la valeur de premier : ");
    scanf("%d", &premier);
    printf("indiquer la valeur de second : ");
    scanf("%d",&second);

    puts("Evaluation en cours...");
    if(premier < second)
    {
        printf("%d est plus petit que %d\n", premier, second);

    }
    if (premier > second)
    {
        printf("%d est plus grand que %d\n", premier, second);
    }
    return 0;
}
