#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<malloc.h>
#include"movie.h"

void Insert()
{
	FILE *fp;
	movie * tmp = NULL, * t=NULL;

	if ((fp = fopen("MovieData.txt", "r")) == NULL)
	{
		printf("Can't open file data.txt");
		exit(-1);
	}
	t = Head;
	tmp = t;
	while (!feof(fp))
	{
		tmp = (movie *)malloc(sizeof(movie));
		fscanf(fp, "%s %s %d %d %d %d\n", tmp->name, tmp->start, &tmp->floor, &tmp->sit[0], &tmp->sit[1]);
		tmp->next = NULL;
		tmp = tmp->next;
	}

	tmp = (movie *)malloc(sizeof(movie));
	tmp->next = NULL;

	printf("영화 제목 입력 : ");
	gets(tmp->name);
	printf("영화 시작 시간 입력 (ex ) 9 : 00 ~ 12 : 00) : " );
	gets(tmp->start);
	printf("영화 상영관 입력 : ");
	scanf("%d", &tmp->floor);
	printf("영화 좌석 수 입력(ex ) 10(x길이) 5(y길이)) : ");
	scanf("%d %d", &tmp->sit[0], &tmp->sit[1]);

	if(Head == NULL)
	{
		Head = tmp;
		return;
	}
	t = Head;
	while(1)
	{
		if(t == NULL)
			break;
		t = t->next;
	}

	t = tmp;
	return;
}

void PrintMovie()
{
	movie * tmp = NULL;

	tmp = Head;

	while(1)
	{
		if(tmp == NULL)
			break;
		printf("영화 제목 : %s\n영화 시간 : %s\n상영관 : %d관\n좌석 x : %d, y : %d\n", tmp->name, tmp->start, tmp->floor, tmp->sit[0], tmp->sit[1]);
		tmp = tmp->next;
	}
	return;
}
