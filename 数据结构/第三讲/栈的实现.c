#include "stack.h"

void Init_Stack(SqStack s) {
    Clear(s);
}

void Clear(SqStack s) {
    if (s == NULL) return ; // 检查空指针
    s->top = 0;             // 栈顶指针为0
    memset(s->stack_array, 0 , sizeof(ElemType)*STACK_INIT_SIZE); // 数组元素清0
}

int IsFull(SqStack s) {
    if (s == NULL) return 0; // 检查空指针
    if (s->top >= STACK_INIT_SIZE - 1) return 1;
    return 0;
}

int Push(SqStack s, ElemType e) {
    if (s == NULL) return 0; // 检查空指针
    if (IsFull(s)) {
        printf("stack is full, can't push\n");
        return 0;
    }
    s->stack_array[s->top] = e;
    s->top ++ ;
    return 1;
}

int Pop(SqStack s, ElemType *ee) {
    if (s == NULL || ee == NULL) return 0; //检查空指针
    if (s->top == 0) {printf("stack is empty.\n"); return 0;}
    s->top -- ;
    memcpy(ee,&s->stack_array[s->top],sizeof(ElemType));
    return 1;
}

int isEmpty(SqStack s) {
    return s->top == 0 ? 1 : 0;
}

int GetTop(SqStack s, ElemType *ee) {
    if (s == NULL || ee == NULL) return 0; // 检查空指针
    if (isEmpty(s)) {printf("stack is empty.\n") ; return 0;}
    ee = &s->stack_array[s->top - 1];
    return 1;
}

void PrintStack(SqStack s) {
    if (s == NULL) return ; // 检查空指针
    if (s->top == 0) {printf("stack is empty.\n") ; return;}
    int k;
    for (k = 0; k < s->top; k ++ ) {
        printf("s[%d], value = %d\n", k, s->stack_array[k]);
    }
}

int Length(SqStack s) {
    if (s == NULL) return 0;
    return s->top; 
}
 void DestoryStack(SqStack s) {
     Clear(s);
     return;
 }