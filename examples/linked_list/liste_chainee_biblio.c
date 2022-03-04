
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




void ajg(Cell **head,int element)
{
   struct Cell *new;
   
   new =  malloc(sizeof(Cell)); 
   new->data = element;
   new->next = (Cell*) *head;
   *head = new; 
}

void ajd(Cell **head,int element)
{
   Cell *new,*p;

   p = *head; 
   
   new= malloc(sizeof(Cell)); 
   new->data = element;
   new->next = NULL;
   
   if (*head == NULL){
       *head=new;
        return;
      } else {
         while (p->next != NULL) p = (Cell*) p->next;
       p->next =  new;  
      }   

}

void construit_liste(Cell** head)
{
  Cell* local;
  Cell* new;
  int x;
 
  /*Lecture du premier élément de la liste initialisation */ 
    scanf("%d",&x);
    new=(Cell*) malloc(sizeof(Cell));
    new->data = x;
    new -> next = NULL;
    local=new;
    *head = new;
  /*lecture du reste de la liste */
   scanf("%d",&x);
   while (x!=-1)
  {
    new=(Cell*)malloc(sizeof(Cell));
    new->data = x;
    new -> next = NULL;
    local->next = new; 
    local = new; 
    scanf("%d",&x);
 }
}

void affiche_liste(Cell* head)
{
  while (head != NULL) 
  { printf("%d, ",head->data);
    head = (Cell*)head->next;
  }
  printf("\n");
}

void retire_element(Cell** head,int elem)
{
   Cell *parcour,*ancien;
   if (! (*head)) return;

   if ((*head)->data==elem){
      parcour = *head; 
      *head = (*head) -> next;
      free(parcour);
      return; 
      };
   
   parcour = *head;
   ancien = *head;
 
   while (parcour && parcour->data != elem) 
         {
            ancien = parcour; 
            parcour = parcour ->next; 
         }

  if (parcour != NULL){
     ancien->next = parcour->next;
     free(parcour);
     }
}
void concat(Cell **liste_1,Cell *liste_2)
{
   Cell *parcour; 
   if (! *liste_1) 
      {*liste_1=liste_2; return;}
   parcour = *liste_1; 
   while (parcour->next != NULL) parcour = parcour -> next;
   parcour -> next = liste_2;
}

Cell *quicksort(Cell *head) // retourne un pointeur donc une addresse de Cell
{
  Cell *inf_p=NULL,*sup_p=NULL,*parcour=NULL;
  Cell *pptit, *pgrand;
  int pivot; 

  if ( head == NULL) return NULL;  // liste de taille 0

  pivot = head->data;
  parcour = head ->next;
  while (parcour){
    if (parcour -> data < pivot) 
        ajg(&inf_p,parcour -> data); 
    else
        ajg(&sup_p,parcour -> data);
    parcour = parcour -> next;
  }

  pptit  = quicksort(inf_p);
  pgrand = quicksort(sup_p);
  ajg(&pgrand,pivot);
  concat(&pptit,pgrand); /*concat(&a,b) rajoute à a tous les éléments de b */

  return(pptit);        /*en faisant pointer le next de la dernière cellule de a sur b */ 
}  

