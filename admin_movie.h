#pragma once

typedef struct node
{
	char name[100];
	char time[50];
	int floor;

	node * next;
} movie;

void Insert();
void PrintMovie();
