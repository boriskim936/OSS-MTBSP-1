
#include<stdio.h>
int main()
{
	char answer; //결제y/n
	int payment; //결제수단고르기
	int cash; //현금
	int cardnumber; //카드번호
	int happymoney; //문화상품권번호

	printf("결제하시겠습니까? y/n\n");
	scanf("\n%c", &answer);
	if (answer == 'y')
	{
		printf("결제수단을 고르세요\n");
		printf("1.현금 2.카드 3.문화상품권\n");
		scanf("%d", &payment);
		switch (payment)
		{
		case 1:
			printf("현금을 입력하세요\n");
			scanf("%d", &cash);
			printf("총금액은 %d입니다\n", cash);
			printf("결제가 완료되었습니다.\n");
			break;
		case 2:

			printf("카드번호를 입력하세요\n");
			scanf("%d", &cardnumber);

			printf("결제가 완료되었습니다\n");
			break;
		case 3:
			printf("문화상품권 번호를 입력하세요\n");
			scanf("%d", &happymoney);
			printf("결제가 완료되었습니다\n");
			break;
		}
	}
}
