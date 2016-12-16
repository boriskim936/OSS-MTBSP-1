#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "admin_movie02.h"
#include "user_membership.h"
#include "user_login.h"
#include "admin_movie_payment.h"
#include "user_movie_select.h"
#include "user_movie_people.h"
#include "user_movie_seat.h"
#include "user_movie_payment.h"
#include "user_movie_ticket.h"
#pragma warning(disable:4996)


void main()
{
	movie * movie_head = NULL, *movie_temp = NULL, *insert1_current = NULL, *insert2_current = NULL;

	int go, i;

	int z = 1;
	while (1)
	{
		system("cls");
		printf("\n");
		printf("[1] 회원로그인\n\n");
		printf("[2] 비회원로그인\n\n");
		printf("[3] 회원가입\n\n");
		printf("[4] 관리자모드\n\n");
		go = getch();

		system("cls");
		if (go == 49 || go == 50)
		{
			system("cls");
			user *user_head = NULL, *user_temp = NULL;
			user_temp = (user*)malloc(sizeof(user));
			user_head = user_temp;
			if (go == 49)
			{
				user_temp= login_member(user_temp);
				system("cls");
			}
			else if (go == 50)
			{
				user_temp =login_nonmember(user_temp);
				system("cls");
			}
			system("cls");
			user_temp=movie_select_movie(user_temp, movie_head);
			system("cls");
			user_temp=movie_select_time(user_temp, movie_head);
			system("cls");
			user_temp = movie_select_people(user_temp, movie_head);
			system("cls");
			user_temp = movie_select_seat(user_temp, movie_head);
			system("cls");
			movie_select_payment(user_temp);
			system("cls");
			movie_ticket(user_temp);
			user_temp = user_temp->next;
		}
		else if (go == 51)
		{
			membership();
		}
		else if (go == 52)
		{
			while (1)
			{
				printf("\n");
				printf("[1] 영화등록\n\n");
				printf("[2] 좌석및 시간설정\n\n");
				printf("[3] 가격 등록하기\n\n");
				printf("<종료 또는 초기화면을 원하시면 0번>\n\n");
				go = getch();
				system("cls");
				if (go == 48)
				{
					break;
				}
				if (go == 49)
				{
					if (movie_head == NULL)
					{
						movie_temp = (movie*)malloc(sizeof(movie));
						movie_temp = admin_movie_insert1(movie_temp);
						movie_head = insert1_current = movie_temp;
						movie_head->next = NULL;

					}
					else
					{
						movie_temp = (movie*)malloc(sizeof(movie));
						movie_temp = admin_movie_insert1(movie_temp);

						insert1_current->next = movie_temp;
						movie_temp->next = NULL;
						insert1_current = movie_temp;

					}

				}
				else if (go == 50)
				{
					z = 1;
					insert2_current = movie_head;
					printf("\n");
					while(insert2_current != NULL)
					{
						printf("[%d] => [%s] [%s]\n\n", z, insert2_current->movie_number, insert2_current->movie_name);
						insert2_current = insert2_current->next;
						z++;
					}
					insert2_current = movie_head;
					printf("\n");
					printf("영화를 선택 하여주십시오(숫자 입력): ");
					scanf("%d", &go);
					system("cls");
					for (i = 1; i <= go; i++)
					{
						if (i==1)
						{
							insert2_current;
						}
						else
						{
							insert2_current = insert2_current->next;
						}

					}
					insert2_current = admin_movie_insert2(insert2_current);
				}

				else if (go == 51)
				{
					movie_select_people(movie_head);
				}
			}
		}
	}

	return;
}
