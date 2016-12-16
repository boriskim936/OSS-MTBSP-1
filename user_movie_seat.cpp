
#include "user_movie_seat.h"
#pragma warning(disable:4996)

user *movie_select_seat(user *user_temp, movie *movie_head)
{
	int i, j, go;
	int x, y;
	int count = 0, count2 = 0;
	int empty = 0;
	int people;
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
	for (i = 0; i < 10; i++)
	{
		if (strcmp(user_temp->user_movie_time, movie_temp->movie2[i].time) == 0)
		{
			break;
		}
	}
	count = i;
	people = 0;
	while (people != user_temp->user_people)
	{
		system ("cls");
		printf("\n");
		printf("    ");
		for (i = 0; i < movie_temp->movie2[count].width; i++)
		{
			printf("---");
		}
		printf("\n");
		printf("\n");
		printf("    ");
		for (i = 0; i < movie_temp->movie2[count].width; i++)
		{
			printf("%2d ", i + 1);
		}
		printf("\n");
		for (i = 0; i < movie_temp->movie2[count].height; i++)
		{
			printf("%3d  ", i + 1);
			for (j = 0; j < movie_temp->movie2[count].width; j++)
			{
				if (movie_temp->movie2[count].seat[i][j] == 1)
				{
					printf("■ ");
				}
				else
					printf("□ ");
				++empty;
			}
			printf("\n");
		}
		x = 0, y = 0;
		printf("\n좌측 숫자를 보고 열을 선택하여 주십시오(숫자 입력):");
		scanf("%d", &x);
		printf("상단 숫자를 보고 칸을 선택하여 주십시오(숫자 입력):");
		scanf("%d", &y);
		if (movie_temp->movie2[count].seat[x - 1][y - 1] == 0)
		{
			movie_temp->movie2[count].seat[x - 1][y - 1] = 1;
			system("cls");
			printf("\n");
			printf("    ");
			for (i = 0; i < movie_temp->movie2[count].width; i++)
			{
				printf("---");
			}
			printf("\n");
			printf("\n");
			printf("    ");
			for (i = 0; i < movie_temp->movie2[count].width; i++)
			{
				printf("%2d ", i + 1);
			}
			printf("\n");
			for (i = 0; i < movie_temp->movie2[count].height; i++)
			{
				printf("%3d  ", i + 1);
				for (j = 0; j < movie_temp->movie2[count].width; j++)
				{
					if (movie_temp->movie2[count].seat[i][j] == 1)
					{
						printf("■ ");
					}
					else
						printf("□ ");
					++empty;
				}
				printf("\n");
			}
				printf("\n");
				printf("\n[%d열 %d칸] 예약이 완료되었습니다.\n\n계속 진행하실려면 아무키나 눌러주세요\n", x, y);
				go = getch();
				people++;
				user_temp->user2[count2].height_number = x;
				user_temp->user2[count2].width_number = y;
				count2++;
				for (i = count2; i < 30; i++)
				{
					user_temp->user2[i].height_number = 0;
					user_temp->user2[i].width_number = 0;
				}

		}
		else {
			printf("\n[%d열 %d칸]은 이미 예약된 자리입니다.\n\n계속 진행하실려면 아무키나 눌러주세요\n", x, y);
			go = getch();
		}
	}
	return user_temp;
}
