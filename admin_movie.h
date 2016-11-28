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
