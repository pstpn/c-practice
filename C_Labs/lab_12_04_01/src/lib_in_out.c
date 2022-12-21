#include <stdio.h>


void array_filling(FILE *f, int *pcur, int *pend)
{
    while (pcur != pend)
        fscanf(f, "%d", pcur++);
}


void writing_to_file(FILE *f, int *pcur, int *pend)
{
    while (pcur != pend)
        fprintf(f, "%d ", *(pcur++));
}