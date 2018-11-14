#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 3

/*
initiate_bingo() : 빙고 테이블을 초기에 만들어주는 함수 
ptint_bingo() : 빙고 테이블 현재상황을 화면에 출력 
get_number_byMe() : 내가 빙고 번호 입력 선택 
get_number_byCom() : 컴퓨터가 임의로 빙고 번호 선택 
process_bingo() : 선택된 숫자를 입력받아서 빙고 테이블 칸을 채움 
count_bingo() : 빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산하여 반환 
*/


int initiate_bingo();
int ptint_bingo();
int get_number_byMe();
int get_number_byCom();
int process_bingo();
int count_bingo();


int main(void){
	
	int Me[N][N]; //내 빙고 테이블 
	int Com[N][N]; //컴퓨터 빙고 테이블 
	int MeNum; //내가 선택한 숫자 
	int ComNum; //컴퓨터가 선택한 숫자 
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
