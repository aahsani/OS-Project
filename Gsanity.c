#include <time.h>
#include "types.h"
#include "stat.h"
#include "user.h"


void myPrint(int pid){
	int j;
	for(j = 0 ; j < 50 ; j++ ){
		printf(1, "process %d is printing for the %d time.\n", pid, j);
	}
}

int main(){

	printf(1, "Father pid is %d\n", getpid());
	sleep(1000); //10 seconds
	int child = fork();
	if( child < 0 ){
		printf(1, "error\n");
		return -1;
	}
	else if( child == 0 ){
		myPrint(getpid());
		exit();	
	}
	else 	myPrint(getpid());

	wait();
	return 0;
}
