/*
#include "types.h"
#include "stat.h"
#include "user.h"

void myPrint(){
	int j;
	for(j = 0 ; j < 1000 ; j++ ){
		;
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
			myPrint();
		}
	}

	for( i = 0 ; i < 10 ; i++ ){
		wait2( &wt[i], &rt[i] );
	}
	return 0;
}
*/

#include "types.h"
#include "user.h"
int main (void)
{
 int ChildPid[10];
 int i,j;
 for( j = 0; j<10 ; j++){
  	ChildPid[j] = fork();
	if(ChildPid[j] == 0){
	  for( i =0 ; i<1000 ; i++);
		exit();
	}	
		
}
  for( i = 0 ; i<10 ; i++)
	wait();

	exit();
	return 0;
}
