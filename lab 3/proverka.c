#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	system ("chcp 1251> nul");
	
	unsigned long N;
	int k, i, s, f;
	
	s=0;
	k=0;
	i=0;
	
	while (system("cls"),k++,printf("Введите целое положительное число: "),fflush(stdin),scanf("%u",&N)!=1)		
	{
		switch(k)
		{		
			case 5:
				printf("Вы безнадежны, но можете попытаться снова\n");
				break;
			default:
				printf("Ошибка\n");
				break;
		}
		system("pause");
	}
	
	f=sizeof(N)*8;
	
	while (i++,i<=f)
	{
		if(N&1==1)
		{
			s=s+1;
		}
		N=N>>1;
	}
	
	
	if(s%2==0)
	{
		printf("кол-во единиц четное\n");
	}
	else
	{
		printf("кол-во единиц нечетное\n");
	}
	
	system("pause");
	return 0;
}




