#include "mealy.h"
#include "../helper/my_string.h"

struct node
{
    char *label;
    char **alphabets;
    char **outputs;
    struct node **ptr_alphabets;
};

void mealy_machine(FILE *fp, int alphabets, int states)
{
    printf("Creating Mealy Machine\n");

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
        node_list[i]->outputs = (char **)malloc(sizeof(char *) * alphabets);
        node_list[i]->ptr_alphabets = (struct node **)malloc(sizeof(struct node *) * alphabets);

        for (int j = 0, k = 0; j < alphabets; j++, k += 3)
        {
            node_list[i]->alphabets[j] = (char *)malloc(sizeof(char));
            node_list[i]->outputs[j] = (char *)malloc(sizeof(char));
            node_list[i]->alphabets[j] = contents[k];
            node_list[i]->outputs[j] = contents[k + 2];

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
                printf("output => %c\n", *init_ptr->outputs[i]);
                init_ptr = init_ptr->ptr_alphabets[i];
                break;
            }
        }

        printf("current state => %s\n", init_ptr->label);
    }
    printf("final state => %s\n", init_ptr->label);
}