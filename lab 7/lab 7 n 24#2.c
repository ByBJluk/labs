#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum status_oplaty {not_paid, paid} status_oplaty;

typedef enum status_vipolnenia {not_complete, complete }status_vipolnenia;

typedef struct date
{
	int d, m, y;
}date;

typedef struct zakaz 
{
	char name_org[11];
	status_oplaty st_p;
	status_vipolnenia st_c;
	int duration;
	double price;
	date date;
}zakaz;

void input_date(date *p)
{
	while (fflush(stdin), printf("\nday:\t"), scanf("%d", &p->d) != 1 || p->d > 31 || p->d < 0)
		printf("error! incorrect date\n");
	while (printf("month:\t"), scanf("%d", &p->m) != 1 || p->m > 12 || p->m < 0)
		printf("error! incorrect date\n");
	while (printf("year:\t"), scanf("%d", &p->y) != 1 || p->y < 2000 || p->y>2100)
		printf("error! incorrect date\n");
}

void input_zakaz(zakaz *p)
{
	fflush(stdin);
	printf("\nname of organization:\t");
	scanf("%s", &p->name_org);
	while (fflush(stdin), printf("\n\n0 - not paid\n1 - paid\nenter status:"), scanf("%d", &p->st_p) != 1 ||( p->st_p != not_paid && p->st_p!= paid))
		printf("\nerror! incorrect input");
	while (fflush(stdin), printf("\n\n0 - not complete\n1 - complete\nenter status:"), scanf("%d", &p->st_c) != 1 || (p->st_c != not_complete && p->st_c != complete))
		printf("\nerror! incorrect input");
	fflush(stdin);
	printf("\nenter date:\n");
	input_date(&p->date);
	while (fflush(stdin), printf("\nenter price(rub):\t"), scanf("%lg", &p->price) != 1 || p->price < 0)
		printf("error! incorrect input!");
	while (fflush(stdin), printf("\nenter duration(days):\t"), scanf("%d", &p->duration) != 1 || p->duration < 0)
		printf("error! incorrect input!");
}

void output_status(const status_vipolnenia p, const status_vipolnenia o)
{
	if (p)
		printf("\nstatus: paid");
	else
		printf("\nstatus: not paid");
	if (o)
		printf(", complete\n");
	else
		printf(", not complete\n");
}

void output_date(const date *p)
{
	if (p->d < 10)
		if (p->m < 10)
			printf("date: 0%i.0%i.%i\n", p->d, p->m, p->y);
		else
			printf("date: 0%i.%i.%i\n", p->d, p->m, p->y);
	else
		if (p->m < 10)
			printf("date: %i.0%i.%i\n", p->d, p->m, p->y);
		else
			printf("date: %i.%i.%i\n", p->d, p->m, p->y);
}

void output_zakaz(const zakaz *p)
{
	printf("\nname of org: %s", p->name_org);
	output_status(p->st_p, p->st_c);
	printf("duration(in days): %d", p->duration);
	printf("\nprice of order(rub): %lg\n", p->price);
	output_date(&p->date);
}

double calc_price(const zakaz *p)
{
	double summ_price = 0;
	if (p->st_p && !p->st_c)
		summ_price = p->price;
	return summ_price;
}

int calc_duration(const zakaz* p)
{
	int summ_dur=0;
	if (!p->st_p)
		summ_dur = p->duration;
	return summ_dur;
}

int search(zakaz *p, char *str)
{
	if (!stricmp(str, p->name_org))
		return 1;
	return 0;
}

int sort_date(zakaz* p, zakaz* o)
{
	if (p->date.y < o->date.y)
		return 0;
	else
		if (p->date.m < o->date.m)
			return 0;
		else
			if (p->date.d < o->date.d)
				return 0;
			else
				return 1;

}

int main()
{
	int summ_dur = 0;
	double summ_price = 0;
	zakaz A, B;
	char str[11];

	printf("\nenter info:");
	input_zakaz(&A);

	printf("\n\nenter info:");
	input_zakaz(&B);

	printf("\nlist :");
	output_zakaz(&A);
	printf("\n");
	output_zakaz(&B);

	printf("\nsearch(name):");
	scanf("%s", str);
	printf("\n");
	if (search(&A, str))
		output_zakaz(&A);
	if (search(&B, str))
		output_zakaz(&B);
	system("pause");

	printf("\nsort date:");
	if (sort_date(&A, &B))
	{
		output_zakaz(&A);
		output_zakaz(&B);
	}
	else
	{
		output_zakaz(&B);
		output_zakaz(&A);
	}
	printf("\n");
	system("pause");

	summ_price += calc_price(&A);
	summ_dur += calc_duration(&A);
	summ_price += calc_price(&B);
	summ_dur += calc_duration(&B);
	printf("\nprice(paid ,not complete):%lg", summ_price);
	printf("\n general duration(not paid):%d\n", summ_dur);

	system("pause");
	return 0;


}





