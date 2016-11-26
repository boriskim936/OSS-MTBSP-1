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
		fscanf(fp, "%s %s %d %d %d %d\n", tmp->name, tmp->start, &tmp->time, &tmp->floor, &tmp->sit[0], &tmp->sit[1]);
		tmp->next = NULL;
		tmp = tmp->next;
	}

}
