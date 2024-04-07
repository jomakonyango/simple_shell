#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CMD_LEN 256
#define PROMPT "#cisfun$ "

/**
* execute_cmd - forks a child process to execute a command
* @cmd: the command to execute
* Return: the status of the executed command
*/
int execute_cmd(char *cmd)
{
char *argv[2];
int status;
pid_t pid;

argv[0] = cmd;
argv[1] = NULL;

pid = fork();
if (pid < 0)
{
perror("fork failed");
return (EXIT_FAILURE);
}
if (pid == 0)
{
/* Child process: execute the command */
if (execve(argv[0], argv, NULL) == -1)
{
perror(argv[0]);
}
exit(EXIT_FAILURE);
}
else
{
/* Parent process: wait for the child to finish */
wait(&status);
}

return (status);
}

/**
* main - a simple shell that reads a line of input and executes it
* Return: 0 on success, 1 on error
*/
int main(void)
{
char cmd[MAX_CMD_LEN];

/* Main loop */
while (1)
{
printf(PROMPT);
if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL)
{
printf("\n");
return (EXIT_SUCCESS);
}

/* Remove newline at the end */
cmd[strlen(cmd) - 1] = '\0';

/* Execute the command */
execute_cmd(cmd);
}

return (EXIT_SUCCESS);
}
