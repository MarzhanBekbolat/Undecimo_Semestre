# include <stdio.h>

int main ()
{

int lim,triang[200][200],L,C;

printf ("\nIngrese el límite de filas: \n\n");
scanf ("%d",&lim  );

for (L=0; (L<lim); L++)
	{
	for (C=0; (C<=L); C++)
		{
		if ((C==0) || (L==C))
			{
			triang[L][C]=1;
			}
			else
			{
			triang[L][C]=triang[L-1][C]+triang[L-1][C-1];
			}
		}
	}
for (L=0; (L<lim); L++)
	{
	for (C=0; (C<=L); C++)
		{
		printf ("%d ",triang[L][C]);
		}
	printf ("\n\n");
	}

}



