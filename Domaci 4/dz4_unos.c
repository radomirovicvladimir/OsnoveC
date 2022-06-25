#include "dz4.h"
#include <stdio.h>
#include <stdlib.h>
/* Upis elemenata u listu. */
Elem *upis(int n) {
	Elem *prvi = NULL, *posl = NULL; int i;
	for (i = 0; i < n; i++) {
		Elem *novi = malloc(sizeof(Elem));
		scanf("%d %d %d %d", &novi->zgrada, &novi->sala, &novi->pocetak, &novi->kraj);
		novi->sled = NULL;
		if (!prvi) prvi = novi;
		else posl->sled = novi;
		posl = novi;
	}
	return prvi;
}
/* Brisanje svih elemenata liste. */
void brisi(Elem *lst) {
	while (lst) {
		Elem *stari = lst;
		lst = lst->sled;
		free(stari);
	}
}
/* Izostavljanje odabranog elementa. */
Elem *izostavi(Elem *lst, Elem *lstp) {
	Elem *tek = lst, *pret = NULL;
	while (tek)
		if ((tek->zgrada != lstp->zgrada) || (tek->sala != lstp->sala) || (tek->pocetak != lstp->pocetak) || (tek->kraj != lstp->kraj)) {
			pret = tek; tek = tek->sled;
		}
		else {
			Elem *stari = tek;
			tek = tek->sled;
			if (!pret) lst = tek;
			else pret->sled = tek;
			free(stari);
		}
	return lst;
}
/* Dodavanje jednog elementa na pocetak. */
Elem *na_pocetak(Elem *lst, Elem *lstp) {
	Elem *novi = malloc(sizeof(Elem));
	novi->zgrada = lstp->zgrada;
	novi->sala = lstp->sala;
	novi->pocetak = lstp->pocetak;
	novi->kraj = lstp->kraj;
	novi->sled = lst;
	return novi;
}
/* Dodavanje jednog elementa na kraj. */
Elem *na_kraj(Elem *lst, Elem *lstp) {
	Elem *novi = malloc(sizeof(Elem));
	novi->zgrada = lstp->zgrada;
	novi->sala = lstp->sala;
	novi->pocetak = lstp->pocetak;
	novi->kraj = lstp->kraj;
	novi->sled = NULL;
	if (!lst) return novi;
	else {
		Elem *tek = lst;
		while (tek->sled) tek = tek->sled;
		tek->sled = novi;
		return lst;
	}
}