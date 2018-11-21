#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4 // ���� ���̺� ��ȣ���  
#define M 3 // ���� �̱�� ���� ��ȣ���  


int initiate_bingo(int bingotable[N][N]);
int print_bingo(int bingotable[N][N]);
int get_number_byMe(int numbyMe, int numbyCom);
int get_number_byCom(int numbyCom, int numbyMe);
int process_bingo(int selectednum, int bingotable[N][N]);
int count_bingo(int bingotable[N][N], int count);

   
int tableMe[N][N]; //�� ���� ���̺� 
int tableCom[N][N]; //��ǻ�� ���� ���̺�
	
int numbyMe; //���� ������ ���� 
int numbyCom; //��ǻ�Ͱ� ������ ���� 
	
int countMe = 0; //�� ������ ��  
int countCom = 0; //��ǻ�� ������ ��    
	
int turn = 0; //turn�� ���� �� �ʱ�ȭ  

int main(void){
	
	printf("#���� ������ �����մϴ�.#\n");
	printf("#�������� %i�� ���� ä�� �� �¸��մϴ�.#\n\n", M); 
	printf("------------------------------------\n\n");
	
	initiate_bingo(tableMe); //�� ���� ���̺� �������  
    initiate_bingo(tableCom); //��ǻ�� ���� ���̺� �������  
      
    
    do
    {	
        printf("<���� ����� ������>\n\n");
        print_bingo(tableMe); //�� ���� ���̺� ȭ�鿡 ���
    	
    	get_number_byMe(numbyMe, numbyCom); //���� ���� ����  
    	get_number_byCom(numbyCom, numbyMe); //��ǻ�Ͱ� ���� ����  
    	
    	process_bingo(numbyMe, tableMe); //���� ������ ���ڷ� �� �������̺� ä���  
    	process_bingo(numbyCom, tableMe); //��ǻ�Ͱ� ������ ���ڷ� �� �������̺� ä���
    	process_bingo(numbyMe, tableCom); //���� ������ ���ڷ� ��ǻ�� �������̺� ä���  
    	process_bingo(numbyCom, tableCom); //��ǻ�Ͱ� ������ ���ڷ� ��ǻ�� �������̺� ä���
		 
    	count_bingo(tableMe, countMe); //�� ���� ���̺��� ���� �� ����  
    	count_bingo(tableCom, countCom); //��ǻ�� ���� ���̺��� ���� �� ���� 
		 
    	printf("\n#���� ����� ���� �� : %d#\n\n", countMe); //��������� �� ���� �� ���  
    	
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

int initiate_bingo(int bingotable[N][N]){ //bingotable = ���� ���̺��� ����� 2���� �迭 
	
	
	int i, j;
	int table[N*N]; //1���� �迭��  
	int x;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			bingotable[i][j] = 0; //���� ���̺� �ʱ�ȭ  
		}
	}
	
	for (i=0; i<N*N; i++)
	{
		table[i] = 0;
	}
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			while (1)
			{
				x = 1+rand()%(N*N); //���� �߻�  
				
				if (table[x-1] == 0)
				{
					bingotable[i][j] = x;
					table[x-1] = 1; //�ߺ� ����  
					break;
				 } 
			}
		}
	} //���� �߻���Ų �� �ߺ� ����  

}
	
int print_bingo(int bingotable[N][N]){
	
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			printf("%2d ", bingotable[i][j]);
		}
		printf("\n"); //N*N ���·� ȭ�鿡 ���� ���̺� ���  
	}
	printf("\n");
}

int get_number_byMe(int numbyMe, int numbyCom){
		
	printf("���� �ϳ��� �����ϼ��� : ");
	scanf("%d", &numbyMe); //���� �����ϴ� ����
	
	if((numbyMe>N*N) || (numbyMe<1))
	{
		printf("\n#1���� %d ������ ���� �� �����ϼ���.#\n\n", N*N);
		
		get_number_byMe(numbyMe, numbyCom);
	} //������ ���ڰ� ���� ���� ������ ��� �ٽ� ����  
	else if((numbyMe == numbyCom))
	{
		printf("\n#������� ���õ��� ���� ���� �� �����ϼ���.#\n\n");
		
		get_number_byMe(numbyMe, numbyCom);
	} //������ ���ڰ� ��ǻ�Ͱ� ������ ���ڿ� ���� ��� �ٽ� ����  
	
	return numbyMe;
} 

int get_number_byCom(int numbyCom, int numbyMe){
	
	printf("\n��ǻ�Ͱ� ���� �ϳ��� �����մϴ�.\n\n");
	
	srand((unsigned int)time(NULL));
	
	numbyCom = 1+rand()%(N*N); //��ǻ�Ͱ� �����ϴ� ���� ���� �߻�
	
	if(numbyCom == numbyMe)
	{
		get_number_byCom(numbyCom, numbyMe);
	} //���� �߻��� ���ڰ� ���� ������ ���ڿ� ���� ��� �ٽ� ����  
	
	printf("��ǻ�Ͱ� ������ ���ڴ� %d�Դϴ�.\n\n", numbyCom);
	printf("------------------------------------\n");
	
	return numbyCom;
}

int process_bingo(int selectednum, int bingotable[N][N]){
	
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if (bingotable[i][j] == selectednum)
			{
				bingotable[i][j] = -1; //������ ���ڸ� �����ǿ��� -1�� �ٲ�� ��. 
			}
			
		}
    }
    
    return 0;
}


int count_bingo(int bingotable[N][N], int count){
	
	int i, j;
	int sum = 0;
	
	 for (i=0; i<N; i++)
	 {
	 	for (j=0; j<N; j++)
	 	{
	 		sum += bingotable[i][j];
	 		
	 		if(sum == (-1)*N) //���õ� ���ڴ� -1�� �ٲ�. ���� -1*N�� �Ǹ� ��� ���õ���, �� ���� ������ �ǹ���  
	 		{
	 			count++; //���� �� ����  
			 }
		 }
	 } //���� ����� ���� 
	 
	 for (j=0; j<N; j++)
	 {
	 	for (i=0; i<N; i++)
	 	{
	 		sum += bingotable[i][j];
	 		
	 		if(sum == (-1)*N)
	 		{
	 			count++;
			 }
		 }
	  } //���� ����� ����  
	 
	 for (i=0; i<N; i++)
	 {
	    for (j=0; j<N; j++)
	 	{
	 		if(i==j) //������ �Ʒ����� �밢���� ��� ���� ���� ����  
	 		{
	 			sum += bingotable[i][j];
	 			
	 			if(sum == (-1)*N)
	 			{
	 				count++;
				 }
			 }
		 }
	 } //������ �Ʒ����� �밢�� ����� ����  
	 
	 for (i=0; i<N; i++)
	 {
	 	for (j=0; j<N; j++)
	 	{
	 		if(i+j == N-1) //���� �Ʒ����� �밢���� ��� ���� �� ���� N-1��  
	 		{
	 			sum += bingotable[i][j];
	 			
	 			if(sum == (-1)*N)
	 			{
	 				count++;
				 }
			 }
		 }
	 } // ���� �Ʒ����� �밢�� ����� ����  
	 
	 return count; 
}












