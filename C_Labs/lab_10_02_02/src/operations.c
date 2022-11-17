#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../inc/my_types.h"
#include "../inc/my_err.h"
#include "../inc/list_funcs.h"


int get_val(node_t *head, int count, int a)
{
    int p = 0;
    int degree = count - 1;


    for (node_t *cur = head; cur; cur = cur->next, --degree)
        p += cur->elem * ((int) pow(a, degree));

    return p;
}


int get_ddx(node_t *head, node_t **ddx_head, int count)
{
    int ddx_degree = count - 1;


    for (node_t *cur = head; ddx_degree > 0; --ddx_degree, cur = cur->next)
    {
        node_t *cur_node = calloc(1, sizeof(node_t));
        if (!cur_node)
            return ERR_ALLOC;

        cur_node->next = NULL;

        cur_node->elem = cur->elem * ddx_degree;

        list_add_end(ddx_head, cur_node);
    }

    return SUCCESS;
}


int get_sum(node_t *first_head, node_t *second_head, node_t **sum_head, int first_count, int second_count)
{
    for (node_t *cur_1 = first_head, *cur_2 = second_head;
    first_count && second_count;)
    {
        node_t *cur_node = calloc(1, sizeof(node_t));
        if (!cur_node)
            return ERR_ALLOC;

        cur_node->next = NULL;


        if (first_count == second_count)
        {
            cur_node->elem = cur_1->elem + cur_2->elem;

            cur_1 = cur_1->next,
            cur_2 = cur_2->next;

            --first_count,
            --second_count;
        }
        else if (first_count > second_count)
        {
            cur_node->elem = cur_1->elem;

            cur_1 = cur_1->next;

            --first_count;
        }
        else
        {
            cur_node->elem = cur_2->elem;

            cur_2 = cur_2->next;

            --second_count;
        }

        list_add_end(sum_head, cur_node);
    }

    return SUCCESS;
}


int get_dvd(node_t *head, node_t **first_head, node_t **second_head, int count)
{
    for (node_t *cur = head; cur; cur = cur->next, --count)
    {
        node_t *cur_node = calloc(1, sizeof(node_t));
        if (!cur_node)
            return ERR_ALLOC;

        cur_node->elem = cur->elem;
        cur_node->next = NULL;


        if ((count + 1) % 2)
            list_add_end(second_head, cur_node);
        else
            list_add_end(first_head, cur_node);
    }

    return SUCCESS;
}