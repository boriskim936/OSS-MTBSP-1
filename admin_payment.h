#include<stdio.h>


typedef struct setting //관리자모드 예매가격 변경 구조체
{

   char adult_m[20];//어른 가격
   char teen_m[20]; //청소년 가격
   char senior_m[20]; //우대 가격
   char child_m[20]; //어린이 가격
}setting;


void print_setting();

   void main()//관리자모드 표가격고치기
   {
      setting adult_m1, teen_m1, senior_m1, child_m1;

      FILE *fpout; //파일 포인터 변수선언

      fpout = fopen("payment_data.txt", "w"); //텍스트파일을 쓰기전용으로 열기

      if (fpout == NULL) //파일이 없을경우
      {
         printf("파일열기 실패");
         return;
      }



      printf("변경할 어른표 가격을 입력하세요\n"); //입력시 '어른6000' 이런식으로 입력해야함
      scanf("%s" ,adult_m1.adult_m);
      fprintf(fpout, "%s", adult_m1.adult_m); //fpout에 입력받은 데이터저장하기

      printf("변경할 청소년표의 가격을 입력하세요\n");
      scanf("%s", teen_m1.teen_m);
      fprintf(fpout, "%s", teen_m1.teen_m);

      printf("변경할 우대표의 가격을 입력하세요\n");
      scanf("%s", senior_m1.senior_m);
      fprintf(fpout, "%s", senior_m1.senior_m);

      printf("변경할 어린이표의 가격을 입력하세요\n");
      scanf("%s", child_m1.child_m);
      fprintf(fpout, "%s", child_m1.child_m);


      fclose(fpout);



      print_setting();
      return;
   }
void print_setting() //파일이 띄어쓰기없이 저장되어 이어서 출력됨 고쳐야함
{
   FILE *fpin = NULL;
   setting adult_m1, teen_m1, senior_m1, child_m1;
   fpin = fopen("payment_data.txt", "r");

   while (!feof(fpin))
   {
      fscanf(fpin, "%s", adult_m1.adult_m);
      printf("새로 바뀐 표의 가격은 %s", adult_m1.adult_m);

   }

}
