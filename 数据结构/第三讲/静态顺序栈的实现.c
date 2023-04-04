#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define STACK_INIT_SIZE 100
typedef int ElemType;

typedef struct sqstack
{
    ElemType stack_array[STACK_INIT_SIZE];
    int top;
}sqstack, *SqStack;

void Init_Stack(SqStack s);
void Clear(SqStack s);
int IsFull(SqStack s);
int Push(SqStack s, ElemType e);
int Pop(SqStack s, ElemType *ee);
int isEmpty(SqStack s);
ElemType GetTop(SqStack s, ElemType *ee);
void PrintStack(SqStack s);
int Length(SqStack s);

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

ElemType GetTop(SqStack s, ElemType *ee) {
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
int main()
{
    sqstack s;       // 创建顺序栈
    Init_Stack(&s); // 初始化顺序栈
    printf("stack length is %d . \n", Length(&s));
    ElemType ee;
    ee = 1; Push(&s, ee);
    ee = 2; Push(&s, ee);
    ee = 3; Push(&s, ee);
    ee = 4; Push(&s, ee);
    ee = 5; Push(&s, ee);
    ee = 6; Push(&s, ee);
    ee = 7; Push(&s, ee);
    ee = 8; Push(&s, ee);
    ee = 9; Push(&s, ee);
    ee = 10; Push(&s, ee);
    printf("stack length is %d . \n", Length(&s));

    if (GetTop(&s, &ee)) printf("top elem is %d\n", ee);
    
    PrintStack(&s);

    if (Pop(&s, &ee)) printf("pop elem is %d\n", ee);
    if (Pop(&s, &ee)) printf("pop elem is %d\n", ee);
    if (Pop(&s, &ee)) printf("pop elem is %d\n", ee);
    if (Pop(&s, &ee)) printf("pop elem is %d\n", ee);
    if (Pop(&s, &ee)) printf("pop elem is %d\n", ee);
    if (Pop(&s, &ee)) printf("pop elem is %d\n", ee);
    if (Pop(&s, &ee)) printf("pop elem is %d\n", ee);
    if (Pop(&s, &ee)) printf("pop elem is %d\n", ee);
    return 0;
}