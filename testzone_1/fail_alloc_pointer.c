#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // pour sleep(seconds);
in
/* 
@author : onyr
@date : 21 09 2020
@system : Ubuntu 18.04.5 LTS
@compiler : gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0

exemple de mauvaise utilisation de free(pointeur) 
WARN : quand deux pointeurs renvoient vers la même chose, libérer l'un libère aussi l'autre
car la case renvoyé par les deux pointeurs est détuite 

Mais ATTENTION, ce programme ne marchera pas lancé ainsi : 
❮ onyr ★  kenzae❯ ❮ testzone_1❯❯ MALLOC_CHECK_=1 ./fail_alloc_pointer
The value of a is : 0x55a003e6a010
The value of b is : 0x55a003e6a010
The value of *a is : 2
The value of *b is : 2
*** free(a) ***
The value of a is : 0x55a003e6a010
The value of b is : 0x55a003e6a010
The value of *a is : 0
The value of *b is : 0
free(): invalid pointer
Aborted (core dumped)

En effet, b étant déjà libérer, free(b) est une opération invalide

Le problème, c'est que dans ce programme, lancé normalement, des choses dangeureuses sont permises :
 ❮ onyr ★  kenzae❯ ❮ testzone_1❯❯ gcc fail_alloc_pointer.c -o fail_alloc_pointer
 ❮ onyr ★  kenzae❯ ❮ testzone_1❯❯ ./fail_alloc_pointer 
The value of a is : 0x5618cb783260
The value of b is : 0x5618cb783260
The value of *a is : 2
The value of *b is : 2
*** free(a) ***
*** sleep(8) ***
The value of a is : 0x5618cb783260
The value of b is : 0x5618cb783260
The value of *a is : 0
The value of *b is : 0
*** free(b) ***
The value of a is : 0x5618cb783260
The value of b is : 0x5618cb783260
The value of *a is : 4
The value of *b is : 4

Comment est-ce que la case mémoire n'est pas réellement libérée ? On voit bien que même après
le free(), l'addresse mémoire est conservée dans a et b et que seule la valeur de *a == *b est 
rendue nulle. Donc technquement, free() n'a pas marché ? Que se passe t'il ?
*/


int main () {

	int * a;
	int * b;

	a = (int *) malloc(sizeof(int));
	b = a;
	*b = 1;
	*a = 2;

	printf("The value of a is : %p\n", a);
	printf("The value of b is : %p\n", b);

	printf("The value of *a is : %d\n", *a);
	printf("The value of *b is : %d\n", *b);	
	
	printf("*** free(a) ***\n");
	free(a);
	// WARN : free(a) implique comme b = a que b pointe vers le vide interstellaire 
	
	printf("*** sleep(8) ***\n");
	sleep(8);
	
	printf("The value of a is : %p\n", a);
	printf("The value of b is : %p\n", b);

	printf("The value of *a is : %d\n", *a); // ne renvoie vers rien = 0
	printf("The value of *b is : %d\n", *b); // ne renvoie vers rien = 0
	
	printf("*** free(b) ***\n");
	free(b);

	*b = 3;
	*a = 4;

	printf("The value of a is : %p\n", a);
	printf("The value of b is : %p\n", b);

	printf("The value of *a is : %d\n", *a);
	printf("The value of *b is : %d\n", *b);

	return 0;
}
