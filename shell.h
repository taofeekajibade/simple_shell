#ifndef _MAIN_H
#define _MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/stat.h>


#define MAX_INPUT 1024
#define DELIM " \n"
#define INVALID_EXIT "Invalid exit value\n"
#define OUT_OF_RANGE "Value out of range (0 - 255)\n"
#define SHELL "./hsh: 1: "
#define SHELL_ERROR "hsh"
#define SHELL_INFO "Usage: cd <directory>\n"
#define SHELL_HOME "Changed to HOME directory\n"

void shell_init(void);
void fork_process(int ac, char **argv, char **env);
void executeCommand(int ac, char **argv, char **env);
char *read_input(void);
void error_handler(const char *command);
void handle_signal(int sig);
void free_all(char **argv);
char **parse_input(char *input, char ***argv);
/*char **parse_input(char *input);*/
bool _strtest(char *argv);
bool _testcommand(const char *cmd);
char *path_to_argv(char *command);
void handle_exit(char **argv);
void handle_cd(const char *path);
int set_env(char **argv);
int unset_env(char **argv);
void print_env(char **env);
int _strlen(char *str);
char *_strcopy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(const char *str1, const char *str2);
char *get_line(void);
char *str_tok(char *str, const char *delim);
char str_dup(const char *str);


#endif
