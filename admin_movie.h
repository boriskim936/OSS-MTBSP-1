#pragma once

typedef struct node{
	char name[100];
	char start[30];
	int floor;
	int sit[2];
	struct node *next;
}movie;

movie * Head = NULL;

void Insert();
void PrintMovie();
