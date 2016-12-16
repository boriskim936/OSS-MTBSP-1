#pragma once
typedef struct movie2 {
	char time[40];
	int seat[200][200];
	int height;
	int width;
}movie2;

typedef struct movie {
	char user_name[20];
	char user_id[20];
	char movie_number[20];
	char movie_name[20];
	int count[10];
	struct movie2 movie2[10];
	int adult;
	int youth;
	int child;
	int preferential;
	struct movie *next;
}movie;

typedef struct paymnet {
	int adult;
	int youth;
	int child;
	int preferential;
}payment;
