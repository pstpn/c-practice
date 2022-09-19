/**
 * @file my_err.h
 * @author Stepan Postnov ICS7-31B
 * @brief Библиотека, содержащая коды ошибок
 * @version 0.1
 * @date 2022-09-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ___MY_ERR___
#define ___MY_ERR___

/**
 * @brief Код возврата при успешном завершении
 * 
 */
#define SUCCESS 0
/**
 * @brief Код возврата при достижении конца файла
 * 
 */
#define END_OF_FILE -1

/**
 * @brief Код возврата при некорректных аргументах командной строки
 * 
 */
#define INCORRECT_ARGS 1
/**
 * @brief Код возврата при некорректном имени файла
 * 
 */
#define INCORRECT_FILENAME 2
/**
 * @brief Код возврата при некорректной структуре
 * 
 */
#define INCORRECT_STRUCT 3
/**
 * @brief Код возврата при некорректном годе
 * 
 */
#define INCORRECT_YEAR 5
/**
 * @brief Код возврата при некорректном файле
 * 
 */
#define INCORRECT_FILE 6
/**
 * @brief Код возврата при некорректном анализируемом поле
 * 
 */
#define INCORRECT_FIELD 7

#endif // ___MY_ERR___
