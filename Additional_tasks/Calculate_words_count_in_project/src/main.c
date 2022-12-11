/**
 * @file main.c
 * @author Stepan Postnov
 * @brief                        
 * 
 * Программа подсчета количества слов в проекте
 * 
 * @version 0.1
 * @date 2022-12-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include <stdio.h>

#include "my_def.h"
#include "my_err.h"
#include "tools.h"
#include "in_out.h"


int main(void)
{
    get_all_filenames_in_cur_folder(OUT_FILENAME, CUR_PROJECT_FOLDER, 2,
        "h", "c");

    print_words_count(OUT_FILENAME, SEPS);

    return SUCCESS;
}
