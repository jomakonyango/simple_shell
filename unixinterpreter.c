#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CMD_LEN 128
#define HISTORY_COUNT 20

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
*/
int main(void)
{
char cmd[MAX_CMD_LEN];

while (1)
{
printf("#cisfun$ ");
if (fgets(cmd, sizeof(cmd), stdin) == NULL)
{
printf("\n");
exit(0);
}

system(cmd);
}

return (0);
}
