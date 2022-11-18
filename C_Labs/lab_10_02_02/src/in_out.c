#include <stdio.h>
#include <stdlib.h>

#include "../inc/my_def.h"
#include "../inc/my_err.h"
#include "../inc/my_types.h"
#include "../inc/list_funcs.h"


int get_type(FILE *f, char *type)
{
    char buf;


    for (int i = 0; i < OPERATION_TYPE_LEN; ++i)
    {
        type[i] = fgetc(f);

        if (type[i] == '\n')
            return ERR_READING;
    }

    buf = fgetc(f);

    if (buf != '\n')
        return ERR_READING;
    
    return SUCCESS;
}


int read_pol(FILE *f, int *count, node_t **head)
{
    char buf;


    if (fscanf(f, "%d", count) != 1 ||
        *count < 1)
        return ERR_READING;
    
    for (int i = 0; i < *count; ++i)
    {
        node_t *cur_node = calloc(1, sizeof(node_t));
        if (!cur_node)
            return ERR_ALLOC;

        cur_node->next = NULL;


        if (fscanf(f, "%d", &(cur_node->elem)) != 1)
        {
            free(cur_node);
            return ERR_READING;
        }

        list_add_end(head, cur_node);
    }

    if ((buf = fgetc(f)) != '\n')
        return ERR_READING;

    return SUCCESS;
}


int read_val(FILE *f, int *count, node_t **head, int *a)
{
    char buf;

    
    if (read_pol(f, count, head))
        return ERR_READING;

    if (fscanf(f, "%d", a) != 1 || (buf = fgetc(f)) != '\n')
        return ERR_READING;

    return SUCCESS;
}


void print_pol(node_t *head)
{
    for (node_t *cur = head; cur; cur = cur->next)
        printf("%d ", cur->elem);
    
    printf("L\n");
}