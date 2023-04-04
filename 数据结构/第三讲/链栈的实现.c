#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *next;
}Node, *LinkStack;

Node *Init_Stack();

void DestroyStack(LinkStack SS);

int Push(LinkStack SS, ElemType e);

int Pop(LinkStack SS, ElemType *e);

int  Length(LinkStack SS);                   

void Clear(LinkStack SS);                    

int  IsEmpty(LinkStack SS);                    

// 打印链栈中全部的元素。
void PrintStack(LinkStack SS);                    

int GetTop(LinkStack SS, ElemType *e);

LinkStack Init_Stack() {
    LinkStack head = (LinkStack)malloc(sizeof(Node));
    if (head == NULL) return NULL;
    head->next = NULL;
    return head;
}

void Clear(LinkStack s) {
    if (s == NULL) return;
    LinkStack tmp1;
    LinkStack tmp2 = s->next;
    while (tmp2 != NULL) {
        tmp1 = tmp2->next;
        free(tmp2);
        tmp2 = tmp1;
    }
    s->next = NULL;
    return;
}

int Length (LinkStack s) {
    if (s == NULL) return 0;
    LinkStack node = s->next;

    int length = 0;
    while (node) {node = node->next; length ++ ;}
    return length;
}

void DestoryStack(LinkStack s) {
    Node *tmp;
    while (s != NULL) {
        tmp = s->next;
        free(s);
        s = tmp;
    }
    return;
}

void PrintStack(LinkStack s) {
    if (s == NULL) return;
    if (s->next == NULL) {printf("stack is empty."); return;}
    int k = 0;
    LinkStack node = s->next;
    while (node != NULL) {
        printf("s[%d], value = %d\n", k ++ , node->data);
        node = node->next;
    }
}

int Pop(LinkStack s, ElemType *e) {
    if (s == NULL || e == NULL) return 0;
    if (s->next == NULL) {printf("stack is empty."); return 0;}
    LinkStack node = s->next;
    memcpy(e, &node->data, sizeof(ElemType));
    s->next = node->next;
    free(node);
    return 1;
}

int GetTop(LinkStack s, ElemType *e){
    if (s == NULL || e == NULL) return 0;
    if (s->next == NULL) {printf("stack is empty."); return 0;}
    memcpy(e, &s->next->data, sizeof(ElemType));
    return 1;
}

int Push(LinkStack s, ElemType e) {
    if (s == NULL) return 0;
    LinkStack node = (LinkStack)malloc(sizeof(Node));
    if (node == NULL) return 0;

    node->data = e;

    node->next = s->next;
    s->next = node;

    return 1;
}

int main () 
{
    Node *s;       // 创建顺序栈
    s = Init_Stack(); // 初始化顺序栈
    printf("stack length is %d . \n", Length(s));
    ElemType ee;
    ee = 1; Push(s, ee);
    ee = 2; Push(s, ee);
    ee = 3; Push(s, ee);
    ee = 4; Push(s, ee);
    ee = 5; Push(s, ee);
    ee = 6; Push(s, ee);
    ee = 7; Push(s, ee);
    ee = 8; Push(s, ee);
    ee = 9; Push(s, ee);
    ee = 10; Push(s, ee);
    printf("stack length is %d . \n", Length(s));

    if (GetTop(s, &ee)) printf("top elem is %d\n", ee);
    
    PrintStack(s);

    if (Pop(s, &ee)) printf("pop elem is %d\n", ee);
    if (Pop(s, &ee)) printf("pop elem is %d\n", ee);
    if (Pop(s, &ee)) printf("pop elem is %d\n", ee);
    if (Pop(s, &ee)) printf("pop elem is %d\n", ee);
    if (Pop(s, &ee)) printf("pop elem is %d\n", ee);
    if (Pop(s, &ee)) printf("pop elem is %d\n", ee);
    if (Pop(s, &ee)) printf("pop elem is %d\n", ee);
    if (Pop(s, &ee)) printf("pop elem is %d\n", ee);
    return 0;
}