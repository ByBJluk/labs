#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	system("chcp 1251>nul");
	
	int n,k,i,a[20]={0};
	
	while(system("pause"),fflush(stdin),system("cls"),printf("введите размер массива : "),scanf("%i",&n)!=1||n>20||n<=0)
		printf("Ошибка! некорректный ввод\n");
	
	for (i=0;i<n;i++)
		while(printf("a[%i]= ",i),scanf("%i",&a[i])!=1)
			printf("введите значение элемента массива еще раз\n");
	
	printf("\n");
	
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

	printf("Размер полученного массива: %i\n",n);
	
	for (i=0;i<n;i++)
		printf("a[%i]= %i\n",i,a[i]);
	

	system("pause");
	return 0;
	
}
