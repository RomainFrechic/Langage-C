#include <stdlib.h>

#include <stdio.h>


typedef enum {coeur, carreau, pique, trefle} color_type ;

typedef enum {AS, ROI, DAME, VALET, DIX, NEUF, HUIT, SEPT, SIX, CINQ, QUATRE, TROIS, DEUX} value_type ;

typedef struct

{
 color_type color ;

 value_type value ;

} card_type ;
char* traduit_value(int value)
 {
  char* types_string[] = { "As",

               "Roi",

               "Dame",

               "Valet",

               "Dix",

               "Neuf",

               "Huit",

               "Sept",

               "Six",

               "Cinq",

               "Quatre",

               "Trois",

               "Deux"};





  if (value>-1 && value<14) {

    return types_string[value]; }

  return "erreur";

}


void affiche (card_type * card){
char* value_aff = NULL;
value_aff= traduit_value(card->value);
printf("\n Type :%s\n", value_aff);

}


int main (void) {
  card_type My_Card = {coeur, AS};
  card_type*  card = &My_Card;
  affiche(card);
  exit(0);

}

