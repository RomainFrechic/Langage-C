#include <stdio.h>
#include <stdlib.h>

int main()
{
    int scoremax1, scoremax2, scoremax3;
    printf("votre meilleurs score:");
    scanf("%d", &scoremax1);
    printf("second meilleur score:");
    scanf("%d", &scoremax2);
    printf("troisieme meilleur score:");
    scanf("%d", &scoremax3);

    puts("voici vos meilleurs scores:");
    printf("#1 %d\n", scoremax1);
    printf("#2 %d\n", scoremax2);
    printf("#3 %d\n", scoremax3);
    return 0;
}
