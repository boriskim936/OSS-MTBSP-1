#include "user_movie_select.h"
#pragma warning(disable:4996)

user *movie_select_movie(user *user_temp, movie *movie_head)
{
	int i, go = 1;
	int z = 1;
	movie *movie_temp = NULL;
	movie_temp = movie_head;
	printf("\n");
	while (movie_temp != NULL)
	{
		printf("[%d] => [%s] [%s]\n\n", z, movie_temp->movie_number, movie_temp->movie_name);
		movie_temp = movie_temp->next;
		z++;
	}
	movie_temp = movie_head;
	printf("상영할 영화를 선택하여 주십시요(숫자 입력): ");
	scanf("%d", &go);
	system("cls");
	for (i = 1; i <= go; i++)
	{
		if (i == 1)
		{
			movie_temp;
		}
		else
		{
			movie_temp = movie_temp->next;
		}
		strcpy(user_temp->user_movie_number, movie_temp->movie_number);
		strcpy(user_temp->user_movie_name, movie_temp->movie_name);
	}

	return user_temp;
}

user *movie_select_time(user *user_temp, movie *movie_head)
{
	int go;
	int j = 0;
	int i = 0;
	int z = 1;
	movie *movie_temp = NULL;
	movie_temp = movie_head;
	while(1)
	{
		if (strcmp(user_temp->user_movie_number, movie_temp->movie_number) == 0 && strcmp(user_temp->user_movie_name, movie_temp->movie_name) == 0)
		{
			break;
		}
		else
		movie_temp = movie_temp->next;
	}
	printf("\n");
	while (movie_temp->count[j] != 0)
	{
		printf("[%d] => [%s]\n\n", z,movie_temp->movie2[i].time);
		movie_temp->movie2->time[i];
		i++;
		z++;
		j++;
	}
	printf("상영할 영화의 시간을 선택하여 주십시요(숫자 입력): ");
	scanf("%d", &go);

	strcpy(user_temp->user_movie_time, movie_temp->movie2[go-1].time);

	return user_temp;
}
