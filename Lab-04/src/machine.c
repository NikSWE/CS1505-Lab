#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <string.h>

#include "types/type_3.h"
#include "helper/my_string.h"

int main()
{
    FILE *fp;

    fp = fopen("input.txt", "r");

    if (fp == NULL)
        exit(EXIT_FAILURE);

    char *terminal = read_line(fp);
    char *non_terminal = read_line(fp);

    int rules = atoi(read_line(fp));

    char *rules_array[rules];

    for (int i = 0; i < rules; i++)
        rules_array[i] = read_line(fp);

    int grammer_type;

    if (is_type_3(terminal, non_terminal, rules_array, rules))
        grammer_type = 3;

    fclose(fp);
    return EXIT_SUCCESS;
}