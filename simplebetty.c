#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAXLINE 4096  /* Maximum length of a line */

/**
* main - a simple shell that reads a line of input and executes it
* Return: 0 on success, 1 on error
*/
int main(void)
{
char line[MAXLINE];  /* Buffer to hold the line */
FILE *fpin;  /* File pointer for the pipe */

/* Open a pipe to the shell */
fpin = popen("/bin/sh", "r")
if (fpin == NULL)
{
perror("popen error");  /* Print the error */
exit(1);  /* Exit with status 1 */
}

/* Main loop */
for (;;)
{
fputs("prompt> ", stdout);  /* Print the prompt */
fflush(stdout);  /* Flush the output buffer */
if (fgets(line, MAXLINE, fpin) == NULL)  /* Read a line from the pipe */
break;  /* If we hit EOF, break out of the loop */
if (fputs(line, stdout) == EOF)  /* Write the line to stdout */
{
perror("fputs error to pipe");  /* Print the error */
exit(1);  /* Exit with status 1 */
}
}

/* Close the pipe */
if (pclose(fpin) == -1)
{
perror("pclose error");  /* Print the error */
exit(1);  /* Exit with status 1 */
}

putchar('\n');  /* Print a newline */
exit(0);  /* Exit successfully */
}

