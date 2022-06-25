/* Vladimir Radomirovic 2018/0474
	insta: dovlaa__
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100
main()
{
	int l, i;
	char *s, *p, z;

	while (1)
	{

		s = calloc(MAX, sizeof(char));
		if (s == NULL) { printf("Greska prilikom dodele memorije"); break; }

		for (l = 0; l < MAX - 1; l++) if ((*(s + l) = getchar()) == '\n') break;
		*(s + l) = '\0';

		if (s == NULL) { printf("Greska prilikom realociranja memorije\n"); continue; }

		if (strcmp(s, "dosta Brus Li") == 0) break;
		printf("%s", s);

		//if
		s = realloc(s, strlen(s) + 3); if (s == NULL) { printf("Greska prilikom realociranja memorije"); break; }
		p = strstr(s, "if");
		if (*(p + 3) != '(')
		{
			for (i = strlen(p); i > 2; i--) *(p + i) = *(p + i - 1);
			*(p + 3) = '(';
		}
		//begin
		p = strstr(s, "begin");
		*p = '{';
		strcpy(p + 1, p + 5);
		s = realloc(s, strlen(s) + 2); if (s == NULL) { printf("Greska prilikom realociranja memorije"); break; }
		//end
		p = strstr(s, "end");
		*p = '}';
		strcpy(p + 1, p + 3);
		s = realloc(s, strlen(s) + 2); if (s == NULL) { printf("Greska prilikom realociranja memorije"); break; }
		//then
		p = strstr(s, "then");
		if (*(p - 2) != ')') *(p - 1) = ')';
		strcpy(p, p + 4);
		s = realloc(s, strlen(s) + 2); if (s == NULL) { printf("Greska prilikom realociranja memorije"); break; }

		printf("\n%s\n", s);
		free(s);
	}
	return 0;
}