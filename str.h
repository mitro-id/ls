#ifndef STR_H_INCLUDED
#define STR_H_INCLUDED
#include "func.h"
#include <ctype.h>

//ожидание ENTER для действия
void enter();

//проверка на целочисленность
int is_int(const char *str);

//удаление лишних пробелов
void del_space(char *a);

#endif // STR_H_INCLUDED
