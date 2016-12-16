#include "user_movie_ticket.h"
#pragma warning(disable:4996)

void gotoxy(int x, int y)
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void *movie_ticket(user *user_temp)
{
	int i, go;
	int j = 0;
	int z = 0;
	gotoxy(0, 7);
	for (i = 0; i < Max_x; i++)
	{
		if (i == 0)
			printf("┏");
		else if (i == Max_x - 1)
			printf("┓");
		else
			printf("━");
	}
	for (i = 7; i < Max_y - 1; i++)
	{
		gotoxy(0, i + 1);
		printf("┃");
	}
	for(i = 7; i < Max_y - 1; i++)
	{
		gotoxy((Max_x - 1) * 2, i + 1);
		printf("┃");
	}
	gotoxy(0, Max_y);
	for (i = 0; i < Max_x; i++)
	{
		if (i == 0)
			printf("┗");
		else if (i == Max_x - 1)
			printf("┛");
		else
			printf("━");
	}

	gotoxy(3, 9);
	printf("이름 : %s", user_temp->user_name);
	gotoxy(3, 11);
	printf("영화 : %s", user_temp->user_movie_name);
	gotoxy(3, 13);
	printf("시간 : %s", user_temp->user_movie_time);
	gotoxy(3, 15);
	printf("인원 : %d", user_temp->user_people);
	gotoxy(3, 17);
	printf("금액 : %d", user_temp->user_payment);
	gotoxy(3, 19);
	printf("좌석 :");
	for (i = 0; i < 30; i++)
	{
		if (user_temp->user2[i].height_number != 0)
		{
			printf(" %d열%d칸", user_temp->user2[i].height_number, user_temp->user2[i].width_number);
			if ((i+1 % 4) == 0)
			{
				printf("\n");
				gotoxy(3, 19+(++z));
			}
		}
	}
	go=getch();
	system("cls");
	return 0;
}
