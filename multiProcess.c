#include  <stdio.h>
#include  <string.h>
#include <stdlib.h>
#include  <sys/types.h>
#include <time.h>
#include <unistd.h> 
#include <sys/wait.h>
int  main(void)
{
	pid_t  pid;
	time_t timer;
	char buffer[26];
	char c;
	FILE* f;
	struct tm* time_info;
	for (int i = 0; i < 10; ++i)
		{
			pid = fork();
			if (pid == 0) {
				c = getchar();
				printf("%c\n",c);
				time(&timer);
				time_info = localtime(&timer);
				f = fopen("multiProcess.log","a");
				strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", time_info);
				fprintf(f, "[%s] : %c\n",buffer, c);
				//printf("Ket thuc mot process con\n");
				fclose(f);
				exit(0);
			}
		}
    for(int i=0;i<10;i++){ // loop will run n times (n=5) 
    	wait(NULL);   
	}
	return 0;
}