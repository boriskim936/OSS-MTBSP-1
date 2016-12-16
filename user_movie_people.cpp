#include "user_movie_people.h"
#pragma warning(disable:4996)

user *movie_select_people(user *user_temp, movie *movie_head)
{
	int x1 = 0 , x2 = 0, x3 = 0, x4 = 0;
	movie *movie_temp = NULL;
	movie_temp = movie_head;
	while (1)
	{
		if (strcmp(user_temp->user_movie_number, movie_temp->movie_number) == 0 && strcmp(user_temp->user_movie_name, movie_temp->movie_name) == 0)
		{
			break;
		}
		else
			movie_temp = movie_temp->next;
	}
	printf("\n");
	printf("[구매 인원 입력] (ex: 4, 7, 10, 1)\n\n");
	printf("[성  인] [%d] 인원: ", movie_temp->adult);
	scanf("%d", &x1);
	printf("[청소년] [%d] 인원: ", movie_temp->youth);
	scanf("%d", &x2);
	printf("[어린이] [%d] 인원: ", movie_temp->child);
	scanf("%d", &x3);
	printf("[우  대] [%d] 인원: ", movie_temp->preferential);
	scanf("%d", &x4);
	user_temp->user_people = (x1 + x2 + x3 + x4);
	user_temp->user_payment = (movie_temp->adult*x1) + (movie_temp->youth*x2) + (movie_temp->child*x3) + (movie_temp->preferential*x4);



	return user_temp;
}
