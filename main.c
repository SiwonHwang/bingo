#include <stdio.h>
#include <stdlib.h>

#define N
#define M 

/*
initiate_bingo() : 빙고 테이블을 초기에 만들어주는 함수 
ptint_bingo() : 빙고 테이블 현재상황을 화면에 출력 
get_number_byMe() : 내가 빙고 번호 입력 선택 
get_number_byCom() : 컴퓨터가 임의로 빙고 번호 선택 
process_bingo() : 선택된 숫자를 입력받아서 빙고 테이블 칸을 채움 
count_bingo() : 빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산하여 반환 
*/


int initiate_bingo(void){
	
	int sm[N][N];
	int sc[N][N];
	
	srand((unsigned) time(NULL));
	
	return 0;
	
}
