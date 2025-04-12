#include "func.h"
#include "str.h"
#include "stack_list.h"

int main(){
    char *buffer = malloc(max_len_string);
    int state = 10;
    size_t id, id2;
    stack *head = alloc();
    list *ls = lalloc();
    printf("Developer AgichevDS\n");
    while(state != 5){
        printf("List items:\n");
        loutput(ls);
        printf("Select action\n1)ADD\n2)DEL\n3)COPY\n4)OUTPUT\n5)EXIT\n");
        fgets(buffer, max_len_string, stdin);
        del_space(buffer);
        system("cls");
        if(is_int(buffer) == 0){
            state = atoi(buffer);
            if(state == 1){
                clean(head);
                head = add_stack();
                printf("Enter ID\n");
                fgets(buffer, max_len_string, stdin);
                del_space(buffer);
                id = (size_t)atoi(buffer);
                add_list(ls, copy(head), id);
                system("cls");
            }
            else if(state == 2){
                printf("Enter ID\n");
                fgets(buffer, max_len_string, stdin);
                del_space(buffer);
                id = (size_t)atoi(buffer);
                if(access(ls, id, ls) != NULL){
                    ls = del_list(access(ls, id, ls));
                }
                system("cls");
            }
            else if(state == 3){
                printf("Enter ID\n");
                fgets(buffer, max_len_string, stdin);
                del_space(buffer);
                id = (size_t)atoi(buffer);
                printf("Enter new ID\n");
                fgets(buffer, max_len_string, stdin);
                del_space(buffer);
                id2 = (size_t)atoi(buffer);
                if(access(ls, id, ls) != NULL){
                    add_list(ls, copy(elem(access(ls, id, ls))), id2);
                }
                system("cls");
            }
            else if(state == 4){
                printf("Enter ID\n");
                fgets(buffer, max_len_string, stdin);
                del_space(buffer);
                id = (size_t)atoi(buffer);
                ot(ls, id);
                system("cls");
            }
            else if(state == 5){
                printf("End of work");
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
    lclean(ls);
    clean(head);
    free(buffer);
    return 0;
}
