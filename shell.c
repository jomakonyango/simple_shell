#include "simple_shell.h"

/**
 * prompt - Display a prompt and wait for the user to type a command
 */
void prompt(void)
{
    printf("#cisfun$ ");
}

/**
 * read_line - Read the command line
 * Return: The line from stdin
 */
char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);
    return line;
}

/**
 * split_line - Split the command line into an array of arguments
 * @line: The command line
 * Return: Null-terminated array of arguments
 */
char **split_line(char *line)
{
    char **args = malloc(sizeof(char *));
    args[0] = strtok(line, "\n");
    args[1] = NULL;
    return args;
}

/**
 * execute - Execute the command
 * @args: Null-terminated array of arguments
 * Return: 1 if the shell should continue running, 0 otherwise
 */
int execute(char **args)
{
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return (1);
    if (strcmp(args[0], "exit") == 0)
        return (0);

    pid = fork();
    if (pid == 0)
    {
        /* Child process */
        if (execve(args[0], args, NULL) == -1)
            perror("./shell");
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        /* Error forking */
        perror("./shell");
    }
    else
    {
        /* Parent process */
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return (1);
}

