#ifndef ___MY_TYPES___
#define ___MY_TYPES___


typedef struct node node_t;

struct node
{
    int elem;
    node_t *next;
};

#endif // ___MY_TYPES___