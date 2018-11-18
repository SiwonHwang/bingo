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
	int Mechoice; //���� ������ ���� 
	int Comchoice; //��ǻ�Ͱ� ������ ���� 
	
	printf("���� ������ �����մϴ�.\n");
	printf("�������� %i�� ���� ä�� �� �¸��մϴ�.\n\n", M); 
	
	initiate_bingo(N, bingoMe); //�� ���� ���̺� �������  
    initiate_bingo(N, bingoCom); //��ǻ�� ���� ���̺� �������  
	  
	print_bingo(N, bingoMe); //�� ���� ���̺� ȭ�鿡 ��� 
	
	get_number_byMe(Mechoice);
	
	return 0;
}


void initiate_bingo(int n, int bingotable[n][n]){ //bingotable = ���� ���̺��� ����� 2���� �迭 
	
	int i, j;
	int max = n*n;
	
	srand((unsigned)time(NULL));
	
	for (i=0; i<max; i++){
		bingotable[0][i] = 1+rand()%max; //���� ���̺� ���� �߻�  
		
		for (j=0; j<i; j++){
			if (bingotable[0][j] == bingotable[0][i]){
				i--; 
				break; //���� ���̺� �ߺ� ���� 
			}
		}
	}
	
}
	
void print_bingo(int n, int bingotable[n][n]){
	
	int i, j;
	
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			printf("%d ", bingotable[i][j]);
		}
		printf("\n"); //N*N ���·� ȭ�鿡 ���� ���̺� ���  
	}
	printf("\n");
}

void get_number_byMe(int i){
		
	printf("���� �ϳ��� �����ϼ��� : %d\n");
	scanf("%d", &i);
} 
