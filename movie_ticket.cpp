#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct ticket {
  char user[10];
  char movie_name[200];
  char movie_time[200];
  char mocie_seat[200];
  int people;
  int payment;
  struct ticket *next;
} TICKET;

void Print_ticket(TICKET *head);

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
  printf("이름 : %s",head->user);
  printf("영화명 : %s",head->movie_name);
  printf("영화시간 : %s",head->movie_time);
  printf("영화좌석 : %s",head->movie_seat);
  printf("인원수 : %d",head->people);
  printf("결제금액 : %d",head->payment);
}
