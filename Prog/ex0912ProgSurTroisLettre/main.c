#include <stdio.h>

int main()
{
    int alpha,code;

    for(alpha='A'; alpha<='Z'; alpha=alpha+1)
    {
        for(alpha='A'; alpha<='Z'; alpha=alpha+1)
        {

          for(alpha='A'; alpha<='Z'; alpha=alpha+1)
{
     printf("%c%c%c\t", alpha,alpha,alpha);
}
        }
    }
    putchar('\n');
    return 0;
}
