#include "user_movie_payment.h"
#pragma warning(disable:4996)
void *movie_select_payment(user *user_temp)
{
	char name[20];
	int payment; //결제수단고르기
	int cash; //현금
	char cardnumber[20]; //카드번호
	char giftnumber[20]; //문화상품권 번호
	char data_giftnumber[20]; //비교할 문화상품권 번호
	int go;
	printf("\n");
	printf("[1] 현금 결제하기\n\n");
	printf("[2] 카드 결제하기\n\n");
	printf("[3] 문화상품권 결제하기\n\n");
	printf("결제수단을 고르세요(숫자입력): ");
	scanf("%d", &payment);
	system("cls");
	switch (payment)
	{
	case 1:
		printf("\n");
		printf("총 [%d원]입니다.\n\n현금을 입력하세요: ", user_temp->user_payment);
		scanf("%d", &cash);
		printf("\n결제가 완료되었습니다.\n아무거나 눌러주세요");
		go = getch();
		break;
	case 2:
		printf("\n");
		printf("총 [%d원]입니다.\n", user_temp->user_payment);
		printf("이름을 입력하여주세요: ");
		scanf("%s", &name);
		printf("\n카드번호를 입력하세요: ");
		scanf("%s", &cardnumber);
		printf("결제가 완료되었습니다\n아무거나 눌러주세요");
		FILE *fp_out;
		fp_out = fopen("payment_card_data.txt", "a");
		fprintf(fp_out, "%s %s\n", &name, &cardnumber);
		fclose(fp_out);
		go = getch();
		break;
	case 3:
		printf("\n");
		printf("총 [%d원]입니다.\n", user_temp->user_payment);
		printf("문화상품권 번호를 입력하세요.(Pin 16자리 숫자): \n");
		scanf("%s", &giftnumber);
		FILE *fp_in;
		fp_in = fopen("payment_gitfnumber_data.txt", "r");
		while (!feof(fp_in))
		{
			fscanf(fp_in, "%s\n", &data_giftnumber);
			if (strcmp(data_giftnumber, giftnumber) == 0)
			{
				printf("결제가 완료되었습니다.\n아무거나 눌러주세요");
				go = getch();
				return 0;
			}
			else
				printf("잘못된 번호입니다.\n");
		}
		fclose(fp_in);
		break;
	}
	return 0;
}
