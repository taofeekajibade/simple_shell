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
#include <errno.h>


#define BUFFER_SIZE 64
#define DELIMITER " \n"

void fork_process(int ac, char **argv, char **env);
void executeCommand(int ac, char **argv, char **env);
void error_handler(const char *command);
void p_error(const char *command);
void signal_c(int sig);
char *get_line(void);
void free_all(char **argv);
char **parse_command(char *user_line);
char *read_line(void);
char *path_to_argv(char *command);
void handle_exit(char **argv);
void handle_cd(const char *path);
int set_env(char **argv);
int unset_env(char **argv);
void print_env(char **env);
int str_len(char *str);
char *str_cpy(char *dest, char *src);
char *str_cat(char *dest, char *src);
int str_cmp(const char *str1, const char *str2);
char *str_tok(char *str, const char *delim);
char str_dup(const char *str);


#endif
