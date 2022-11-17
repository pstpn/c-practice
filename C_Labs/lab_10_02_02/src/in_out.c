#include <stdio.h>
#include <stdlib.h>

#include "../inc/my_def.h"
#include "../inc/my_err.h"
#include "../inc/my_types.h"
#include "../inc/list_funcs.h"


int get_type(char *type)
{
    char buf;


    for (int i = 0; i < OPERATION_TYPE_LEN; ++i)
    {
        type[i] = fgetc(stdin);

        if (type[i] == '\n')
            return ERR_READING;
    }

    buf = fgetc(stdin);

    if (buf != '\n')
        return ERR_READING;
    
    return SUCCESS;
}


int read_pol(int *count, node_t **head)
{
    char buf;


    if (scanf("%d", count) != 1 ||
        *count < 1)
        return ERR_READING;
    
    for (int i = 0; i < *count; ++i)
    {
        node_t *cur_node = calloc(1, sizeof(node_t));
        if (!cur_node)
            return ERR_ALLOC;

        cur_node->next = NULL;


        if (scanf("%d", &(cur_node->elem)) != 1)
        {
            free(cur_node);
            return ERR_READING;
        }

        list_add_end(head, cur_node);
    }

    if ((buf = fgetc(stdin)) != '\n')
        return ERR_READING;

    return SUCCESS;
}


int read_val(int *count, node_t **head, int *a)
{
    char buf;

    
    if (read_pol(count, head))
        return ERR_READING;

    if (scanf("%d", a) != 1 || (buf = fgetc(stdin)) != '\n')
        return ERR_READING;

    return SUCCESS;
}


void print_pol(node_t *head)
{
    for (node_t *cur = head; cur; cur = cur->next)
        printf("%d ", cur->elem);
    
    printf("L\n");
}