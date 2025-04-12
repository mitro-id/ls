#include "stack_list.h"

struct list{
    size_t id;
    stack *head;
    list *next;
    list *prev;
};

list *lalloc(){
    list *ls = malloc(sizeof(list));
    if(ls == NULL){
        return NULL;
    }
    ls->head = NULL;
    ls->next = NULL;
    ls->prev = NULL;
    return ls;
}

void add_list(list *ls, stack *head, size_t id){
    if(ls == NULL || head == NULL){
        return;
    }
    if(ls->next == NULL){
        ls->id = id;
        ls->prev = ls;
        ls->next = ls;
        ls->head = head;
    }
    else{
        list *elem = lalloc();
        elem->id = id;
        elem->head = head;
        elem->next = ls;
        elem->prev = ls->prev;
        ls->prev->next = elem;
        ls->prev = elem;
    }
}

stack *elem(list *ls){
    return ls->head;
}

void ot(list *ls, size_t id){
    if(ls == NULL){
        return;
    }
    list *s = access(ls, id, ls);
    if(s == NULL){
        return;
    }
    output(s->head);
}

void loutput(list *ls){
    if(ls == NULL || ls->prev == NULL){
        return;
    }
    list *e = ls;
    do{
        printf("%d ", (int)e->id);
        e = e->next;
    }while(e != ls);
    printf("\n");
}

void lclean(list *ls){
    if(ls == NULL){
        return;
    }
    if(ls->next == NULL){
        free(ls);
        return;
    }
    if(ls->next == ls){
        clean(ls->head);
        free(ls);
        return;
    }
    list *e = ls;
    while(e->next != ls){
        clean(e->head);
        e = e->next;
        free(e->prev);
    }
    clean(e->head);
    free(e);
}

list *access(list *ls, size_t id, list *st){
    if(ls == NULL){
        return NULL;
    }
    if(ls->id == id){
        return ls;
    }
    if(ls->next == st){
        return NULL;
    }
    return access(ls->next, id, st);

}

list *del_list(list *ls){
    if(ls == NULL || ls->next == NULL){
        return ls;
    }
    if(ls->next == ls){
        lclean(ls);
        return lalloc();
    }
    list *e1 = ls->next;
    list *e2 = ls->prev;
    e1->prev = e2;
    e2->next = e1;
    clean(ls->head);
    free(ls);
    return e2;
}

stack *add_stack(){
    char *buffer = malloc(max_len_string), *end;
    int state = 10;
    double num;
    stack *head = alloc();
    printf("Working on a linked list\n");
    while(state != 6){
        printf("Stack items:\n");
        output(head);
        printf("Select action\n1)Del element\n2)Next element\n3)Previous element\n4)Add element to the right\n5)Add element to the left\n6)Exit\n");
        fgets(buffer, max_len_string, stdin);
        del_space(buffer);
        system("cls");
        if(is_int(buffer) == 0){
            state = atoi(buffer);
            if(state == 1){
                head = del_elem(head);
                system("cls");
            }
            else if(state == 2){
                head = next_elem(head);
                system("cls");
            }
            else if(state == 3){
                head = prev_elem(head);
                system("cls");
            }
            else if(state == 4){
                printf("Enter num\n");
                fgets(buffer, max_len_string, stdin);
                del_space(buffer);
                num = strtod(buffer, &end);
                add_elem_next(head, num);
                system("cls");
            }
            else if(state == 5){
                printf("Enter num\n");
                fgets(buffer, max_len_string, stdin);
                del_space(buffer);
                num = strtod(buffer, &end);
                add_elem_prev(head, num);
                system("cls");
            }
            else if(state == 6){
                printf("The stack is ready\n");
            }
            else{
                printf("Incorrect value\n");
                enter();
                system("cls");
            }
        }
        else{
            printf("Invalid input\n");
            enter();
            system("cls");
        }
    }
    free(buffer);
    return head;
}
