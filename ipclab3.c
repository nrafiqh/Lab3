#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int fd[2], num, flag = 1;
	pipe(fd);
	pid_t pid = fork();

	if (pid == 0) {
		printf("\nEnter a number: ");
		scanf("%d", &num);
		close(fd[1]);
		write(fd[0], &flag, sizeof(flag));
	}
	else if (pid > 0){
         	wait(NULL);

	        if (num == 1)
        	   flag = 0;

	        for (int i = 2; i <= num / 2; i++)
	        {
        	   if (num % i == 0)
          	   {
               		 flag = 0;
               		 break;
           	    }
        	 }
        	 close(fd[0]);
        	 read(fd[1], &flag, sizeof(flag));

		 if (flag == 1)
       		    printf("\nIt is a prime number.\n");
      		 else if (flag == 0)
          	    printf("\nIt is not a prime number.\n");
        }

	return EXIT_SUCCESS;
}
