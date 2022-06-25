/*Vladimir Radomirovic 2018/0474
	insta: dovla__
*/

#include<stdio.h>
#define MAX 100
main()
{
	while (1)
	{
		int n, i, j, s=0;
		int a[MAX];

		printf("Unesite broj elemenata niza: ");
		scanf("%d", &n);

		if (n >= 0 && n <= MAX)
		{
			printf("Unesite elemente niza: ");
			for (i = 0; i < n; i++) scanf("%d", &a[i]);


			for (i = 0; i < n - 1; i++)
			{
				for (j = i + 1; j < n; j++)
					if (a[i] <= a[j])
						break;
				if (j == n) s++;
			}
				
			printf("Ima %d vodja\n", s);
		}
		else return 0;
	}
}
