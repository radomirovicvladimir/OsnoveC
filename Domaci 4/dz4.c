#include "dz4.h"
#include <stdio.h>
void main() {
	Elem *lst = NULL;
	Elem *lstp = malloc(sizeof(Elem));
	int stop = 0, izbor, broj, n, zgrada, sala, pocetak, kraj;
	while (!stop) {
   printf("\n1. Upis elemenata u listu. \n"
			"2. Brisanje svih elemenata liste. \n"
			"3. Izostavljanje odabrano elementa. \n"
			"4. Dodavanje na pocetak liste. \n"
			"5. Dodavanje na kraj liste. \n"
			"6. Ispisivanje liste. \n"
			"7. Obrada liste. \n"
			"0. Zavrsetak rada. \n\n"
			"Vas izbor? "
		);
		scanf("%d", &izbor);
		switch (izbor) {
		case 1: /* Upis elemenata u listu: */
			printf("Duzina? "); scanf("%d", &n);
			printf("Zgrada,sala,pocetak,kraj?\n"); brisi(lst);
			lst = upis(n); break;
		case 2: /* Brisanje svih elemenata liste: */
			brisi(lst); lst = NULL; break;

			case 3: case 4: case 5:
				printf("Zgrada,sala,pocetak,kraj?\n"); scanf("%d %d %d %d", &lstp->zgrada, &lstp->sala, &lstp->pocetak, &lstp->kraj);
				switch (izbor) {
				case 3: /* Izostavljanje odabranog elementa: */
					lst = izostavi(lst, lstp); break;
				case 4: /* Dodavanje na pocetak liste: */
					lst = na_pocetak(lst, lstp); break;
				case 5: /* Dodavanje na kraj liste: */
					lst = na_kraj(lst, lstp); break;
				}
				break;

		case 6: /* Ispisivanje liste: */
			printf("Lista: \n"); pisi(lst); putchar('\n'); break;
		case 7: /* Obrada liste: */
			lst = obrada(lst); break;
		case 0: /* Zavrsetak rada: */
			stop = 1; break;
		default: /* Pogresan izbor: */
			printf("*** Neozvoljeni izbor! ***\a\n"); break;
		}
	}
}