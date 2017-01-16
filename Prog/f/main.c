#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
#ifndef H_ED_PRT_20070430194145
#define H_ED_PRT_20070430194145

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <limits.h>

#define PRT_LARG "12"

#ifdef WIN32
#include <windows.h>

#define PRT_UL(val)\
   printf ("%-"PRT_LARG"s = %U64X%lX\n", #val, \
         (U64) (((U64) val.HighPart << 32) | val.LowPart))
#endif

#define PRT_SIZE(T)\
   printf ("sizeof %-"PRT_LARG"s = %2u bytes (%u-bit)\n"\
   , #T, (unsigned) sizeof(T), (unsigned) (sizeof(T) * CHAR_BIT))

#define PRT_I(val)\
   printf ("%-"PRT_LARG"s = %ld\n", #val, (long) (val))

#define PRT_U(val)\
   printf ("%-"PRT_LARG"s = %lu\n", #val, (unsigned long) (val))

#define PRT_X(val)\
   printf ("%-"PRT_LARG"s = %08lX\n", #val, (unsigned long) (val))

#define PRT_D(val)\
   printf ("%-"PRT_LARG"s = %.2f\n", #val, (double) (val))

#define PRT_S(val)\
   printf ("%-"PRT_LARG"s = '%s'\n", #val, (val))

#define PRT_P(val)\
   printf ("%-"PRT_LARG"s = %p\n", #val, (void *) (val))

#define PRT_C(val)\
   printf ("%-"PRT_LARG"s = '%c'\n", #val, (val))

#ifdef __cplusplus
}
#endif

