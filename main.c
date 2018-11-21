#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4 // 빙고 테이블 기호상수  
#define M 3 // 빙고 이기는 조건 기호상수  


int initiate_bingo(int bingotable[N][N]);
int print_bingo(int bingotable[N][N]);
int get_number_byMe(int numbyMe, int numbyCom);
int get_number_byCom(int numbyCom, int numbyMe);
int process_bingo(int selectednum, int bingotable[N][N]);
int count_bingo(int bingotable[N][N], int count);

   
int tableMe[N][N]; //내 빙고 테이블 
int tableCom[N][N]; //컴퓨터 빙고 테이블
	
int numbyMe; //내가 선택한 숫자 
int numbyCom; //컴퓨터가 선택한 숫자 
	
int countMe = 0; //내 빙고줄 수  
int countCom = 0; //컴퓨터 빙고줄 수    
	
int turn = 0; //turn수 선언 및 초기화  

int main(void){
	
	printf("#빙고 게임을 시작합니다.#\n");
	printf("#빙고판을 %i줄 먼저 채울 시 승리합니다.#\n\n", M); 
	printf("------------------------------------\n\n");
	
	initiate_bingo(tableMe); //내 빙고 테이블 만들어줌  
    initiate_bingo(tableCom); //컴퓨터 빙고 테이블 만들어줌  
      
    
    do
    {	
        printf("<현재 당신의 빙고판>\n\n");
        print_bingo(tableMe); //내 빙고 테이블 화면에 출력
    	
    	get_number_byMe(numbyMe, numbyCom); //내가 숫자 선택  
    	get_number_byCom(numbyCom, numbyMe); //컴퓨터가 숫자 선택  
    	
    	process_bingo(numbyMe, tableMe); //내가 선택한 숫자로 내 빙고테이블 채우기  
    	process_bingo(numbyCom, tableMe); //컴퓨터가 선택한 숫자로 내 빙고테이블 채우기
    	process_bingo(numbyMe, tableCom); //내가 선택한 숫자로 컴퓨터 빙고테이블 채우기  
    	process_bingo(numbyCom, tableCom); //컴퓨터가 선택한 숫자로 컴퓨터 빙고테이블 채우기
		 
    	count_bingo(tableMe, countMe); //내 빙고 테이블의 빙고 수 세기  
    	count_bingo(tableCom, countCom); //컴퓨터 빙고 테이블의 빙고 수 세기 
		 
    	printf("\n#현재 당신의 빙고 수 : %d#\n\n", countMe); //현재까지의 내 빙고 수 출력  
    	
    	turn++; //turn수 증가  
    	
	}while((countMe != M) && (countCom != M));
	//나 혹은 컴퓨터가 M빙고를 완성하기 전까지 반복
	
	
	if ((countMe == M) && (countCom != M))
	{
		printf("#당신이 승리하였습니다.#\n");
	}
	else if ((countMe != M) && (countCom == M))
	{
		printf("#컴퓨터가 승리하였습니다.#");
	}
	else if ((countMe == M) && (countCom == M))
	{
		printf("#비겼습니다.#");
	} //결과 출력  
	  
	printf("#turn : %d회#", turn); //총 turn수 출력  
	
	return 0;
}

int initiate_bingo(int bingotable[N][N]){ //bingotable = 빙고 테이블을 만드는 2차원 배열 
	
	
	int i, j;
	int table[N*N]; //1차원 배열로  
	int x;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			bingotable[i][j] = 0; //빙고 테이블 초기화  
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
				x = 1+rand()%(N*N); //난수 발생  
				
				if (table[x-1] == 0)
				{
					bingotable[i][j] = x;
					table[x-1] = 1; //중복 제거  
					break;
				 } 
			}
		}
	} //난수 발생시킨 후 중복 제거  

}
	
int print_bingo(int bingotable[N][N]){
	
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			printf("%2d ", bingotable[i][j]);
		}
		printf("\n"); //N*N 형태로 화면에 빙고 테이블 출력  
	}
	printf("\n");
}

int get_number_byMe(int numbyMe, int numbyCom){
		
	printf("숫자 하나를 선택하세요 : ");
	scanf("%d", &numbyMe); //내가 선택하는 숫자
	
	if((numbyMe>N*N) || (numbyMe<1))
	{
		printf("\n#1부터 %d 사이의 숫자 중 선택하세요.#\n\n", N*N);
		
		get_number_byMe(numbyMe, numbyCom);
	} //선택한 숫자가 범위 외의 숫자일 경우 다시 실행  
	else if((numbyMe == numbyCom))
	{
		printf("\n#현재까지 선택되지 않은 숫자 중 선택하세요.#\n\n");
		
		get_number_byMe(numbyMe, numbyCom);
	} //선택한 숫자가 컴퓨터가 선택한 숫자와 같을 경우 다시 실행  
	
	return numbyMe;
} 

int get_number_byCom(int numbyCom, int numbyMe){
	
	printf("\n컴퓨터가 숫자 하나를 선택합니다.\n\n");
	
	srand((unsigned int)time(NULL));
	
	numbyCom = 1+rand()%(N*N); //컴퓨터가 선택하는 숫자 랜덤 발생
	
	if(numbyCom == numbyMe)
	{
		get_number_byCom(numbyCom, numbyMe);
	} //랜덤 발생한 숫자가 내가 선택한 숫자와 같을 경우 다시 실행  
	
	printf("컴퓨터가 선택한 숫자는 %d입니다.\n\n", numbyCom);
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
				bingotable[i][j] = -1; //선택한 숫자를 빙고판에서 -1로 바뀌도록 함. 
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
	 		
	 		if(sum == (-1)*N) //선택된 숫자는 -1로 바뀜. 합이 -1*N이 되면 모두 선택됐음, 즉 빙고가 됐음을 의미함  
	 		{
	 			count++; //빙고 수 증가  
			 }
		 }
	 } //가로 빙고수 세기 
	 
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
	  } //세로 빙고수 세기  
	 
	 for (i=0; i<N; i++)
	 {
	    for (j=0; j<N; j++)
	 	{
	 		if(i==j) //오른쪽 아래방향 대각선은 행과 열의 수가 같음  
	 		{
	 			sum += bingotable[i][j];
	 			
	 			if(sum == (-1)*N)
	 			{
	 				count++;
				 }
			 }
		 }
	 } //오른쪽 아래방향 대각선 빙고수 세기  
	 
	 for (i=0; i<N; i++)
	 {
	 	for (j=0; j<N; j++)
	 	{
	 		if(i+j == N-1) //왼쪽 아래방향 대각선은 행과 열의 수 합이 N-1임  
	 		{
	 			sum += bingotable[i][j];
	 			
	 			if(sum == (-1)*N)
	 			{
	 				count++;
				 }
			 }
		 }
	 } // 왼쪽 아래방향 대각선 빙고수 세기  
	 
	 return count; 
}












