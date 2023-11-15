#include "shkend.h"

/**
 *write_ken - function
 *@ken: pointer
 */
void write_ken(char *ken)
{
	write(STDOUT_FILENO, ken, strlen(ken));
}
/**
 * display_prompt- function
 */
void display_prompt(void)
{
	write_ken("$ ");
}
/**
 * execute_command - command that executes
 * @command: pointer
 * @arguments: pointer
 */
void execute_command(char *command, char **arguments)
{
	pid_t pid = fork();


	if (pid < 0)
	{
		write_ken("Fork failed\n");

	} else if (pid == 0)

	{

		/* Child process */

		execvp(command, arguments);
		write_ken("Execution failed\n");

		exit(EXIT_FAILURE);

	}
	else
	{
		/* Parent process */

	waitpid(pid, NULL, 0);
	}
}
/**
 * main - function
 * Return: 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *arguments[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();
	ssize_t read_size = read(STDIN_FILENO, command, sizeof(command));
		if (read_size < 0)
		{
			write_ken("Error reading input\n");
			exit(EXIT_FAILURE);
		}
		else if (read_size == 0)
		{
			/* Handle end of file (Ctrl+D) */
			write_ken("\nExiting the shell.\n");
				break;
		}
		/* Remove newline character from the end of the command */
		command[strcspn(command, "\n")] = 0;
		if (strlen(command) == 0)
		{
			continue;
		}
		if (strcmp(command, "exit") == 0)
		{
		break;
		}
	/* Tokenize the command line to separate command and arguments */
	int i = 0;

	arguments[i] = strtok(command, " ");
	while (arguments[i] != NULL)
	{
		i++;
		arguments[i] = strtok(NULL, " ");
	}
	execute_command(arguments[0], arguments);
	}
	return (0);
}
