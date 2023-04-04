#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_QUEUE_SIZE 100

#define ElemType int

typedef struct BTNode {
    ElemType data;
    struct BTNode *Lchild, *Rchild;
}BTNode;

void LevelOrderTraversal(BTNode *root) {
    
    if (root == NULL) {
        return;
    }

    BTNode* Queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;
    BTNode *node = root;
    if (node != NULL) {
        Queue[++rear] = node; //结点入队
        while(front < rear) {
            node = Queue[++front];
            printf("%d ", node->data);
            if (node->Lchild != NULL) {
                Queue[++rear] = node->Lchild;
            }
            if (node->Rchild != NULL) {
                Queue[++rear] = node->Rchild;
            }
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
    LevelOrderTraversal(T);
    printf("\n");
    return 0;
}
