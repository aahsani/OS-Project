#include "types.h"
#include "user.h"

int main(void)
{
	printf(1,"Parent pid is %d and child pid is %d\n", getppid(),getpid());
	exit();
}
