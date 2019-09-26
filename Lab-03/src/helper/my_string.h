#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

char *read_line(FILE *);
char **split_string(char *);
int count_token(char *);

#endif