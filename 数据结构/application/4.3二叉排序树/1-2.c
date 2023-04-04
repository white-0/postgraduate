#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define Elemtype int

typedef struct Node{
	Elemtype data;
    struct Node *lchild, *rchild;
}node, *bitptr;

void InOrder(bitptr bNode) {
    if(bNode == NULL) return;
    InOrder(bNode->lchild);
    printf("%d ", bNode->data);
    InOrder(bNode->rchild);
}

bitptr Search_Insert(bitptr root, Elemtype e){
	node *p, *f, *new;
	p=root, f=root;
	while(p!=NULL){
		f=p;
		if(p->data == e) 
			break;
		else if(p->data > e)
			 p = p->lchild;
		else 
			p=p->rchild;
	}
	if(p==NULL){
		new = (node*)malloc(sizeof(node));
		new->lchild = NULL, 
	    new->rchild = NULL, 
 		new->data = e;
		if(f->data >e ) 
			f->lchild = new;
		else 
			f->rchild = new;
		p = new;
	}
	return root;
} 

int IsSearchTree(bitptr t) { //递归遍历二叉树是否为二叉排序树  
    if(!t)        //空二叉树情况  
        return 1;  
    else if(!(t->lchild) && !(t->rchild))   //左右子树都无情况  
        return 1;  
    else if((t->lchild) && !(t->rchild))    //只有左子树情况  
    {  
        if(t->lchild->data>t->data)  
            return 0;  
        else  
            return IsSearchTree(t->lchild);  
    }  
    else if((t->rchild) && !(t->lchild))   //只有右子树情况  
    {  
        if(t->rchild->data<t->data)  
            return 0;  
        else  
            return IsSearchTree(t->rchild);  
    }  
    else         //左右子树全有情况  
    {                                  
        if((t->lchild->data>t->data) || (t->rchild->data<t->data))  
           return 0;  
        else  
           return (IsSearchTree(t->lchild) && IsSearchTree(t->rchild) );  
    }  
}

int main(){
    bitptr tree = (bitptr)malloc(sizeof(node));
    tree = Search_Insert(tree, 1);
    tree = Search_Insert(tree, 2);
    tree = Search_Insert(tree, 10);
    tree = Search_Insert(tree, 5);
    tree = Search_Insert(tree, 8);
    tree = Search_Insert(tree, 12);
    tree = Search_Insert(tree, 7);
    InOrder(tree);
    printf("\n");
    int n = IsSearchTree(tree);
    printf("%d\n", n);
    printf("\n");
    return 0;
}