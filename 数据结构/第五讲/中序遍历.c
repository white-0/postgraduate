#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STACK_SIZE 100

#define ElemType int

typedef struct BTNode {
    ElemType data;
    struct BTNode *Lchild, *Rchild;
}BTNode;



//递归形式
void InorderTraverse(BTNode* T) {
    if (T == NULL) return;
    InorderTraverse(T->Lchild);
    printf("%d ", T->data);
    InorderTraverse(T->Rchild);
}

//非递归形式
void InOrderTraversal(BTNode *root) {
    
    if (root == NULL) {
        return;
    }

    BTNode* stack[MAX_STACK_SIZE];
    int top = 0;
    BTNode *node = root;
    while (node != NULL || top > 0) {
        while (node != NULL) {
            stack[top ++ ] = node;
            node = node->Lchild;
        }
        node = stack[-- top];
        printf("%d ", node->data);
        node = node->Rchild;
    }
}


int main()
{
    BTNode* T = (BTNode *)malloc(sizeof(BTNode));
    T->data = 1;
    T->Lchild = (BTNode *)malloc(sizeof(BTNode));
    T->Rchild = (BTNode *)malloc(sizeof(BTNode));
    T->Lchild->data = 2;
    T->Rchild->data = 3;
    T->Lchild->Lchild = (BTNode *)malloc(sizeof(BTNode));
    T->Lchild->Rchild = (BTNode *)malloc(sizeof(BTNode));
    T->Lchild->Lchild->data = 5;
    T->Lchild->Rchild->data = 6;
    T->Rchild->Lchild = (BTNode *)malloc(sizeof(BTNode));
    T->Rchild->Rchild = (BTNode *)malloc(sizeof(BTNode));
    T->Rchild->Lchild->data = 7;
    T->Rchild->Rchild->data = 8;
    InorderTraverse(T);
    printf("\n");
    InOrderTraversal(T);
    return 0;
}