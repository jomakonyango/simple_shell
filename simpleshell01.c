#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256
#define MAX_ARGS 16
/**
* execute_command -function takes this
* array of arguments and executes the command
* @argv: The command to execute and its arguments
*
* Return: Always 0 (Success)
*/
void execute_command(char *argv[])
{
pid_t pid;
int status;

pid = fork();
if (pid < 0)
{
perror("fork error");
}
else if (pid == 0)
{
if (execvp(argv[0], argv) < 0)
{
fprintf(stderr, "%s: command not found\n", argv[0]);
exit(1);
}
}
else
{
if (wait(&status) < 0)
{
perror("wait error");
}
}
}
/**
* read_command :function takes the user’s input
* and tokenizes it into an array of arguments
* @cmd: The command to tokenize
* @argv: The array to store the tokenized
* command and its arguments
*
*Return - Always return (0) on success.
*/

void read_command(char *cmd, char *argv[])
{
char *token;
int i;

cmd[strcspn(cmd, "\n")] = '\0';

token = strtok(cmd, " ");
for (i = 0; i < MAX_ARGS - 1 && token != NULL; i++)
{
argv[i] = token;
token = strtok(NULL, " ");
}

argv[i] = NULL;
}

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
char cmd[MAX_CMD_LEN];
char *argv[MAX_ARGS];

while (1)
{
printf("simple_shell> ");
if (fgets(cmd, sizeof(cmd), stdin) == NULL)
{
printf("\n");
exit(0);
}

read_command(cmd, argv);
execute_command(argv);
}

return (0);
}
