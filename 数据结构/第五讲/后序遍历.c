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
void PostorderTraverse(BTNode* T) {
    if (T == NULL) return;
    PostorderTraverse(T->Lchild);
    PostorderTraverse(T->Rchild);
    printf("%d ", T->data);
}

//非递归形式
void PostOrderTraversal(BTNode *root) {
    
    if (root == NULL) {
        return;
    }

    BTNode* stack[MAX_STACK_SIZE];
    int top = 0;
    BTNode *node = root;
    BTNode *lastVisit = root;
    while (node != NULL || top > 0) {
        while (node != NULL) {
            stack[top ++ ] = node;
            node = node->Lchild;
        }
        node = stack[top - 1];
        if (node->Rchild == NULL || node->Rchild == lastVisit){
            printf("%d ", node->data);
            -- top;
            lastVisit = node;
            node = NULL;
        }else {
            node = node->Rchild;
        }
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
    PostorderTraverse(T);
    printf("\n");
    PostOrderTraversal(T);
    return 0;
}