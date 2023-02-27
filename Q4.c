#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
int n, i, level = 0;
FILE *fptr;
printf("Enter the value of n: ");
scanf("%d", &n);
for (i = 1; i <= n; i++) { 
    if (fork() == 0) { 
        level++;
        fptr = fopen("processes.txt", "a"); 
        fprintf(fptr, "Process ID: %d\n", getpid()); 
        fprintf(fptr, "Parent process ID: %d\n", getppid()); 
        fprintf(fptr, "Level: %d\n", level);
        fflush(fptr); 
        fclose(fptr); 
        exit(0); 
    } 
    else {
        wait(NULL);
    }
} 
return 0; 
}
