#include "dz4.h"
#include <stdio.h>
/* Ispisivanje liste. */
void pisi(Elem *lst) {
	while (lst) {
		printf("%d %d %d %d \n", lst->zgrada, lst->sala, lst->pocetak, lst->kraj);
		lst = lst->sled;
	}
}