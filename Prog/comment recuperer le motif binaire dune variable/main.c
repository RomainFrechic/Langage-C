
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


char * get_binary (unsigned int val, size_t * tab_size)
{
   size_t size = sizeof (unsigned int) * CHAR_BIT;    /* Taille du type.      */
   size_t i = 0;
   char * tab = NULL;


   tab = malloc (size);

   if (tab != NULL)
   {
      for (i = 0; i < size; i++)
      {
         /*
          * On recupere les bits de la variable un par un en commencant
          * par les bits de poids faible (bits de droite) mais on les insere
          * dans le sens de lecture normal d'un etre humain soit de gauche
          * a droite.
          */
         tab[size - i - 1] = (val << (size - i - 1)) >> (size - 1);
      }

      if (tab_size != NULL)
      {
         *tab_size = size;
      }
   }


   return tab;
}


int main (void)
{
   char * tab = NULL;
   size_t size = 0;
   size_t i = 0;


   tab = get_binary (29, & size);

   if (tab != NULL)
   {
      for (i = 0; i < size; i++)
      {
         printf ("%d", tab[i]);
      }
      printf ("\n");
   }

   free (tab);


   return EXIT_SUCCESS;
}
