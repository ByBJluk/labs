#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int funkzia_proverki_vvoda()
	{
		int k;
		while(system("pause"),fflush(stdin),system("cls"),printf("введите размер массива : "),scanf("%i",&k)!=1||k>20||k<=0)
			printf("Ошибка! некорректный ввод\n");
		return k;	
	}

void funkzia_vvoda_mass(int a[],int n)
	{
		int i;
		for (i=0;i<n;i++)
			while(printf("a[%i]= ",i),scanf("%i",&a[i])!=1)
				printf("введите значение элемента массива еще раз\n");

			printf("\n");
	}

int funkzia_sort_mass(int a[],int n)
	{
		int i,k=0;
		
		if (a[0]==a[1])
			for (i=0;i<n;i++)
				if (a[i]!=a[0])
					{
						k=i;
						for (k;k<n;k++)
							a[k]=a[k+1];
						n--;
						i--;
					}	
	
		if (a[0]<a[1])
			for (i=0;i<n-1;i++)
				if(a[i]>a[i+1])
					{
						k=i+1;
						for (k;k<n;k++)
							a[k]=a[k+1];
						n--;
						i--;
					}
	
		if (a[0]>a[1])
			for (i=0;i<n-1;i++)
				if(a[i]<a[i+1])
					{
						k=i+1;
						for (k;k<n;k++)
							a[k]=a[k+1];
						n--;
						i--;
					}	
		return n;			
	}

void out_mass(int a[],int n)
	{
		int i;
		for (i=0;i<n;i++)
			printf("a[%i]= %i\n",i,a[i]);
		
	}

int main()
{
	system("chcp 1251>nul");
	int n, a[20]={0};
	
	n=funkzia_proverki_vvoda();
	funkzia_vvoda_mass(a,n);
	n=funkzia_sort_mass(a,n);
	printf("Размер полученного массива: %i\n",n);
	out_mass(a,n);

	system("pause");
	return 0;
	
}
