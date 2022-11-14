#include <stdio.h>
#include <stdlib.h>

#include "../inc/list_funcs.h"
#include "../inc/my_types.h"
#include "../inc/my_err.h"


int read_watch(FILE *f, char *model, int *price)
{
    int ch;
    int i = 0;


    while ((ch = fgetc(f)) != '\n' && i < MAX_MODEL_LEN)
        model[i++] = ch;

    if (ch != '\n')
        return ERR_READING;

    if (model[0] == '\0')
        return ERR_READING;
    
    if (fscanf(f, "%d\n", price) != 1)
        return ERR_READING;
    else if (*price <= 0)
        return ERR_READING;

    return SUCCESS;
}


int get_list(FILE *f, node_t **top)
{
    while (feof(f) == 0)
    {
        watch_t *new_watch = calloc(1, sizeof(watch_t));
        if (!new_watch)
            return ERR_ALLOC;


        if (read_watch(f, new_watch->model, &(new_watch->price)))
        {
            free(new_watch);
            return ERR_READING;
        }

        node_t *new_node = calloc(1, sizeof(node_t));
        if (!new_node)
        {
            free(new_watch);
            return ERR_ALLOC;
        }

        new_node->data = new_watch;
        new_node->next = NULL;

        *top = list_add_end(*top, new_node);
    }

    return SUCCESS;
}


void write_watches(FILE *f, node_t *top)
{
    node_t *cur = top;


    for (; cur; cur = cur->next)
        fprintf(f, "%s\n%d\n",
        ((watch_t *) cur->data)->model,
        ((watch_t *) cur->data)->price);
}