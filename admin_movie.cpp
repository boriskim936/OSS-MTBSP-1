#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<malloc.h>
#include"movie.h"

void Insert()
{
	FILE *fp;
	movie * tmp = NULL;

	if ((fp = fopen("MovieData.txt", "r")) == NULL)
	{
		printf("Can't open file data.txt");
		exit(-1);
	}

	printf("");
}
