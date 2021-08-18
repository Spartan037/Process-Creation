#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	int child_b;
	int child_c;
	int child_d;
	int child_e;
	child_b=fork();
	if(child_b<0)
	{
		printf("Error:fork failed\n");
		exit(1);
	}
	else if(child_b==0)
	{
		printf("In child B process\n");
		printf("Child id: %u\n",getpid());
		printf("Parent id: %u\n",getppid());
		child_d=fork();
		if(child_d<0)
		{
			printf("Error:fork failed");
			exit(1);
		}
		else if(child_d==0)
		{
			printf("In child D process space:\n");
			printf("Child id: %u\n",getpid());
			printf("Parent id: %u\n",getppid());
		}
		else
		{
			child_e=fork();
			if(child_e<0)
			{
				printf("Error:fork failed");
				exit(0);
			}
			else if(child_e==0)
			{
				printf("In child E process space:\n");
				printf("Child id: %u\n",getpid());
				printf("Parent id: %u\n",getppid());
			}
			else
			{
				printf("In parent (B) process space:\n");
				printf("Child id: %u\n",getpid());
				printf("Parent id: %u\n",getppid());
				wait(NULL);
			}
		}
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

