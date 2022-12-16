#include <stdio.h>

#include "my_types.h"
#include "my_err.h"
#include "my_msgs.h"
#include "my_def.h"


int get_in_elem(FILE *f, char *elem)
{
    char buf;


    if (fscanf(f, "%c%c", elem, &buf) != 2)
        return ERR_READING;
    if (buf != '\n')
        return ERR_READING;

    return SUCCESS;
}


void clear_buf(FILE *f)
{
    char buf = '\0';

    
    while (buf != '\n')
        buf = fgetc(f);
}


void draw_line(int len)
{
    for (int i = 0; i < len; ++i)
        printf("-");

    printf("\n");
}


void print_list_info(node_t *root_node)
{
    for (node_t *cur = root_node; cur; cur = cur->next_node)
    {
        draw_line(TABLE_WIDTH);

        printf(NODE_INFO_MSG, BLUE, PURPLE, VALUE_WIDTH, cur->value, 
        RESET, BLUE, RED, POINTER_WIDTH, (void *) cur, RESET, GREEN, PURPLE, VALUE_WIDTH - 10,
        (cur->prev_node) ? cur->prev_node->value : ' ', RESET, GREEN, RED, POINTER_WIDTH, 
        (void *) cur->prev_node, RESET, GREEN, PURPLE, VALUE_WIDTH - 10,
        (cur->next_node) ? cur->next_node->value : ' ', RESET, GREEN, RED, POINTER_WIDTH, 
        (void *) cur->next_node, RESET);

        draw_line(TABLE_WIDTH);
        printf("\n");
    }
}
