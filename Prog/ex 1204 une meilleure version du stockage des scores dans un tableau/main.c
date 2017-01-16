#include <stdio.h>
#include <stdlib.h>

int main()
{
    int scoremax [4];
    int x;
    for(x=0;x<4;x++)
    {
        printf("votre score #%d : ", x+1);
        scanf("%d", &scoremax[x]);
    }
    puts("voici vos meilleurs scores");
    for(x=0;x<4;x++)
    printf("#%d %d\n", x+1, scoremax[x]);
    return 0;
}
