#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "struct_membership.h"
#include "loop_free.h"
#pragma warning(disable:4996)

//typedef struct userInformation {
//	char id[20];
//	char password[16];
//	char name[20];
//	char phone[20];
//	char userNumber[20];
//	struct userInformation *next;
//}UI;


void login_member();
void login_nonmember();
//UI *NonMember_Login();

void loop_free(UI *head);

void login_member()
{
	char cid[18];
	char cpassword[20];
	FILE *fp_in;
	fp_in = fopen("data1.txt", "r");
	UI *head, *temp;
	head = (UI*)malloc(sizeof(UI));
	head->next = NULL;
	temp = head;
	printf("���̵�:");
	scanf("%s", &cid);
	printf("���й�ȣ:");
	scanf("%s", &cpassword);

	while (!feof(fp_in))
	{
		fscanf(fp_in, "%s %s %s %s %s\n", temp->id, temp->password, temp->name, temp->phone, temp->userNumber);
		if (strcmp(temp->id, cid) == 0 && strcmp(temp->password, cpassword) == 0)
		{
			printf("�α��� �Ǽ̽��ϴ�.");
			return;
		}
		else
			temp->next = (UI*)malloc(sizeof(UI));
		temp = temp->next;
	}
	printf("���̵��� �н����尡 ���ų� �߸� �Է��ϼ̽��ϴ�.");
	return;
}
void login_nonmember()
{
	char id[20], phone[30];
	FILE *fp_out1, *fp_out2;
	fp_out1 = fopen("user_nonmember_data.txt", "a");
	fp_out2 = fopen("user_data.txt", "a");
	printf("�̸�:");
	scanf("%s", &id);
	printf("�ڵ��� ��ȣ:");
	scanf("%s", &phone);
	fprintf(fp_out1, "%s %s", id, phone);
	fprintf(fp_out2, "%s",id);
	fclose(fp_out1);
	fclose(fp_out2);
	return;
}

//void loop_free(UI *head) {
//	UI *temp, *current;
//	for (temp = head; temp != NULL; temp = current)
//	{
//		current = temp->next;
//		free(temp);
//	}
//
//}
