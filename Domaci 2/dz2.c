/* Vladimir Radomirovic 2018/0474
	insta: dovlaa__
*/
#include<stdio.h>
#include<stdlib.h>
main()
{
	int **a, **gornja, **donja, i, j, n, s=0;
	while (1)
	{
		printf("\nUnesi rang kvadrate matrice: ");
		scanf("%d", &n);
			if (n <= 0) break;

		//Alociranje memorije za matrice tacnije za redove matrica
		a = malloc(n * sizeof(int*));
		gornja = calloc(n, sizeof(int*));
		donja = calloc(n, sizeof(int*));

		//Ispitivanje uspesnosti dodele dinamicke memorije
		if (a == NULL || gornja == NULL || donja == NULL)
		{
			printf("Neuspesna dodela dinamicke memorije");
			return 0;
		}
		for (i = 0; i < n; i++)
		{
			//Alociranje memorije za kolone matrica
			a[i] = malloc(n * sizeof(int));//*(a+i)=malloc(n*sizeof(int));
			gornja[i] = calloc(n, sizeof(int));
			donja[i] = calloc(n, sizeof(int));

			//Unos Elemenata u niz  I sabiranje traga matrice
			printf("%d vrsta: ", i+1);
			for (j = 0; j < n; j++)
			{
				scanf("%d", &a[i][j]);
				if (i == j) s += a[i][j];
			}
		}
		
		//Ispis unete matrice
		for (i = 0; i < n; i++)
		{
			printf("\n");
			for (j = 0; j < n; j++)
				printf("%5d", a[i][j]);
		}
		
		//Ispitivanje vrednosti glavne dijagonale i formiranje trougaonih matrica
		if (s > 0)
		{
			for(i=0;i<n;i++)
				for (j = 0; j < n; j++)
				{
					if (i > j)
						donja[i][j] = a[i][j];
					else
						gornja[i][j] = a[i][j];
				}
		}
		else
		{
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					if (i < j)
						gornja[i][j] = a[i][j];
					else
						donja[i][j] = a[i][j];
				}
		}

		//Ispisivanje Gornje i Donje trougaone matrice
		printf("\nDonje trougaona matrica:");
		for (i = 0; i < n; i++)
		{
			printf("\n");
			for (j = 0; j < n; j++)
				printf("%5d", donja[i][j]);
		}
		printf("\nGornje trougaona matrica:");
		for (i = 0; i < n; i++)
		{
			printf("\n");
			for (j = 0; j < n; j++)
				printf("%5d", gornja[i][j]);
			
		}
		
		//Oslobadjanje prostora
		for (i = 0; i < n; i++)
		{
			free(a[i]);		free(gornja[i]);	free(donja[i]);
		}
		free(a);	free(gornja);	free(donja);
	}
}
