/**
 * @file main.c
 * @author Stepan Postnov
 * @brief 
 * @version 0.1
 * @date 2022-12-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "my_types.h"
#include "my_msgs.h"
#include "my_def.h"
#include "my_err.h"
#include "mem.h"
#include "in_out.h"
#include "list_funcs.h"
#include "operations.h"


/**
 * @brief Main function
 * 
 * @return int 
 */
int main(void)
{
    int key = -1;

    node_t *root_node = NULL;

    
    while (key != 0)
    {
        printf(MENU_MSG);

        if (fscanf(stdin, "%d", &key) != 1 ||
        key < 0 || key > MENU_LEN)
        {
            printf(ERR_CODE_MSG, RED, RESET);
            free_list(root_node);
            return ERR_CODE;
        }

        switch (key)
        {
            case 0:
            {
                free_list(root_node);
                return SUCCESS;
            }
            case 1:
            {
                if (!root_node)
                    printf(ERR_LIST_IS_EMPTY_MSG, RED, RESET);
                else
                    print_list_info(root_node);
                break;
            }
            case 2:
            {
                clear_buf(stdin);

                char elem;


                printf(INPUT_ELEM_MSG);

                if (get_in_elem(stdin, &elem))
                {
                    printf(ERR_READING_STDIN_MSG, RED, RESET);
                    clear_buf(stdin);
                    break;
                }

                node_t *new_node = malloc(sizeof(node_t));


                new_node->next_node = NULL;
                new_node->prev_node = NULL;
                new_node->value = elem;

                root_node = list_add_end(root_node, new_node);

                printf(SUCCESSFULLY_ADD_MSG, GREEN, RESET);

                break;
            }
            case 3:
            {
                clear_buf(stdin);

                if (!root_node)
                    printf(ERR_LIST_IS_EMPTY_MSG, RED, RESET);
                else
                {
                    char del_elem;


                    printf(INPUT_DEL_VALUE_MSG);

                    if (get_in_elem(stdin, &del_elem))
                    {
                        printf(ERR_READING_STDIN_MSG, RED, RESET);
                        clear_buf(stdin);
                        break;
                    }

                    if (del_list_elem(&root_node, del_elem) == NOT_FOUND)
                        printf(ERR_ELEM_NOT_FOUND_MSG, RED, RESET);
                    else
                        printf(SUCCESSFULLY_DEL_MSG, GREEN, del_elem, RESET);
                }

                break;
            }
            case 4:
            {
                if (!root_node)
                    printf(ERR_LIST_IS_EMPTY_MSG, RED, RESET);
                else
                {
                    root_node = sort(root_node);

                    printf(SUCCESSFULLY_SORT_MSG, GREEN, RESET);
                }

                break;
            }
        }
    }
    
    return SUCCESS;
}
