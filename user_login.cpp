#include "user_login.h"

user *login_member(user *user_temp)
{
	system("cls");
	char cid[20];
	char cpassword[20];
	int go;
	FILE *fp_in;
	fp_in = fopen("membership_data.txt", "r");
	UI *head, *temp;
	head = (UI*)malloc(sizeof(UI));
	head->next = NULL;
	temp = head;
	printf("\n");
	printf("[아이디]: ");
	scanf("%s", &cid);
	printf("\n");
	printf("[비밀번호]: ");
	scanf("%s", &cpassword);
	system("cls");
	while (!feof(fp_in))
	{
		fscanf(fp_in, "%s %s %s %s %s\n", temp->id, temp->password, temp->name, temp->phone, temp->userNumber);
		if (strcmp(temp->id, cid) == 0 && strcmp(temp->password, cpassword) == 0)
		{
			printf("\n<로그인 되셨습니다.>\n\n아무키나 눌러주세요");
			strcpy(user_temp->user_name, temp->name);
			strcpy(user_temp->user_phone, temp->phone);
			go = getch();
			return user_temp;
		}
		else
			temp->next = (UI*)malloc(sizeof(UI));
		temp = temp->next;
	}
	printf("<아이디와 패스워드가 없거나 잘못 입력하셨습니다.>\n");
	printf("[1] => 재입력");
	go = getch();
	system("cls");
	if(go== 49)
		return login_member(user_temp);


	return user_temp;
}
user *login_nonmember(user *user_temp)
{
	char id[20], phone[30];
	FILE *fp_out1, *fp_out2;
	fp_out1 = fopen("user_nonmember_data.txt", "a");
	printf("[이름]: ");
	scanf("%s", user_temp->user_name);
	printf("\n");
	printf("[핸드폰 번호]: ");
	scanf("%s", user_temp->user_phone);
	fprintf(fp_out1, "%s %s\n", user_temp->user_name, user_temp->user_phone);
	fclose(fp_out1);

	return user_temp;
}
