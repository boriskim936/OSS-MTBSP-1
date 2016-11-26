#pragma once

typedef struct node
{
	char name[100];
	char start[20];
	int time;
	int floor;
	int sit[2];

	node * next;
} movie;

movie * Head = NULL;

void Insert();
void PrintMovie();
