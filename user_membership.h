#include <stdio.h>
#include <malloc.h>
#include "struct_membership.h"
#include "loop_free.h"
#pragma warning(disable:4996)


UI *Membership(UI *head, UI *tail);
void loop_free(UI *head);

void membership()
{
	FILE *fp_in, *fp_out;
	fp_out = fopen("data1.txt", "a");
	UI *head=NULL, *temp, *current, *tail = NULL;
	temp = (UI*)malloc(sizeof(UI));
	current = head;
	printf("ID:");
	scanf("%s", temp->id);
	printf("PASSWORD:");
	scanf("%s", temp->password);
	printf("이름:");
	scanf("%s", temp->name);
	printf("폰번호:");
	scanf("%s", temp->phone);
	printf("주민번호 앞6자리:");
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
