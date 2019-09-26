#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "dfa/dfa.h"
#include "mealy/mealy.h"
#include "helper/my_string.h"

int main()
{
    FILE *fp = fopen("config.txt", "r");

    // exit if file not found
    if (fp == NULL)
    {
        printf("Config File Not Found\n");
        exit(EXIT_FAILURE);
    }

    char **contents = split_string(read_line(fp));

    // type = 0, machine = dfa
    // type = 1, machine = mealy

    int type = atoi(contents[0]);
    int alphabets = atoi(contents[1]);
    int states = atoi(contents[2]);

    // file pointer at the beginning of the file
    fseek(fp, 0, SEEK_SET);

    switch (type)
    {
    case 0:
        dfa_machine(fp, alphabets, states);
        break;
    case 1:
        mealy_machine(fp, alphabets, states);
        break;
    default:
        printf("Machine Not Supported\n");
        break;
    }

    return EXIT_SUCCESS;
}