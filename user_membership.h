#pragma once

#include <stdio.h>
#include <malloc.h>
#include <Windows.h>

typedef struct userInformation {
	char id[20];
	char password[16];
	char name[20];
	char phone[20];
	char userNumber[20];
	struct userInformation *next;
}UI;

void membership();
