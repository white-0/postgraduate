#include "stack.h"

int Match_Brackets(char str[], int length) {
    int i;
    sqstack s;
    Init_Stack(&s);
    for (i = 0; i < length + 1; i ++ ){
        if (str[i] == '(' || str[i] == '['){
            Push(&s, str[i]);
        }else if(str[i] == ')'){
            char x;
            Pop(&s, &x);
            if (x != '(') {printf("match unsuccefully\n"); return 0;}
        }else if(str[i] == ']'){
            char x;
            Pop(&s, &x);
            if (x != '[') {printf("match unsuccefully\n"); return 0;}
        }
    }
    return isEmpty(&s);
}

int main ()
{
    int length;
    scanf("%d", &length);
    int i;
    char str[length + 1];
    for (int i = 0; i < length + 1; i ++ ) {
        scanf("%c", &str[i]);
    }
    for (int i = 0; i < length + 1; i ++ ) {
        printf("%c", str[i]);
    }
    printf("\n");
    if(Match_Brackets(str, length))
        printf("is matched");
    else 
        printf("is not matched");
}