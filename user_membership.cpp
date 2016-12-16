#include "user_membership.h"
#pragma warning(disable:4996)


void membership()
{
	system("cls");
	FILE *fp_in, *fp_out;
	printf("\n");
	fp_out = fopen("membership_data.txt", "a");
	UI *head = NULL, *temp, *current, *tail = NULL;
	temp = (UI*)malloc(sizeof(UI));
	current = head;
	printf("[아이디]: ");
	scanf("%s", temp->id);
	printf("\n");
	printf("[비밀번호]: ");
	scanf("%s", temp->password);
	printf("\n");
	printf("[이름]: ");
	scanf("%s", temp->name);
	printf("\n");
	printf("[폰번호]: ");
	scanf("%s", temp->phone);
	printf("\n");
	printf("[주민번호 앞6자리]: ");
	scanf("%s", temp->userNumber);


	if (head->id == NULL)
	{
		head = temp;
		tail = temp;
		fprintf(fp_out, "%s %s %s %s %s\n", head->id, head->password, head->name, head->phone, head->userNumber);
		fclose(fp_out);
		return;
	}
	else
	{
		tail->next = temp;
		tail = temp;
		for (current = head; current != tail; current = current->next)
		{
			fprintf(fp_out, "%s %s %s %s %s\n", current->id, current->password, current->name, current->phone, current->userNumber);
		}
		fclose(fp_out);
	}
	return;
}
