#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	system("chcp 1251>nul");
	
	int a[15][15]={0}, i, s, j, kp, m, n;
	
	while(system("pause"),fflush(stdin),system("cls"),printf("введите размер матрицы(m*n) : "),scanf("%i%i",&m,&n)!=2||n>15||n<=1||m>15||m<=1)
		printf("Ошибка! некорректный ввод\n");
	
	for(j=0;j<m;j++)
		for (i=0;i<n;i++)
			while(printf("a[%i][%i]= ",j,i),scanf("%i",&a[j][i])!=1||(a[j][i]!=1 && a[j][i]!=0))
				printf("введите значение элемента матрицы еще раз\n");
	
	printf("\n");
	
	for(j=0;j<m;printf("\n"),j++)
		for (i=0;i<n;i++)
			printf(" %i ",a[j][i]);
	
	printf("\n");
	
	for(j=0;j<m;j++)
		for (i=0;i<n;i++)
			if(a[j][i]==1 &&(( a[j-1][i]==0 && a[j][i-1]==0 && a[j-1][i-1]==0)||(i==0 && a[j-1][i]==0)||(j==0 && a[j][i-1]==0)))
			{
				int kj, ki, i1, j1;
				kj=0;
				ki=0;
				i1=i;
				j1=j;
				kp=0;
				
				for(j1;a[j1][i]==1;j1++);
				
				for(i1;a[j][i1]==1;i1++);

				s=j1*i1;
				
				for(s;s>=0;s--)
					if(a[0][s]==0)
						break;
				
				s++;
				j1++;
				i1++;
				
				if(i==0 && j==0)
					{
						for(j1;j1>=0;j1--)
							if(a[j1][i1+1]!=0)
								break;
						for(i1;i1>=0;i1--)
							if(a[j1+1][i1]!=0)
								break;
					}
					
				if(i==0 && j!=0)
					{
						for(j1;j1>=0;j1--)
							if(a[j1][i1+1]!=0)
								break;
					
						for(i1;i1>=0;i1--)
							{
								if(a[j-1][i1]!=0)
									break;
								if(a[j1+1][i1]!=0)
									break;
							}
					}
					
				if(j==0 && i!=0)
					{
						
						for(j1;j1>=0;j1--)
							{
								if(a[j1][i-1]!=0)
									break;
								if(a[j1][i1+1]!=0)
									break;
							}
					
						for(i1;i1>=0;i1--)
							{
								if(a[j-1][i1]!=0)
									break;
								if(a[j1+1][i1]!=0)
									break;
							}
					}
					
					i1++;
					j1++;
					
				if(s==0 && i1==0 && j1==0)
					kp++;
			}
	
	printf("Кол-во  прям-ков : %i\n",kp);
	
	system("pause");
	return 0;
}
