#include "dz4.h"
#include <stdio.h>
#include <stdlib.h>

/* Sortiranje liste. */
void sort(Elem *lst) {
	Elem *i, *j;
	Elem *novi = malloc(sizeof(Elem));
	for (i = lst; i; i = i->sled)
		for (j = i->sled; j; j = j->sled)
			if (j->pocetak < i->pocetak)
			{
				novi->zgrada = i->zgrada;
				novi->sala = i->sala;
				novi->pocetak = i->pocetak;
				novi->kraj = i->kraj;

				i->zgrada = j->zgrada;
				i->sala = j->sala;
				i->pocetak = j->pocetak;
				i->kraj = j->kraj;

				j->zgrada = novi->zgrada;
				j->sala = novi->sala;
				j->pocetak = novi->pocetak;
				j->kraj = novi->kraj;
			}
}
/* Obrada liste. */
Elem *obrada(Elem *lst) {
	int prek = 0;
	sort(lst);
	Elem *tek = lst, *novi = lst->sled, *staro, *mesto = NULL;
	printf("\nTermini koji se preklapaju: \n");
	while (novi)
	{
		if ((novi->pocetak >= tek->pocetak) && (novi->pocetak < tek->kraj))
		{
			if ((novi->pocetak == tek->pocetak) && (novi->sala == mesto->sala) && (tek->sala != mesto->sala)) {
				if (prek == 0) { printf("%d %d %d %d\n", tek->zgrada, tek->sala, tek->pocetak, tek->kraj); prek = 1; }
				printf("%d %d %d %d\n", novi->zgrada, novi->sala, novi->pocetak, novi->kraj);
				staro = tek;
				tek = novi;
				novi = novi->sled;
				lst = izostavi(lst, staro);
			}
			else {
				if (prek == 0) { printf("%d %d %d %d\n", tek->zgrada, tek->sala, tek->pocetak, tek->kraj); prek = 1; }
				printf("%d %d %d %d\n", novi->zgrada, novi->sala, novi->pocetak, novi->kraj);
				staro = novi;
				novi = novi->sled;
				lst = izostavi(lst, staro);
			}
		}
		else
		{
			mesto = tek;
			tek = novi;
			novi = novi->sled;
			prek = 0;
		}
	}
	return lst;
}