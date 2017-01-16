#include <stdio.h>

int main()
{
    int cmptr;
    cmptr = 0;
    while(1)
    {
        printf("%d,", cmptr);
        cmptr = cmptr+1;
        if (cmptr>50)
        break;
    }
    putchar('\n');
    return 0;
}
