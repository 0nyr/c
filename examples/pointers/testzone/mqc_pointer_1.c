#include <stdio.h>
#include <stdlib.h>

/* this program is not correctly using pointers, no malloc()
munmap_chunk(): invalid pointer
Aborted (core dumped) */


int main () {

	int * p;
	int val;
	p = &val;
	*p = 1;
	free(p);
	
	return 0;
}
