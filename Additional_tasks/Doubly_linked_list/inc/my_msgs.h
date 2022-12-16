#ifndef ___MY_MSGS___
#define ___MY_MSGS___


#define INPUT_ELEM_MSG "\nВведите значение, которое Вы хотите добавить в список (один символ): "
#define INPUT_DEL_VALUE_MSG "\nВведите значение узла, который Вы хотите удалить (один символ): "
#define DEL_ELEM_MSG "\n%sЭлемент успешно удален!%s\n"
#define SUCCESSFULLY_DEL_MSG "\n%sЭлемент успешно удален! Удаленный элемент: \"%c\"%s\n"
#define SUCCESSFULLY_SORT_MSG "\n%sСписок успешно отсортирован!%s\n"
#define NODE_INFO_MSG "\
|%sVALUE: %s%*c     %s|%s ADDRESS: %s%*p%s|\
\n--------------------------------------------------------\
\n|%sPREV NODE VALUE: %s%*c     %s| %sADDRESS: %s%*p%s|\
\n|%sNEXT NODE VALUE: %s%*c     %s| %sADDRESS: %s%*p%s|\n"
#define SUCCESSFULLY_ADD_MSG "\n%sДобавление элемента произведено успешно%s\n"
#define ERR_ALLOC_MSG "\n%sНе удалось выделить память. Попробуйте снова.%s\n\n"
#define ERR_CODE_MSG "\n%sНекорректный код. Попробуйте снова.%s\n\n"
#define ERR_READING_STDIN_MSG "\n%sНе удалось получить элемент. Попробуйте снова.%s\n\n"
#define ERR_LIST_IS_EMPTY_MSG "\n%sСписок пуст. Сначала добавьте элементы в него и попробуйте снова.%s\n\n"
#define ERR_ELEM_NOT_FOUND_MSG "\n%sУзел с таким значением для удаления не найден. Попробуйте снова!%s\n"
#define MENU_MSG  "\n\
1  --  Вывести список\n\
2  --  Добавить узел в список\n\
3  --  Удалить узел списка\n\
4  --  Отсортировать список\n\
0  --  Выход\n: "

#endif // ___MY_MSGS___
