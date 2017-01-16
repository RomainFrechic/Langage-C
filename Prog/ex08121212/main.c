#include <stdio.h>

int main()
{
    int a,b, leplusgrand;

    printf("Indiquez une valeur A: ");
    scanf("%d", &a);
    printf("Indiquez une autre valeur B: ");
    scanf("%d", &b);

   if ( a > b)
   {
       printf("%d est plus grand que %d\n", a,b);
   }
   else
   {
       printf("%d n'est pas plus grand que %d\n",a,b);
   }
   return(0);
}
