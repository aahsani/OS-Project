#include "types.h"
#include "stat.h"
#include "user.h"

void myPrint(int pid){
	int j;
	for(j = 0 ; j < 100 ; j++ ){
		printf(2, "child %d prints for the %d time.\n", pid, j);
	}
	exit();
}

int main(){

	int pid[10], wt[10], rt[10];
	int i = 0;
	for( i = 0 ; i < 10 ; i++ ){
		pid[i] = fork();
		if( pid[i] < 0 ) {
			printf(1, "error\n");
			return -1;
		}
		else if( pid[i] == 0 ){
			myPrint(getpid());
		}
	}

	for( i = 0 ; i < 10 ; i++ ){
		pid[i] = wait2( &wt[i], &rt[i] );
	}

	printf(1, "--------------------------\n");
	for( i = 0 ; i < 10 ; i++ ){
		printf(1, "child %d : rtime = %d, wtime = %d, turnaroundtime = %d\n", pid[i], rt[i], wt[i], (rt[i]+wt[i]));
		printf(1, "--------------------------\n");
	}

	return 0;
}
