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
        Queue[++rear] = node; //缁撶偣鍏ラ槦
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

// 1、leaf count 求二叉树中叶子的个数
void CountLeaf(BTNode* T, int* count) {
    if(T != NULL && T->Lchild == NULL && T->Rchild == NULL){
        *count = *count + 1 ;
    }
    if (T) {
        CountLeaf(T->Lchild, count);
        CountLeaf(T->Rchild, count);
    }
}

// 2、tree height 求二叉树的高度
int treeDepth(BTNode* T) {
    if (T == NULL) return 0;
    
    int hl = treeDepth(T->Lchild);
    int hr = treeDepth(T->Rchild);

    return (hl > hr) ? (hl + 1) : (hr + 1);
}

// 3、tree width 求二叉树的宽度
int treeWidth(BTNode* root) {
    if(root == NULL) return 0;
    BTNode* p = NULL;
    BTNode* queue[MAX_QUEUE_SIZE];
    int rear = 0;
    int front = 0;
    int width = 0;
    int maxWidth = 0;
    queue[ ++ rear] = root;
    while (front < rear) {
        width = (rear - front);
        if (maxWidth < width) maxWidth = width;
        int i;
        for (i = 0; i < width; i ++ ){
            p = queue[ ++ front];
            if (p->Lchild) queue[ ++ rear] = p->Lchild;
            if (p->Rchild) queue[ ++ rear] = p->Rchild;
        }
    }
    return maxWidth;
}

// 4、swap left and right 交换二叉的左右子树
// （1）di
void Swap1(BTNode* root) {
    if (root == NULL) return;
    BTNode* temp = root->Lchild;
    root->Lchild = root->Rchild;
    root->Rchild = temp;
    Swap1(root->Lchild);
    Swap1(root->Rchild);
}

//  （2）fei di 
void swap(BTNode* root){      //root是根节点
	BTNode *queue[100], *temp, *root1;
	int first = 0, last = 0;
	queue[first++] = root;
	while(first != last){
		root1 = queue[++last];
		temp = root1->Lchild;
		root1->Lchild = root1->Rchild;
		root1->Rchild = temp;
		if(root1->Lchild != NULL)
			queue[first++] = root1->Lchild;
		if(root1->Rchild != NULL)
			queue[first++] = root1->Rchild;
	}
}

// 5、二叉树的最小深度
int minDepth(BTNode* root) {
    if(root == NULL)
        return 0;
    int heightOfLeft = minDepth (root->Lchild);
    int heightOfRight = minDepth (root->Rchild);
    return heightOfLeft > heightOfRight ? heightOfRight + 1 : heightOfLeft + 1;
}

// 6、对称树
int isMirror(BTNode* t1, BTNode* t2) {
        if (t1 == NULL && t2 == NULL)  return 1;
        if (t1 == NULL || t2 == NULL)  return 0;
        if (t1->data != t2->data) return 0;
        else 
            return t1->data == t2->data
                    &&  isMirror(t1->Rchild, t1->Lchild)
                    &&  isMirror(t2->Lchild, t2->Rchild);
}
int isSymmetric(BTNode* root) {
        return isMirror(root,root);
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

    BTNode* T1 = (BTNode *)malloc(sizeof(BTNode));
    T1->data = 1;
    T1->Lchild = (BTNode *)malloc(sizeof(BTNode));
    T1->Rchild = (BTNode *)malloc(sizeof(BTNode));
    T1->Lchild->data = 2;
    T1->Rchild->data = 2;
    
    // int count  = 0;
    // CountLeaf(T, &count);
    // printf("%d", count);

    // int high = treeDepth(T);
    // printf("%d", high);
    // printf("\n");
    
    // int maxWidth = treeWidth(T);
    // printf("%d", maxWidth);
    // printf("\n");
    
    // LevelOrderTraversal(T);
    // Swap1(T);
    // printf("\n");
    // LevelOrderTraversal(T);
    // swap(T);
    // printf("\n");
    // LevelOrderTraversal(T);
    // printf("\n");

    // int res = minDepth(T);
    // printf("%d", res);
    // printf("\n");

    int res = isSymmetric(T1);
    printf("%d", res);
    printf("\n");

    return 0;
}