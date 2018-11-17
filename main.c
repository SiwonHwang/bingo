#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4 // ���� ���̺� ��ȣ���  
#define M 3 // ���� �̱�� ���� ��ȣ���  

/*
initiate_bingo() : ���� ���̺��� �ʱ⿡ ������ִ� �Լ� 
ptint_bingo() : ���� ���̺� �����Ȳ�� ȭ�鿡 ��� 
get_number_byMe() : ���� ���� ��ȣ �Է� ���� 
get_number_byCom() : ��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ���� 
process_bingo() : ���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä�� 
count_bingo() : ���� ���̺��� ä�� ����/����/�밢�� �� ���� ����Ͽ� ��ȯ 
*/

int main(void){
	
	int bingoMe[N][N]; //�� ���� ���̺� 
	int bingoCom[N][N]; //��ǻ�� ���� ���̺� 
	int MeNum; //���� ������ ���� 
	int ComNum; //��ǻ�Ͱ� ������ ���� 
	
	void initiate_bingo(N, bingoMe);
	void print_bingo(N, bingoMe);
	
	return 0;
}


void initiate_bingo(int n, bingotable[n][n]){
	
	int bingotable[n][n];
	int i, j;
	int max = n*n
	
	srand((unsigned)time(NULL));
	
	for (i=0; i<max; i++){
		bingMe[0][i] = rand()%max;
		
		for (j=0; j<i; j++){
			if (bingotable[0][j] == bingotable[0][i]){
				i--;
				break;
			}
		}
	}
	
}
	
void print_bingo(int n, bingotable[n][n]){
	
	int bingotable[n][n];
	int i, j;
	
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			printf("%d ", bingotable[i][j]);
		}
	}
}













