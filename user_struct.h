#pragma once

typedef struct user2 {
	int height_number;
	int width_number;
}user2;

typedef struct user {
	char user_name[20];
	char user_phone[20];
	char user_movie_number[20];
	char user_movie_name[20];
	char user_movie_time[40];
	int user_people;
	int user_payment;
	struct user2 user2[30];
	struct user *next;
}user;
