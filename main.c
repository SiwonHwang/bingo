#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 3

/*
initiate_bingo() : ���� ���̺��� �ʱ⿡ ������ִ� �Լ� 
ptint_bingo() : ���� ���̺� �����Ȳ�� ȭ�鿡 ��� 
get_number_byMe() : ���� ���� ��ȣ �Է� ���� 
get_number_byCom() : ��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ���� 
process_bingo() : ���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä�� 
count_bingo() : ���� ���̺��� ä�� ����/����/�밢�� �� ���� ����Ͽ� ��ȯ 
*/


int initiate_bingo();
int ptint_bingo();
int get_number_byMe();
int get_number_byCom();
int process_bingo();
int count_bingo();


int main(void){
	
	int Me[N][N]; //�� ���� ���̺� 
	int Com[N][N]; //��ǻ�� ���� ���̺� 
	int MeNum; //���� ������ ���� 
	int ComNum; //��ǻ�Ͱ� ������ ���� 
	int i, j;
	
	srand(time(NULL));
		for (i=0; i<N; i++)
		{
			for(j=0; j<N; j++)
			{
				printf("%d ", 1+rand()%(N*N)); 
			}
		printf("\n");
		}
	
	return 0;
}
