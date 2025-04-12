#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define max_len_string 100

typedef struct stack stack;

stack *alloc();

void add_elem_next(stack *head, double num);

void add_elem_prev(stack *head, double num);

void output(stack *head);

void clean(stack *head);

stack *copy(const stack *head);

stack *del_elem(stack *head);

stack *next_elem(stack *head);

stack *prev_elem(stack *head);


#endif // FUNC_H_INCLUDED
