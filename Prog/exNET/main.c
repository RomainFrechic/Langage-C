#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int indice;

  if(argc != 2){
    printf("erreur");
    exit(1);
  }

  indice = 0;
  while(argv[1][indice] != '\0'){
    indice++;
  }

  printf("le mot %s contient %d lettres\n", argv[1], indice);

  return 0;
}
