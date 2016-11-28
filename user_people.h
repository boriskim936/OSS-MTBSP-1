#include<stdio.h>



typedef struct buy //회원,비회원모드 예매 인원입력 구조체
{
	int adult; //어른
	int teen; //청소년
	int senior; //우대
	int child; //어린이
};


void print_buy();

void main()//회원,비회원모드 인원수받아넣기
{
	setting adult_m1, teen_m1, senior_m1, child_m1;//정의
	buy adult_n, teen_n, senior_n, child_n;//정의

	FILE *fpout; //파일 포인터 변수선언

	fpout = fopen("data.txt", "w"); //텍스트파일을 쓰기전용으로 열기

	if (fpout == NULL) //파일이 없을경우
	{
		printf("파일열기 실패");
		return;
	}



	printf("어른은 몇명입니까?\n");
	scanf("%d", &adult_n.adult);
	fprintf(fpout, "%d", adult_n.adult); //fpout에 입력받은 데이터저장하기

	printf("청소년은 몇명입니까?\n\n");
	scanf("%d", &teen_n.teen);
	fprintf(fpout, "%d", teen_n.teen);

	printf("우대은 몇명입니까?\n\n");
	scanf("%d", &senior_n.senior);
	fprintf(fpout, "%d", senior_n.senior);

	printf("어린이은 몇명입니까?\n");
	scanf("%d", &child_n.child);
	fprintf(fpout, "%d", child_n.child);


	fclose(fpout);



	print_buy();
	return;


}

void print_buy() //파일이 출력안됨 고쳐야함(파일출력함수)
{
	int count;//텍스트파일 읽어온 숫자
	int adult;//어른인원변수
	int teen;//청소년인원변수
	int senior;//우대인원변수
	int child;//어린이 우대변수

	int i = 0;
	FILE *fpin = NULL;
	buy adult_n, teen_n, senior_n, child_n;
	fpin = fopen("data.txt", "r");

	fscanf(fpin, "%d", &count);

	while (!feof(fpin))
	{
		adult = count / 1000;
		teen = count / 100 % 10;
		senior = (count % 100) / 10;
		child = count % 10;


	}

	printf("어른 %d명 청소년 %d 우대 %d명 어린이 %d", adult, teen, senior, child);

}
