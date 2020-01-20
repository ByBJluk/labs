#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	system("chcp 1251> nul");
	
	int x1, x2, y1, y2, s1,s2,k;
	
	printf("введите координаты короля:\nx1 y1:");
	k=scanf("%i%i", &x1, &y1);
	
	printf("введите координаты ладьи:\nx2 y2:");
	k=k+scanf("%i%i", &x2, &y2);
	
	
	if(
	(x1<9 && x1>0)&&(x2<9 && x2>0)&&(y1<9 && y1>0)&&(y2<9 && y2>0)&&(k==4)
	)
	{}
	else
	{
		printf("\nОШИБКА неверно введены значения координат");
		return 1;
	}
	
	
	if(
	((x2==x1)&&((y2==y1+1)||(y2==y1-1)))||((y2==y1)&&((x2==x1+1)||(x2==x1-1)))
	)
	{
		printf("Фигуры бьют друг друга");
		return 0;
	}
	
	
	if(
	((x2==x1+1)&&((y2==y1+1)||(y2==y1-1)))||((y2==y1+1)&&((x2==x1+1)||(x2==x1-1)))
	)
	{
		printf("Король бьёт ладью");
		return 0;
	}
	
	
	if(
	(x1==x2)||(y1==y2)
	)
	{
		printf("Ладья бьет короля");
		return 0;
	}
	else
	{
		printf("Фигуры не атакуют друг друга");
		return 0;
	}
	
	
	system("pause");
	return 0;
}
