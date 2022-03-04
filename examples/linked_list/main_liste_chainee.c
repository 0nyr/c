#ifndef TYPES
#define TYPES
    #include "types.h" 
#endif

#ifndef STDIO 
#define STDIO
    #include <stdio.h> 
#endif

#ifndef STDLIB 
#define STDLIB
    #include <stdlib.h> 
#endif

#include "liste_chainee_biblio.h"


void main(){
  Cell* l,*liste_triee,*new=NULL;

  l=NULL;
  ajd(&l,2);
  ajd(&l,123);
  ajd(&l,5);
  ajd(&l,-8);
  ajd(&l,34);
  ajd(&l,47);
  ajd(&l,7); 
  affiche_liste(l);
  liste_triee = quicksort(l);
  affiche_liste(liste_triee);
  concat(&liste_triee,l);
  affiche_liste(liste_triee); 
  retire_element(&liste_triee,34); 
  affiche_liste(liste_triee);  

}


