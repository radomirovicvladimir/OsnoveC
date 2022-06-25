/*Element liste*/
typedef struct elem {
	int zgrada;
	int sala;
	int pocetak;
	int kraj;
	struct elem *sled;
} Elem;

/* Upis elemenata u listu. */
Elem *upis(int n);

/* Brisanje svih elemenata liste. */
void brisi(Elem *lst);

/* Izostavljanje odabranog elementa. */
Elem *izostavi(Elem *lst, Elem *lstp);

/* Dodavanje na pocetak liste. */
Elem *na_pocetak(Elem *lst, Elem *lstp);

/* Dodavanje na kraj liste. */
Elem *na_kraj(Elem *lst, Elem *lstp);

/* Ispisivanje liste. */
void pisi(Elem *lst);

/* Obrada liste. */
Elem *obrada(Elem *lst);

/* Sortiranje liste. */
void sort(Elem *lst);