#include <stdio.h>
#include <stdlib.h>

#define N
#define M

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
	
	int sm[N][N];s
	int sc[N][N];
	
	srand(time(NULL));
	
	return 0;
}
