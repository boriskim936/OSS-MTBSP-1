#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<malloc.h>
#include"admin_movie.h"

movie* Insert()
{
	movie * Head = NULL;
	FILE *fp;
	movie * tmp = NULL, * t=NULL;
	int num = 9;
	char ask;

	if ((fp = fopen("MovieData.txt", "r")) == NULL)
	{
		printf("Can't open file data.txt");
		exit(-1);
	}
	t = Head;
	while (!feof(fp))
	{
		tmp = (movie *)malloc(sizeof(movie));
		fscanf(fp, "%s\t%s\t%d\t%d\t%d\t%d\n", tmp->name, tmp->start, &tmp->floor, &tmp->sit[0], &tmp->sit[1]);
		/*fgets(tmp->name, 100, fp);
		fgets(tmp->start, 30, fp);
		fscanf(fp, "%d %d %d\n", &tmp->floor, &tmp->sit[0], &tmp->sit[1]);*/
		tmp->next = t;
		t = tmp;
	}
	Head = t;

	tmp = (movie *)malloc(sizeof(movie));
	tmp->next = NULL;

	printf("영화 제목 입력 : ");
	gets(tmp->name);
	printf("영화 시작 시간 입력" );
	while(1)
	{
		if(num == 9)
		{
			SetColor(7,0);
			printf("09 : 00 ~ 11 : 00");
			SetColor(0,7);
		}
		else
			printf("09 : 00 ~ 11 : 00");
		if(num == 11)
		{
			SetColor(7,0);
			printf("11 : 00 ~ 13 : 00");
			SetColor(0,7);
		}
		else
			printf("11 : 00 ~ 13 : 00");
		if(num == 13)
		{
			SetColor(7,0);
			printf("13 : 00 ~ 15 : 00");
			SetColor(0,7);
		}
		else
			printf("13 : 00 ~ 15 : 00");
		if(num == 15)
		{
			SetColor(7,0);
			printf("15 : 00 ~ 17 : 00");
			SetColor(0,7);
		}
		else
			printf("15 : 00 ~ 17 : 00");
		if(num == 17)
		{
			SetColor(7,0);
			printf("17 : 00 ~ 19 : 00");
			SetColor(0,7);
		}
		else
			printf("17 : 00 ~ 19 : 00");
		if(num == 19)
		{
			SetColor(7,0);
			printf("19 : 00 ~ 21 : 00");
			SetColor(0,7);
		}
		else
			printf("19 : 00 ~ 21 : 00");
		ask = getch();
		if(ask == ' ')
			break;
		switch(ask)
		{
		case 72:
			if(num > 9)
				num -= 2;
			break;
		case 80:
			if(num < 19)
				num += 2;
			break;
		}
	}

	printf("영화 상영관 입력 : ");
	scanf("%d", &tmp->floor);
	printf("영화 좌석 수 입력(ex ) 10(x길이) 5(y길이)) : ");
	scanf("%d %d", &tmp->sit[0], &tmp->sit[1]);

	if(Head == NULL)
	{
		Head = tmp;
		if ((fp = fopen("MovieData.txt", "w")) == NULL)
		{
			printf("Can't open file data.txt");
			exit(-1);
		}
		tmp = Head;
		while (1)
		{
			if(tmp == NULL)
				break;
			fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%d\n", tmp->name, tmp->start, tmp->floor, tmp->sit[0], tmp->sit[1]);
			/*fputs(tmp->name, fp);
			fputs(tmp->start, fp);
			fprintf(fp, "%d %d %d\n", tmp->floor, tmp->sit[0], tmp->sit[1]);*/
			tmp = tmp->next;
		}
		return Head;
	}
	t = Head;
	while(1)
	{
		if(t->next == NULL)
			break;
		t = t->next;
 	}

	t->next = tmp;

	if ((fp = fopen("MovieData.txt", "w")) == NULL)
	{
		printf("Can't open file data.txt");
		exit(-1);
	}
	tmp = Head;
	while (1)
	{
		if(tmp == NULL)
			break;
		fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%d\n", tmp->name, tmp->start, tmp->floor, tmp->sit[0], tmp->sit[1]);
		/*fputs(tmp->name, fp);
		fputs(tmp->start, fp);
		fprintf(fp, "%d %d %d\n", tmp->floor, tmp->sit[0], tmp->sit[1]);*/
		tmp = tmp->next;
	}
	return Head;
}

void PrintMovie(movie * head)
{
	movie * tmp = NULL;

	tmp = head;

	while(1)
	{
		if(tmp == NULL)
			break;
		printf("영화 제목 : %s\n영화 시간 : %s\n상영관 : %d관\n좌석 x : %d, y : %d\n", tmp->name, tmp->start, tmp->floor, tmp->sit[0], tmp->sit[1]);
		tmp = tmp->next;
	}
	return;
}

void UserPrint()
{
	movie * Head = NULL;
	FILE *fp;
	movie * tmp = NULL, * t=NULL;

	if ((fp = fopen("MovieData.txt", "r")) == NULL)
	{
		printf("Can't open file data.txt");
		exit(-1);
	}
	t = Head;
	while (!feof(fp))
	{
		tmp = (movie *)malloc(sizeof(movie));
		fscanf(fp, "%s\t%s\t%d\t%d\t%d\t%d\n", tmp->name, tmp->start, &tmp->floor, &tmp->sit[0], &tmp->sit[1]);
		/*fgets(tmp->name, 100, fp);
		fgets(tmp->start, 30, fp);
		fscanf(fp, "%d %d %d\n", &tmp->floor, &tmp->sit[0], &tmp->sit[1]);*/
		tmp->next = t;
		t = tmp;
	}
	Head = t;
	tmp = Head;

	while(1)
	{
		if(tmp == NULL)
			break;
		printf("영화 제목 : %s\n영화 시간 : %s\n상영관 : %d관\n", tmp->name, tmp->start, tmp->floor);
		tmp = tmp->next;
	}
	return;
}
