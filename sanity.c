#include "types.h"
#include "stat.h"
#include "user.h"

void myPrint(int pid){
	int j;
	for(j = 0 ; j < 10 ; j++ ){
		printf(2, "child id is %d\n", pid);
	}
	exit();
}

int main(){

	int cid[30], wt[30], rt[30];
	int i = 0;
	for( i = 0 ; i < 30 ; i++ ){
		cid[i] = fork();
		if( cid[i] < 0 ) {
			printf(1, "error\n");
			return -1;
		}
		else if( cid[i] == 0 ){//child
			int myID = getpid();
			if( myID % 3 == 0 ){ //priority = 1
				//nice();
				printf(2,"%d***********\n",nice());
				myPrint(getpid());
			}
			else if( myID % 3 == 1 ){ //priority = 0 
				nice();
				//nice();
				printf(2,"%d***********\n",nice());
				myPrint(getpid());
			}
			else {//priority = 2
				myPrint(getpid());
			}
		}
		else{//parent
			;
		}
	}

	for( i = 0 ; i < 30 ; i++ ){
		wait2( &wt[i], &rt[i] );
	}
	
	printf(1, "--------------------------\n");
	int wsum0 = 0, wsum1 = 0, wsum2 = 0;
	int tsum0 = 0, tsum1 = 0, tsum2 = 0;
	int c0 = 0, c1 = 0, c2 = 0;
	int wsumT = 0, tsumT = 0; 
	for( i = 0 ; i < 30 ; i++ ){


		printf(1, "child %d : rtime = %d, wtime = %d, turnaroundtime = %d\n", cid[i], rt[i], wt[i], (rt[i]+wt[i]));
		printf(1, "--------------------------\n");

		wsumT += wt[i];
		tsumT += rt[i] + wt[i];

		if( cid[i] % 3 == 0 ){
			wsum1 += wt[i];
			tsum1 += rt[i] + wt[i];
			c1++;
		}
		else if ( cid[i] % 3 == 1 ){
			wsum0 += wt[i];
			tsum0 += rt[i] + wt[i];
			c0++;
		}
		else {
			wsum2 += wt[i];
			tsum2 += rt[i] + wt[i];
			c2++;
		}
	}

	
//	double waverage, taverage; 
//	float fl = 12.34;
//	printf(1,"*****\n%f\n", fl);

	printf(1, "--------------------------\n");
//	waverage = ((double)tsumT/(double)30);
//	taverage = ((double)wsumT/(double)30);
	printf(1, "total averag : turnedround = %d , waittime = %d\n", tsumT/30, wsumT/30);
	printf(1, "--------------------------\n");
//	waverage = ((double)tsumT/(double)30);
//	taverage = ((double)wsumT/(double)30);
	printf(1, "priority 2 averag : turnedround = %d , waittime = %d\n", tsum2/c2, wsum2/c2);
	printf(1, "--------------------------\n");
//	waverage = ((double)tsumT/(double)30);
//	taverage = ((double)wsumT/(double)30);
	printf(1, "priority 1 averag : turnedround = %d , waittime = %d\n", tsum1/c1, wsum1/c1);
	printf(1, "--------------------------\n");
//	waverage = ((double)tsumT/(double)30);
//	taverage = ((double)wsumT/(double)30);
	printf(1, "priority 0 averag : turnedround = %d , waittime = %d\n", tsum0/c0, wsum0/c0);

	return 0;
}
