#include <stdio.h>
#pragma warning(disable:4996)
#include <windows.h>
#include "user_login.h"
#include "user_membership.h"
#include "user_movie.h"
#include "user_people.h"
#include "user_seat.h"
#include "user_payment.h"
#include "user_ticket.h"
#include "admin_movie.h"
#include "admin_payment.h"



void main()
{
	int select;
	printf("회원가입 1번 회원로그인2번 비로그인3번\n");
	scanf("%d", &select);
	if (select == 1)
	{
		membership();
	}
	else if (select == 2)
	{
		login_member();
	}
	else if (select == 3)
	{
		login_nonmember();
	}
	return;

}