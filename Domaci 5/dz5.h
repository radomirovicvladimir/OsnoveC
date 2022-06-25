#include<stdio.h>
#define MAX_LEN 200 
typedef struct titl {
	float vp;
	float vk;
	char text[MAX_LEN];
}Titl;
typedef struct elem {
	struct elem *sled, *pret;
	Titl *titl;
}Elem;

Elem *ucitaj(FILE *ulaz);
Elem *procesuiranje(Elem *lst,int b);
void pisi(Elem *lst);
void *detence(FILE *izlaz);
