#ifndef ___MY_TYPES___
#define ___MY_TYPES___

typedef struct
{
    char *title;
    char *name;
    int year;
} movie_t;

typedef struct
{
    int len;
    int step;
    int allocated;
    movie_t **movies;
}movies_t;


#endif // ___MY_TYPES___