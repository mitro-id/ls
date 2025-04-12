#include "func.h"

struct stack{
    double num;
    stack *next;
    stack *prev;
};

stack *alloc(){
    stack *head = malloc(sizeof(stack));
    if(head == NULL){
        return NULL;
    }
    head->next = NULL;
    head->prev = NULL;
    return head;
}

void add_elem_next(stack *head, double num){
    if(head == NULL){
        return;
    }
    if(head->prev == NULL){
        head->num = num;
        head->prev = head;
        head->next = head;
    }
    else{
        stack *elem = alloc();
        elem->num = num;
        elem->next = head->next;
        elem->prev = head;
        head->next->prev = elem;
        head->next = elem;
    }
}

void add_elem_prev(stack *head, double num){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        head->num = num;
        head->prev = head;
        head->next = head;
    }
    else{
        stack *elem = alloc();
        elem->num = num;
        elem->next = head;
        elem->prev = head->prev;
        head->prev->next = elem;
        head->prev = elem;
    }
}

void output(stack *head){
    if(head == NULL || head->prev == NULL){
        return;
    }
    stack *e = head;
    do{
        printf("%lf ", e->num);
        e = e->next;
    }while(e != head);
    printf("\n^HEAD\n");
}

void clean(stack *head){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        free(head);
        return;
    }
    if(head->next == head){
        free(head);
        return;
    }
    stack *e = head;
    while(e->next != head){
        e = e->next;
        free(e->prev);
    }
    free(e);
}

stack *copy(const stack *head){
    stack *new_head = alloc();
    if(head == NULL){
        return NULL;
    }
    if(head->prev == NULL){
        return new_head;
    }
    const stack *e = head;
    do{
        add_elem_next(new_head, e->num);
        e = e->next;
    }while(e != head);
    return new_head;
}

stack *del_elem(stack *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    if(head->next == head){
        clean(head);
        return alloc();
    }
    stack *e1 = head->next;
    stack *e2 = head->prev;
    e1->prev = e2;
    e2->next = e1;
    free(head);
    return e2;
}

stack *next_elem(stack *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    return head->next;
}

stack *prev_elem(stack *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    return head->prev;
}
