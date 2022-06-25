#include "dz5.h"
#include<stdio.h>
#include<stdlib.h>
#define FPS 25
Elem *ucitaj(FILE *ulaz)
{
	Elem *prvi = NULL, *novi, *posl = NULL;
	float vp, vk;
	char titl[MAX_LEN];
	int ret,i=0,k;
	//fscanf(ulaz, "%f %f", &novi->titl->vp, &novi->titl->vk);

	//printf("%f %f", novi->titl->vp, novi->titl->vk);
	while ((ret = fscanf(ulaz, "%f %f", &vp, &vk)) > 0) {
		novi = (Elem *)malloc(sizeof(Elem));
		novi->titl = (Titl *)malloc(sizeof(Titl)); 
		if (!novi) return 2;
		novi->titl->vp = vp;
		novi->titl->vk = vk;

		k = fgetc(ulaz);
		while (1)
		{
			fscanf(ulaz,"%c", &novi->titl->text[i]);
			if (novi->titl->text[i] == '\n')
			{
				break;
			}
			i++;
		}
		if ((k = fgetc(ulaz)) == EOF) {
			novi->titl->text[i] = '\0';
			break;
		}
		if (k != '\n')
		{
			i++;
			novi->titl->text[i] = k;
			i++;
			while (1)
			{
				fscanf(ulaz, "%c", &novi->titl->text[i]);
				if (novi->titl->text[i] == '\n')
				{
					break;
				}
				i++;
			}
		}
		novi->titl->text[i] = '\0';
		i = 0;




		novi->sled = NULL;
		if (!prvi) prvi = novi;
		else posl->sled = novi;
		posl = novi;
	}
	return prvi;
}
Elem *procesuiranje(Elem *lst,int b)
{
	Elem *prvi = lst;
	int brojac = 0;
	size_t n = sizeof(lst->titl->text) / sizeof(lst->titl->text[0]);
	while (lst) {
		brojac = brojac + lst->titl->vp+b;
		if (brojac < 0) exit(1);
		lst->titl->vp = FPS * brojac;
		brojac = brojac + lst->titl->vk+b;
		if (brojac < 0) exit(2);
		lst->titl->vk = FPS * brojac;
		for (int i = 0; i < n; i++)
		{
			if (lst->titl->text[i] == '\n')
				lst->titl->text[i] = '|';
		}
		lst = lst->sled;
	}
	return prvi;
}
void *detence(FILE *izlaz,Elem *lst)
{
	Elem *prvi = lst;
	int x, y;
	while (lst) {
		x = (int)lst->titl->vp;
		y = (int)lst->titl->vk;
		fprintf(izlaz,"{%d}{%d}%s\n", x,y,lst->titl->text);
		lst = lst->sled;
	}
	lst = prvi;
}
void pisi(Elem *lst) {
	while (lst) {
		printf("%f  %f\n", lst->titl->vp,lst->titl->vk);
		printf("%s\n", lst->titl->text);
		lst = lst->sled;
	}
}