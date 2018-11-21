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
	
	
	int tableMe[N][N]; //�� ���� ���̺� 
	int tableCom[N][N]; //��ǻ�� ���� ���̺�
	
	int numbyMe; //���� ������ ���� 
	int numbyCom; //��ǻ�Ͱ� ������ ���� 
	
	int countMe = 0; //�� ������ ��  
	int countCom = 0; //��ǻ�� ������ ��    
	
	int turn = 0; //turn�� ���� �� �ʱ�ȭ  
	
	printf("#���� ������ �����մϴ�.#\n");
	printf("#�������� %i�� ���� ä�� �� �¸��մϴ�.#\n\n", M); 
	
	initiate_bingo(N, tableMe); //�� ���� ���̺� �������  
    initiate_bingo(N, tableCom); //��ǻ�� ���� ���̺� �������  
      
    
    do
    {	
        printf("<���� ����� ������>\n\n");
        print_bingo(N, tableMe); //�� ���� ���̺� ȭ�鿡 ���
    	
    	get_number_byMe(numbyMe); //���� ���� ����  
    	get_number_byCom(numbyCom); //��ǻ�Ͱ� ���� ����  
    	
    	process_bingo(numbyMe, tableMe); //���� ������ ���ڷ� �� �������̺� ä���  
    	process_bingo(numbyCom, tableMe); //��ǻ�Ͱ� ������ ���ڷ� �� �������̺� ä���
    	process_bingo(numbyMe, tableCom); //���� ������ ���ڷ� ��ǻ�� �������̺� ä���  
    	process_bingo(numbyCom, tableCom); //��ǻ�Ͱ� ������ ���ڷ� ��ǻ�� �������̺� ä���
		 
    	count_bingo(tableMe, countMe); //�� ���� ���̺��� ���� �� ����  
    	count_bing(tableCom, countCom); //��ǻ�� ���� ���̺��� ���� �� ���� 
		 
    	printf("<���� ����� ���� �� : %d", countMe); //��������� �� ���� �� ���  
    	
    	turn++; //turn�� ����  
    	
	}while((countMe != M) && (countCom != M));
	//�� Ȥ�� ��ǻ�Ͱ� M���� �ϼ��ϱ� ������ �ݺ�
	
	
	if ((countMe == M) && (countCom != M))
	{
		printf("#����� �¸��Ͽ����ϴ�.#\n");
	}
	else if ((countMe != M) && (countCom == M))
	{
		printf("#��ǻ�Ͱ� �¸��Ͽ����ϴ�.#");
	}
	else if ((countMe == M) && (countCom == M))
	{
		printf("#�����ϴ�.#");
	} //��� ���  
	  
	printf("#turn : %dȸ#", turn); //�� turn�� ���  
	
	return 0;
}


int initiate_bingo(int n, int bingotable[n][n]){ //bingotable = ���� ���̺��� ����� 2���� �迭 
	
	int i, j;
	int max = n*n;
	
	srand((unsigned)time(NULL));
	
	for (i=0; i<max; i++){
		bingotable[0][i] = 1+rand()%max; //���� ���̺� ���� �߻�  
		
		for (j=0; j<i; j++)
		{
			if (bingotable[0][j] == bingotable[0][i])
			{
				i--; 
				break; //���� ���̺� �ߺ� ���� 
			}
		}
	}
	
}
	
int print_bingo(int n, int bingotable[n][n]){
	
	int i, j;
	
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%d ", bingotable[i][j]);
		}
		printf("\n"); //N*N ���·� ȭ�鿡 ���� ���̺� ���  
	}
	printf("\n");
}

int get_number_byMe(int numbyMe){
	
	int numbyCom;
		
	printf("���� �ϳ��� �����ϼ��� : ");
	scanf("%d", &numbyMe); //���� �����ϴ� ����
	
	if((numbyMe>N*N) || (numbyMe<1))
	{
		printf("\n#1���� %d ������ ���� �� �����ϼ���.#\n\n", N*N);
		
		get_number_byMe(numbyMe);
	} //������ ���ڰ� ���� ���� ������ ��� �ٽ� ����  
	else if(numbyMe == numbyCom)
	{
		printf("\n#������� ���õ��� ���� ���� �� �����ϼ���.#\n\n");
		
		get_number_byMe(numbyMe);
	} //������ ���ڰ� ��ǻ�Ͱ� ������ ���ڿ� ���� ��� �ٽ� ���� -> ���� �ȵ� �ذ��ϱ�  
} 

int get_number_byCom(int numbyCom){
	
	int numbyMe;
	
	printf("\n��ǻ�Ͱ� ���� �ϳ��� �����մϴ�.\n\n\n");
	
	srand((unsigned int)time(NULL));
	
	numbyCom = 1+rand()%(N*N); //��ǻ�Ͱ� �����ϴ� ���� ���� �߻�
	
	if(numbyCom == numbyMe)
	{
		get_number_byCom(numbyCom);
	} //���� �߻��� ���ڰ� ���� ������ ���ڿ� ���� ��� �ٽ� ����  
}

int process_bingo(int selectednum, int bingotable[N][N]){
	
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if(bingotable[i][j] == selectednum)
			{
				bingotable[i][j] = -1; //������ ����(numbyMe, numbyCom)�� �����ǿ��� -1�� �ٲ�� ��. 
			}
			
		}
    }
}

//numbyMe - call by reference �ذ��ϱ�

int count_bingo(int bingotable[N][N], int count){
	
	int i, j;
	
	 //����, ����, �밢���� ���� -1*N�� �Ǹ� ���� �� �� �ϼ� 
	 
	 for (i=0; i<N; i++)
	 {
	 	for (j=0; j<N; j++)
	 	{
	 		if(i==j)
	 		{
	 			
			 }
		 }
	 } //�밢�� ����� ����  
	 
}












