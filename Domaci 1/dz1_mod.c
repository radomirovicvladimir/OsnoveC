#include<stdio.h>
#define MAX 100
main()
{
	while (1)
	{
		int n, i, j, s = 0, sort, temp;
		int a[MAX];

		printf("Unesite broj elemenata niza: ");
		scanf("%d", &n);

		if (n >= 0 && n <= MAX)
		{
			printf("Unesite elemente niza: ");
			for (i = 0; i < n; i++) scanf("%d", &a[i]);

			printf("Nacin sortiranja: 1-Neopadajuci  0-Nerastuci: ");
			scanf("%d", &sort);
			switch (sort)
			{

			case 1:
				for (i = 0; i < n; i++)
					for (j = i + 1; j < n; j++)
						if (a[i] > a[j])
						{
							temp = a[i];
							a[i] = a[j];
							a[j] = temp;
						} 
				
				for (i = 0; i < n; i++) printf("%d ", a[i]);

				break;
			case 0:
				for (i = 0; i < n; i++)
					for (j = i + 1; j < n; j++)
						if (a[i] < a[j])
						{
							temp = a[i];
							a[i] = a[j];
							a[j] = temp;
						} 
				for (i = 0; i < n; i++) printf("%d", a[i]);

				break;
			default:
				printf("Uneli ste nevazeci broj,niz nece biti sortiran\n");break;

			}

			for (i = 0; i < n - 1; i++)
			{
				for (j = i + 1; j < n; j++)
					if (a[i] <= a[j])
						break;
				if (j == n) s++;
			}

			printf("\nIma %d vodja\n", s);
		}
		else return 0;
	}
}