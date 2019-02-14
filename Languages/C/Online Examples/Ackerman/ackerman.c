#include <stdio.h>

int ackerman(int m, int n) {
	int answer;
	if(m == 0) 	answer = n+1;
	else if(n == 0)	answer = ackerman(m-1, 1);
	else 		answer = ackerman(m-1, ackerman(m, n-1));
	return answer;
}

int main(int argc, char *argv[]) {
	int max_i = 6, max_j = 6;
	for(int i = 0; i < max_i; i++) {
		for(int j = 0; j < max_j; j++) {
			printf("ackerman(%d,%d) = %d\n", i, j, ackerman(i, j));
		}
	}
	
	return 0;
}
