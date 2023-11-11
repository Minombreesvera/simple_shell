#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char *my_getline() {
    static char buffer[BUFFER_SIZE];
    static int position = 0;
    static int bytesRead = 0;

    char *line = NULL;
    int i = 0;

    while (1) {
        // If the buffer is empty, read more characters
        if (position == bytesRead) {
            bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            position = 0;

            // If there are no more characters to read, break the loop
            if (bytesRead <= 0) {
                break;
            }
        }

        // Copy characters from the buffer to the line until a newline is encountered
        while (position < bytesRead && buffer[position] != '\n') {
            line = realloc(line, i + 2);  // +2 to accommodate the new character and null terminator
            line[i++] = buffer[position++];
        }

        // If a newline is encountered, add it to the line and break the loop
        if (position < bytesRead && buffer[position] == '\n') {
            line = realloc(line, i + 2);
            line[i++] = buffer[position++];
            line[i] = '\0';
            break;
        }
    }

    // If no characters were read, return NULL (end of file)
    if (line && i == 0) {
        free(line);
        line = NULL;
    }

    return line;
}

int main() {
    while (1) {
        printf("MyShell> ");
        fflush(stdout);

        char *line = my_getline();

        // If NULL is returned, it means end of file or an error occurred
        if (line == NULL) {
            break;
        }

        // Print the entered line for demonstration purposes
        printf("You entered: %s", line);

        // Free the allocated memory for the line
        free(line);
    }

    return 0;
}

