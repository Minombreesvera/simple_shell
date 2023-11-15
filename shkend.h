#ifndef SHKEND_H
#define SHKEND_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/resource.h>
#include <signal.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 100
#define BUFFER_SIZE 1024

char *my_getline(void);
void write_ken(char *ken);
void display_prompt();
int check_command_exists(char *command, char **envp);

#endif
