#include "str.h"

void enter(){
    printf("press ENTER to continue\n");
    char a = '\0';
    while(a != '\n'){
        a = getchar();
    }
    return;
}

int is_int(const char *str){
    if (*str == '-' || *str == '+') str++;
    if (!*str) return 0;
    while (*str) {
        if (!isdigit(*str)) return 1;
        str++;
    }
    return 0;
}

void del_space(char *a){
    int label = 1;
    char *i = a, *j = a;

    while(*i != '\0'){

        if(*i == '|'){
            *j++ = '\\';
        }
        else if(*i != ' ' && *i != '\t' && *i != '\n'){
            label = 0;
            *j++ = *i;
        }
        else if(*i == ' ' && label == 0){
            label = 1;
            *j++ = *i;
        }
        i++;
    }
    if(a){
        if(*a == ' '){
            a[0] = '\0';
        }

        else if(i[-1] == ' '){
            j[-1] = '\0';
        }
        else if(i[-1] != ' '){
            *j = '\0';
        }
    }
}
