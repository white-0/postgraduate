#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define ElemType int
#define  KeyType int
/* 二叉排序树的节点结构定义 */
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//二叉排序树查找算法(递归写法)
BiTree BST_Search_D(BiTNode *T, ElemType key) {
	if(T == NULL) return NULL;
	else{
		if(T->data == key) return T;
		else if (key < T->data)
			return BST_Search_D(T->lchild, key);
		else
			return BST_Search_D(T->rchild, key);
	}
}

BiTree BST_Search_F(BiTNode *T , ElemType key){
	BiTree p = T ;
	while (p != NULL &&  p->data != key ) {
		if (p->data > key)  
			p = p->lchild ;
		else 
			p = p->lchild ;
	}
	if (p->data == key )    
		return(p) ;
	else 
		return(NULL) ;
 }

//二叉排序树查找算法
int SearchBST(BiTree T, KeyType key, BiTree f, BiTree *p) {
    //如果 T 指针为空，说明查找失败，令 p 指针指向查找过程中最后一个叶子结点，并返回查找失败的信息
    if (!T) {
        *p = f;
        return FALSE;
    }
    //如果相等，令 p 指针指向该关键字，并返回查找成功信息
    else if (key == T->data) {
        *p = T;
        return TRUE;
    }
    //如果 key 值比 T 根结点的值小，则查找其左子树；反之，查找其右子树
    else if (key < T->data) {
        return SearchBST(T->lchild, key, T, p);
    }
    else {
        return SearchBST(T->rchild, key, T, p);
    }
}



int InsertBST(BiTree *T, ElemType e) {
	BiTree p = NULL;
	//如果查找不成功，需做插入操作
	if (!SearchBST((*T), e, NULL, &p)) {
//	if (BST_Search_F(*T, e) == NULL) {
		//初始化插入结点
		BiTree s = (BiTree)malloc(sizeof(BiTNode));
		s->data = e;
		s->lchild = s->rchild = NULL;
		//如果 p 为NULL，说明该二叉排序树为空树，此时插入的结点为整棵树的根结点
		if (!p) {
			*T = s;
		}
		//如果 p 不为 NULL，则 p 指向的为查找失败的最后一个叶子结点，只需要通过比较 p 和 e 的值确定 s 到底是 p 的左孩子还是右孩子
		else if (e < p->data) {
			p->lchild = s;
		}
		else {
			p->rchild = s;
		}
		return 1;
	}
	//如果查找成功，不需要做插入操作，插入失败
	return 0;
}


void order(BiTree t)//中序输出
{
    if (t == NULL) {
        return;
    }
    order(t->lchild);
    printf("%d ", t->data);
    order(t->rchild);
}
int main()
{
    int i;
    int a[5] = { 3,4,2,5,9 };
    BiTree T = NULL;
    for (i = 0; i < 5; i++) {
        InsertBST(&T, a[i]);
    }
    printf("中序遍历二叉排序树：\n");
    order(T);
    printf("\n");
	
	BiTNode* e = BST_Search_D(T, 2);
	printf("di data: %d \n", e->data);
	BiTNode* e1 = BST_Search_F(T, 2);
	printf("fei di data: %d \n", e1->data);
}