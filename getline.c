#include "shkend.h"
/**
 * my_getline - function
 * Return: character
 */
char *my_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int placement;
	static int bytesread;
	char *dot = NULL;
	int vera = 0;

	while (1)
	{
	/* If the buffer is empty, read more characters */
		if (placement == bytesread)
	{
		bytesread = read(STDIN_FILENO, buffer, BUFFER_SIZE)
			placement = 0;
		/* If there are no more characters to read, break the loop */
		if (bytesread <= 0)
		{
			break;
		}
	}
	/* Copy characters from the buffer to the line till a newline is seen */
		while (placement < bytesread && buffer[placement] != '\n')
	{
		dot = realloc(dot, vera + 2);
		/* +2 to accommodate the new character and null terminator */
		dot[vera++] = buffer[placement++];
	}
	/* If a newline is encountered, add it to the line and break the loop */
		if (placement < bytesread && buffer[placement] == '\n')
	{
		dot  = realloc(done, vera + 2);
		dot[vera++] = buffer[placement++];
		dot[vera] = '\0';
			break;
	}
	}
	/* If no characters were read, return NULL  EOF (end of file) */
	if (dot && vera == 0)
	{
		free(dot);
		dot = NULL;
	}
	return (dot);
}
/**
 * main - function
 * Return: 0
 */

int main(void)
{
	while (1)
	{
		printf("MyShell> ");
		fflush(stdout);

		char *dot = my_getline();

	/* If NULL is returned, it means end of file or an error occurred */
	if (dot == NULL)
	{
		break;
	}
	/* print the entered line for demonstration purposes */
	printf("You entered: %s", dot);

	/* Free the allocated memory for the line */
	free(dot);
	}
	return (0);
}
