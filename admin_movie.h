#pragma once

#include<stdio.h>

typedef struct node{
	char name[100];
	char start[30];
	int floor;
	int sit[2];
	struct node *next;
}movie;

movie* Insert();
void PrintMovie(movie* head);
void UserPrint();
void setcursortype(CURSOR_TYPE c); // 커서 제거 함수 - 유형철
void gotoxy(int x, int y);
void print();
void SetColor(int bcolor, int tcolor)
