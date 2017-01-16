#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define LONGUEURONDE 70
#define PERIODE .1

int main()
{
    float graph,s,x;
    for (graph=0;graph<PI;graph+=PERIODE)
    {
        s=sin(graph);
        for(x=0;x<s*LONGUEURONDE;x++)
        putchar('*');
        putchar('\n');
    }
    return 0;
}
