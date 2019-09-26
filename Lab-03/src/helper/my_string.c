#include "my_string.h"

// returns pointer to the line read from the file
char *read_line(FILE *fp)
{
    char buf[SIZE];
    fscanf(fp, "%[^\n]", buf);
    return strcpy((char *)malloc(sizeof(char) * strlen(buf)), buf);
}

// returns the token count of the argument
int count_token(char *str)
{
    int token_count = 0, index = 0;
    char prev_char = ' ';
    while (true)
    {
        if ((str[index] == ' ' || str[index] == '\0') && prev_char != ' ')
            token_count++;

        prev_char = str[index];

        if (str[index] == '\0')
            break;
        else
            index++;
    }
    return token_count;
}

// returns pointer to array of strings after tokenization
char **split_string(char *str)
{
    // if empty string passed return null
    if (strlen(str) == 0)
        return NULL;

    char delim[] = " ", *ptr;
    int index = 0;
    char **arr_of_str = (char **)malloc(sizeof(char *) * count_token(str));

    ptr = strtok(str, delim);

    while (ptr != NULL)
    {
        arr_of_str[index] = (char *)malloc(sizeof(char) * strlen(ptr));
        strcpy(arr_of_str[index++], ptr);
        ptr = strtok(NULL, delim);
    }

    return arr_of_str;
}