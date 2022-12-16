#ifndef ___MY_TYPES___
#define ___MY_TYPES___


typedef struct node
{
    char value;

    struct node *prev_node;
    struct node *next_node;
} node_t;


#endif // ___MY_TYPES___