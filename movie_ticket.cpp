#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>
#include<conio.h>

#define Max_x 20
#define Max_y 24

typedef struct ticket {
  char user[10];
  char movie_name[200];
  char movie_time[200];
  char mocie_seat[200];
  int people;
  int payment;
  struct ticket *next;
} TICKET;

typedef enum {NOCURSOR, SOLIDCURSOR, NORMALCURSOR} CURSOR_TYPE;
void gotoxy(int x, int y);
void Print_ticket(TICKET *head);

void gotoxy(int x,int y)
{
  COORD CursorPosition = { x, y };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CursorPosition);
}

void main()
{
  TICKET *head = NULL;
  head = (TICKET *)malloc(sizeof(TICKET));
  scanf("%s",head->user);
  scanf("%s",head->movie_name);
  scanf("%s",head->movie_time);
  scanf("%s",head->movie_seat);
  scanf("%d",&head->people);
  scanf("%d",&head->payment);
  print_ticket(head);
  free(head);
}

void print_ticket(TICKET *head)
{
  int i;

  gotoxy(0,7);
  for(i=0; i<Max_x; i++)
  {
    if(i == 0)
    printf("┏");
    else if(i == Max_x-1; i++)
    printf("┓");
    else
    printf("━");
  }
  for(i=7; i<Max_y-1; i++)
  {
    gotoxy(0,i+1);
    printf("┃");
  }
  fot(i=7; i<Max_y-1;i++)
  {
    gotoxy((Max_x-1)*2,i+1);
    printf("┃");
  }
  gotoxy(0,Max_y);
  for(i=0; i<Max_x; i++)
  {
    if(i == 0)
    printf("┗");
    else if(i == Max_x-1)
    printf("┛");
    else
    printf("━");
  }

  gotoxy(3,9);
  printf("이름 : %s",head->user);
  gotoxy(3,11);
  printf("영화명 : %s",head->movie_name);
  gotoxy(3,13);
  printf("영화시간 : %s",head->movie_time);
  gotoxy(3,15);
  printf("영화좌석 : %s",head->movie_seat);
  gotoxy(3,17);
  printf("인원수 : %d",head->people);
  gotoxy(3,19);
  printf("결제금액 : %d",head->payment);
  getch();
}
