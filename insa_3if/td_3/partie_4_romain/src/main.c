
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lchainee.h"


elem* liste = NULL;

void ajouter_en_tete()
{
    int valeur;
    printf("tapez un nombre :\n");
    scanf("%d", &valeur);

    elem* new_elem = (elem*)malloc(sizeof(elem));
    new_elem->value = valeur;
    new_elem->next = liste;
    liste = new_elem;
}


void afficher()
{
    elem* current = liste;
    
    while(current != NULL)
    {
        printf("%i\n", current->value);
        current = current->next;
    }

    printf("fin de la liste\n");
}


void rechercher()
{
    int recherche;
    printf("entrez un nombre :\n");
    scanf("%i", &recherche);


    int pos = 0;
    elem* current = liste;

    while(current != NULL)
    {
        if(current->value == recherche)
        {
            printf("trouvé en indice %i\n", pos);
            return;
        }

        current = current->next;
        pos++;
    }

    printf("pas trouvé\n");
}


void ajouter_en_queue()
{
    int valeur;
    scanf("%d", &valeur);

    elem* new_elem = (elem*)malloc(sizeof(elem));
    new_elem->value = valeur;
    new_elem->next = NULL;

    if(liste != NULL) 
    {
        elem* current = liste;
        while(current->next != NULL) current = current->next;

        current->next = new_elem;
    }
    else
    {
        liste = new_elem;
    }
    
}


int main()
{
    bool continuer = true;

    while(continuer)
    {
        printf("menu:\n");
        printf("\t1: ajouter en tete\n");
        printf("\t2: afficher la liste\n");
        printf("\t3: rechercher un nombre\n");
        printf("\t4: ajouter en queue\n");
        printf("\t0: quitter\n");

        int choix;
        scanf("%d", &choix);

        switch(choix)
        {
            case 0:
                continuer = false;
                break;
            case 1:
                ajouter_en_tete();
                break;
            case 2:
                afficher();
                break;
            case 3:
                rechercher();
                break;
            case 4:
                ajouter_en_queue();
                break;
            default:
                printf("choix incorrect\n");
        }
    }

    printf("au revoir\n");

    return 0;
}