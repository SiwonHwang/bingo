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
	
	int bingoMe[N][N]; //내 빙고 테이블 
	int bingoCom[N][N]; //컴퓨터 빙고 테이블 
	int MeNum; //내가 선택한 숫자 
	int ComNum; //컴퓨터가 선택한 숫자 
	
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













