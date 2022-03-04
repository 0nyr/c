#include<stdio.h>
#define MAX 100


void qsort(int v[],int left,int right);
void swap (int v[],int i,int j);

void main(){
     int tab[MAX];
     int nb=0,nombre_lu,i; 

     scanf("%d",&nombre_lu);
     while (nombre_lu != -1){  /* stop quand on détecte -1 */
        nb++[tab] = nombre_lu; /* t[n] == *(t+n) == *(n+t) == n[t]... */
        scanf("%d",&nombre_lu);
     }  

     for(i=0;i<nb;i++)
        printf("t[%d]=%4d, ", i,tab[i]);

     printf("\n");

     qsort(tab,0,nb-1); 

     for(i=0;i<nb;i++)
        printf("t[%d]=%4d, ", i,tab[i]);

     printf("\n");
 }

void swap (int v[],int a,int b)
{
   int temp=v[a];
   v[a]=v[b];
   v[b]=temp;
}

void qsort(int v[],int left, int right)
{
  int i, last; 

  if (left>=right) /* rien à faire si le tableau à moins de 2 éléments */
      return; 
  swap(v,left,(left+right)/2); /* mise du pivot en place */
  last = left; 
  for (i = left+1 ; i <=right ; i++) /* partition vis à vis du pivot */
      if (v[i] < v[left])
         swap(v, ++last,i); 
  swap(v, left, last); /* on met le pivot à sa place */
  
  qsort(v,left,last-1);  /* tri récursif des deux parties inf et sup au pivot */
  qsort(v,last+1,right);
}
