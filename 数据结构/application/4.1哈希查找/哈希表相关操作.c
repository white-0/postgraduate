#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define keytype int

typedef struct{   //  元素类型 
	keytype key;
	char info[20];
}elemtype;
typedef struct hnode{   //  哈希表链结点类型 
	elemtype data; 
	struct hnode *next; 
}hnode, *head;
typedef head HT[100];  //  HT为哈希表类型  
void InitHT(HT ht, int n);
void InsertHT(HT ht, int n, elemtype x);
int DeleteHT(HT ht, int n, keytype K); //  删除成功返回1，否则返回0

void InitHT(HT ht, int n) {
	int i;
	for(i = 0; i<n; i++) {
	    ht[i]->next = NULL;
	}
}

void Insert(HT ht, int n, elemtype x) {    //向哈希表中插入关键字key
	head newnode=(head)malloc(sizeof(hnode));
	head p, pre;
	if(!newnode) {
		printf("Insufficient memory !\n");
		return;
	}
	newnode->data=x;
	if(ht[x.key%n]){   //该条链表不为空
	    for(p=ht[x.key%n]; p!=NULL; pre=p, p=p->next){
		    if(p->data.key == x.key) 
				break;
	    }
	    newnode->next=pre->next;
	    pre->next=newnode;
	} else{
		ht[x.key%n] = newnode;
		newnode->next=NULL;
	}
}

int Search(HT ht, int n, elemtype x) {   
    head p, pre;
	if(ht[x.key%n]){   //该条链表不为空
	   for(p=ht[x.key%n]; p!=NULL; pre=p, p=p->next){
		    if(p->data.key == x.key) 
                return 1;
	   }
        return 0;
	} else {         //该条链表为空
	    return 0;
	}
} 

int Delete(HT ht, int n, elemtype x) {//删除哈希表中特定的关键字
	head p, pre;
	if(ht[x.key%n]){ //该条链表不为空
		for(p=ht[x.key%n]; p!=NULL; pre=p, p=p->next){
			if(p->data.key == x.key){
				head tmp = p;
				pre->next = p->next;
				free(tmp);
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	return 0;
}