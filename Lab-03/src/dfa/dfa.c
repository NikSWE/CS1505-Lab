#include "dfa.h"
#include "../helper/my_string.h"

struct node
{
    char *label;
    char **alphabets;
    struct node **ptr_alphabets;
};

void dfa_machine(FILE *fp, int alphabets, int states)
{
    printf("Creating DFA Machine\n");

    char **contents = split_string(read_line(fp));

    // array of nodes
    struct node **node_list = (struct node **)malloc(sizeof(struct node *) * states);

    // initialize all the node with labels
    for (int i = 0, j = 3; i < states; i++, j++)
    {
        node_list[i] = (struct node *)malloc(sizeof(struct node));
        node_list[i]->label = (char *)malloc(sizeof(char) * strlen(contents[j]));
        strcpy(node_list[i]->label, contents[j]);
    }

    for (int i = 0; i < states; i++)
    {
        contents = split_string(read_line(fp));

        node_list[i]->alphabets = (char **)malloc(sizeof(char *) * alphabets);
        node_list[i]->ptr_alphabets = (struct node **)malloc(sizeof(struct node *) * alphabets);

        for (int j = 0, k = 0; j < alphabets; j++, k += 2)
        {
            node_list[i]->alphabets[j] = (char *)malloc(sizeof(char));
            node_list[i]->alphabets[j] = contents[k];

            for (int l = 0; l < states; l++)
            {
                if (strcmp(contents[k + 1], node_list[l]->label) == 0)
                {
                    node_list[i]->ptr_alphabets[j] = node_list[l];
                    break;
                }
            }
        }
    }

    printf("Machine Created Successfully\n\n");

    // read the final states from the config file
    int final_states_count;
    fscanf(fp, "%d", &final_states_count);
    fseek(fp, 1, SEEK_CUR);

    contents = split_string(read_line(fp));

    char **final_states = contents;

    // start taking input from the user
    char input;
    struct node *init_ptr = node_list[0];

    printf("intial state => %s\n", init_ptr->label);
    while (true)
    {
        scanf(" %c", &input);

        if (input == '$')
            break;

        for (int i = 0; i < alphabets; i++)
        {
            if (*init_ptr->alphabets[i] == input)
            {
                init_ptr = init_ptr->ptr_alphabets[i];
                break;
            }
        }

        printf("current state => %s\n", init_ptr->label);
    }
    printf("final state => %s\n\n", init_ptr->label);

    // check if string is accepted or not
    bool flag = false;
    for (int i = 0; i < final_states_count; i++)
    {
        if (strcmp(final_states[i], init_ptr->label) == 0)
        {
            flag = true;
            break;
        }
    }

    if (flag)
        printf("String Accepted\n");
    else
        printf("String Not Accepted\n");
}