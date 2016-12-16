#include "admin_movie_payment.h"


movie *movie_select_people(movie *movie_head)
{
	int i, go = 1;
	int z = 1;
	movie *movie_temp = NULL;
	movie_temp = movie_head;
	printf("\n");
	while (movie_temp != NULL)
	{
		printf("[%d] => %s %s\n", z, movie_temp->movie_number, movie_temp->movie_name);
		movie_temp = movie_temp->next;
		z++;
	}
	movie_temp = movie_head;
	printf("\n가격을 등록할 영화를 선택하여 주십시요(숫자 입력):");
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
	}
	printf("\n");
	printf("[가격 설정] (ex: 7000, 4000, 200)");
	printf("\n[성  인] : ");
	scanf("%d", &movie_temp->adult);
	printf("\n[청소년] : ");
	scanf("%d", &movie_temp->youth);
	printf("\n[어린이] : ");
	scanf("%d", &movie_temp->child);
	printf("\n[우  대] : ");
	scanf("%d", &movie_temp->preferential);
	system("cls");

	return movie_head;
}
