#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 1   // 栈初始数组大小
#define STACKINCREMENT 10 // 存储空间分配增量
#define ElemType int

typedef struct sqstack{
    ElemType *bottom;
    ElemType *top;

    int stackSize;
}SqStack;

SqStack* Init_Stack() {
    SqStack* s = (SqStack *)malloc(sizeof(SqStack));
    s->bottom = (ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if (s->bottom == NULL) {return 0;}  // 内存分配失败
    s->top = s->bottom;     // 栈空时，栈顶和栈底指针相同
    s->stackSize = STACK_INIT_SIZE; // 栈的初始容量
    return s;   // 空栈构造成功
}

int Stack_Empty(SqStack *s) {
    if (s->top == s->bottom) return 1; // 栈空
    else return 0;
}

int Stack_Clear(SqStack *s) {
    s->top == s->bottom;
    return 1;
}

int Get_Top(SqStack *s) {
    if (s->top == s->bottom) return 0; // 栈空
    ElemType e = *(s->top - 1); // 栈非空，将栈顶元素送往e单元保存，栈s保持不变
    return e;
}

int push(SqStack *s, ElemType e) {
    if (s->top - s->bottom >= s->stackSize) { // 若栈满，则追加存储空间
        s->bottom = (ElemType *)realloc(s->bottom, (s->stackSize + STACKINCREMENT)*sizeof(ElemType));
        if(!s->bottom) return 0; // 存储分配失败
        s->top = s->bottom + s->stackSize; // 栈顶指针的新值
        s->stackSize += STACKINCREMENT; // 
    }
    *s->top = e; // 将新元素e插入栈顶指针指示的位置，然后修改栈顶指针；
    s->top ++ ;
    return 1;
    
}

int pop(SqStack* s) {
    if (s->top == s->bottom) return 0; // 若栈空返回删除失败标志
    s->top -- ;
    ElemType e = *s->top;
    return e;
}

int main()
{
    SqStack* stk;
    stk = Init_Stack();
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);
    push(stk, 4);

    ElemType e;
    e = pop(stk);
    printf("%d\n", e);

    return 0;
}