#ifndef ___MY_TYPES___
#define ___MY_TYPES___

#include "my_def.h"


typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

typedef struct 
{
    char model[MAX_MODEL_LEN + 1];
    int price;
} watch_t;


#endif // ___MY_TYPES___