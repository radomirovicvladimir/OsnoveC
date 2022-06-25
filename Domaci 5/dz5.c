/* Vladimir Radomirovic  2018/0474 
	insta:dovlaa__
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "dz5.h"
#define FPS 25
int main(int argc, char * argv[])
{
	Elem *lst = NULL;
	int pomeraj = atoi(argv[3]);
	float a, b;
	FILE *ulaz, *izlaz;
	if (NULL == (ulaz = fopen(argv[1], "r"))) {
		fprintf(stderr,
			"Doslo je do greske pri otvaranju %s\n", argv[1]);
		return 1;
	}
	if (NULL == (izlaz = fopen(argv[2], "w"))) {
		fprintf(stderr,
			"Doslo je do greske pri otvaranju %s\n", argv[2]);
		return 2;
	}
	lst = ucitaj(ulaz);
	lst = procesuiranje(lst,pomeraj);
	detence(izlaz,lst);
	pisi(lst);

	fclose(ulaz);
	fclose(izlaz);
	system("pause");
}
