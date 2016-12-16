#include "admin_movie02.h"

#pragma warning(disable:4996)


movie *admin_movie_insert1(movie *insert1_current)
{

	fflush(stdin);
	printf("\n");
	printf("[영화관 입력] (ex: 1상영관, 1관)\n\n");
	fflush(stdin);
	scanf("%s", insert1_current->movie_number);
	printf("\n[영화명 입력] (ex: 해리포터, 죽은시인의 사회)\n\n");
	fflush(stdin);
	scanf("%s", insert1_current->movie_name);
	system("cls");


	return insert1_current;
}

movie *admin_movie_insert2(movie *insert2_current)
{
	int i, j, x, y;
	int k = 0, t = 0;
	int sum = 0;
	if (insert2_current->count[0] != 1)
	{
		insert2_current->count[0] = 1;
		for (i = 1; i < 9; i++)
		{
			insert2_current->count[i] = 0;
		}
		printf("\n");
		printf("[영화 시간설정] (ex: 11~12, 11시~13시,9-10)\n\n");
		fflush(stdin);
		scanf("%s", insert2_current->movie2[k].time);
		printf("\n[영화 자리설정] (ex: 8 10)-> 열/칸 순으로 입력\n\n");
		fflush(stdin);
		scanf("%d %d", &insert2_current->movie2[k].height, &insert2_current->movie2[k].width);
		system("cls");
		for (i = 0; i < insert2_current->movie2[k].height; i++)
		{
			for(j=0;j<insert2_current->movie2[k].width;j++)
			insert2_current->movie2[k].seat[i][j] = 0;
		}
		return insert2_current;
	}
	for (k = 0; k < 10; k++)
	{
		if (insert2_current->count[k] != 1)
		{
			insert2_current->count[k] = 1;
			for(t=k+1 ; t<10;t++)
				insert2_current->count[t] = 0;
			break;
		}
	}
	printf("\n");
	printf("[영화 시간설정] (ex: 11~12, 11시~13시,9-10)\n\n");
	fflush(stdin);
	scanf("%s", insert2_current->movie2[k].time);
	printf("\n[영화 자리설정] (ex: 8 10)-> 열/칸 순으로 입력\n\n");
	fflush(stdin);
	scanf("%d %d", &insert2_current->movie2[k].height, &insert2_current->movie2[k].width);
	system("cls");
	for (i = 0; i < insert2_current->movie2[k].height; i++)
	{
		for (j = 0; j<insert2_current->movie2[k].width; j++)
			insert2_current->movie2[k].seat[i][j] = 0;
	}
	return insert2_current;
}
