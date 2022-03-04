void concat(Cell**,Cell*);

void ajg(Cell**,int);
  /* ajg(l,e) ajoute l'élément e à gauche dans la liste l */

void ajd(Cell**,int); 
  /* ajd(l,e) ajoute l'élément e à droite dans la liste l */
  
void construit_liste(Cell**);
  /* construit_liste(l) construit une liste d'entiers positifs en 
     ordonnant les valeurs entrées de la gauche vers la droite */
 
void affiche_liste(Cell*);
  /* affiche_liste(l) affiche la liste pointée par l */

void retire_element(Cell**,int);
  /* retire_element(l,e) enlève la première occurence de e dans la liste
    pointée par l */

Cell  *quicksort(Cell*); 
  /* quicksort(l)  retourne un pointeur verus une liste l2 qui contient les éléments de l rangés par ordre croissant */
