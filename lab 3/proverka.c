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
	
	while (system("cls"),k++,printf("������� ����� ������������� �����: "),fflush(stdin),scanf("%u",&N)!=1)		
	{
		switch(k)
		{		
			case 5:
				printf("�� ����������, �� ������ ���������� �����\n");
				break;
			default:
				printf("������\n");
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
		printf("���-�� ������ ������\n");
	}
	else
	{
		printf("���-�� ������ ��������\n");
	}
	
	system("pause");
	return 0;
}




