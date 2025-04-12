#ifndef STACK_LIST_H_INCLUDED
#define STACK_LIST_H_INCLUDED
#include "func.h"
#include "str.h"

typedef struct list list;

list *lalloc();

void add_list(list *ls, stack *head, size_t id);

void loutput(list *ls);

void lclean(list *ls);

list *del_list(list *ls);

list *access(list *ls, size_t id, list *st);

stack *add_stack(stack *ls);

stack *elem(list *ls);

void ot(list *ls, size_t id);

#endif // STACK_LIST_H_INCLUDED
