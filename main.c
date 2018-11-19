#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4 // 빙고 테이블 기호상수  
#define M 3 // 빙고 이기는 조건 기호상수  

/*
initiate_bingo() : 빙고 테이블을 초기에 만들어주는 함수 
ptint_bingo() : 빙고 테이블 현재상황을 화면에 출력 
get_number_byMe() : 내가 빙고 번호 입력 선택 
get_number_byCom() : 컴퓨터가 임의로 빙고 번호 선택 
process_bingo() : 선택된 숫자를 입력받아서 빙고 테이블 칸을 채움 
count_bingo() : 빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산하여 반환 
*/

int main(void){
	
	
	int tableMe[N][N]; //내 빙고 테이블 
	int tableCom[N][N]; //컴퓨터 빙고 테이블
	int numbyMe; //내가 선택한 숫자 
	int numbyCom; //컴퓨터가 선택한 숫자 
	int countMe; //내 빙고줄 수  
	int countCom; //컴퓨터 빙고줄 수    
	int turn=0; //turn수 선언 및 초기화  
	
	printf("#빙고 게임을 시작합니다.#\n");
	printf("#빙고판을 %i줄 먼저 채울 시 승리합니다.#\n\n", M); 
	
	initiate_bingo(N, tableMe); //내 빙고 테이블 만들어줌  
    initiate_bingo(N, tableCom); //컴퓨터 빙고 테이블 만들어줌  
      
    
    do
    {	
    	print_bingo(N, tableMe); //내 빙고 테이블 화면에 출력
    	
    	get_number_byMe(numbyMe); //내가 숫자 선택  
    	get_number_byCom(numbyCom); //컴퓨터가 숫자 선택  
    	
    	turn++; //turn수 증가  
    	
	}while((countMe != M) && (countCom != M));
	//나 혹은 컴퓨터가 M빙고를 완성하기 전까지 반복
	
	if ((countMe == M) && (countCom != M)){
		printf("#당신이 승리하였습니다.#\n");
	}
	else if ((countMe != M) && (countCom == M)){
		printf("#컴퓨터가 승리하였습니다.#");
	}
	else if ((countMe == M) && (countCom == M)){
		printf("#비겼습니다.#");
	} //결과 출력  
	  
	printf("#turn : %d회#", turn); //총 turn수 출력  
	
	return 0;
}


void initiate_bingo(int n, int bingotable[n][n]){ //bingotable = 빙고 테이블을 만드는 2차원 배열 
	
	int i, j;
	int max = n*n;
	
	srand((unsigned)time(NULL));
	
	for (i=0; i<max; i++){
		bingotable[0][i] = 1+rand()%max; //빙고 테이블에 난수 발생  
		
		for (j=0; j<i; j++){
			if (bingotable[0][j] == bingotable[0][i]){
				i--; 
				break; //빙고 테이블 중복 제거 
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
		printf("\n"); //N*N 형태로 화면에 빙고 테이블 출력  
	}
	printf("\n");
}

void get_number_byMe(int numbyMe){
	
	int numbyCom;
		
	printf("숫자 하나를 선택하세요 : ");
	scanf("%d", &numbyMe); //내가 선택하는 숫자
	
	if((numbyMe>N*N) || (numbyMe<1)){
		printf("\n#1부터 %d 사이의 숫자 중 선택하세요.#\n\n", N*N);
		
		get_number_byMe(numbyMe);
	} //선택한 숫자가 범위 외의 숫자일 경우 다시 실행  
	else if(numbyMe == numbyCom){
		printf("\n#현재까지 선택되지 않은 숫자 중 선택하세요.#\n\n");
		
		get_number_byMe(numbyMe);
	} //선택한 숫자가 컴퓨터가 선택한 숫자와 같을 경우 다시 실행  
} 

void get_number_byCom(int numbyCom){
	
	int numbyMe;
	
	printf("\n컴퓨터가 숫자 하나를 선택합니다.\n\n");
	
	srand((unsigned int)time(NULL)); //컴퓨터가 선택하는 숫자 랜덤 발생  
	
	numbyCom = 1+rand()%(N*N);
	
	if(numbyCom == numbyMe){
		get_number_byCom(numbyCom);
	} //랜덤 발생한 숫자가 내가 선택한 숫자와 같을 경우 다시 실행  
}
