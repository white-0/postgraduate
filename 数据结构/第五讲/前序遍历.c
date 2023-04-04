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
void PreorderTraverse(BTNode* T) {
    if (T == NULL) return;
    printf("%d ", T->data);
    PreorderTraverse(T->Lchild);
    PreorderTraverse(T->Rchild);
}

//非递归形式
void PreOrderTraversal(BTNode *root) {
    
    if (root == NULL) {
        return;
    }

    BTNode* stack[MAX_STACK_SIZE];
    int top = 0;
    BTNode *node = root;
    while (node != NULL || top > 0) {
        while (node != NULL) {
            printf("%d ", node->data);
            stack[top ++ ] = node;
            node = node->Lchild;
        }
        node = stack[-- top];
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
    PreorderTraverse(T);
    printf("\n");
    PreOrderTraversal(T);
    return 0;
}