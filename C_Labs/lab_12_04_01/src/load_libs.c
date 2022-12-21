#include <dlfcn.h>
#include <stdio.h>


void *load_func(void *cur_lib, const char *lib_name, const char *func_name)
{
    if (!cur_lib)
        cur_lib = dlopen(lib_name, RTLD_NOW);
    if (!cur_lib)
        return NULL;


    void *cur_func = dlsym(cur_lib, func_name);
    if (!cur_func)
    {
        dlclose(cur_lib);
        return NULL;
    }

    return cur_func;
}