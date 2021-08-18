#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	int child_b;
	int child_c;
	child_b=fork();
	if(child_b<0)
	{
		printf("Error:fork failed");
		exit(1);
	}
	else if(child_b==0)
	{
		printf("In child B process space:\n");
		printf("Child id: %u\n",getpid());
		printf("Parent id: %u\n",getppid());
	}
	else
	{
		child_c=fork();
		if(child_c<0)
		{
			printf("Error:fork failed");
			exit(0);
		}
		else if(child_c==0)
		{
			printf("In child C process space:\n");
			printf("Child id: %u\n",getpid());
			printf("Parent id: %u\n",getppid());
		}
		else
		{
			printf("In parent(A) process space:\n");
			printf("Child id: %u\n",getpid());
			printf("Parent id: %u\n",getppid());
			wait(NULL);
		}
	}
}

