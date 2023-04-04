#include <stdio.h>
#include <stdlib.h>

typedef  char  Item; //环形队列的数据类型,根据自身情况设置
#define QUEUE_SIZE 100

typedef struct queue   
{   
    Item data[QUEUE_SIZE];  // 使用指针的方式，大小在使用循环队列的文件分配，减少queue.c、queue.h和其他文件的耦合性！
    unsigned int front;     // 指向队列第一个元素  
    unsigned int rear;      // 指向队列最后一个元素的下一个元素    
}queue, *SqQueue;
    
void Init_Queue(SqQueue Q)  
{        
    Q->front = 0;                              
    Q->rear = 0;   
    
    return;     
} 
 
int isFull(SqQueue Q)  
{  
    if(Q->front==(Q->rear+1) % QUEUE_SIZE) {     
        return 1;
    } else { 
        return 0;
    }  
} 
 
int isEmpty(SqQueue Q)  
{  
    if(Q->front==Q->rear) {                   
        return 1;  
    } else {
        return 0;  
    }
}  
 
int Insert_Queue(SqQueue Q, Item val)  
{  
    if(isFull(Q)) {  
        return 0; 
    } else {  
        Q->data[Q->rear] = val;  
        Q->rear = (Q->rear+1) % QUEUE_SIZE;  
        return 1;  
    }      
}  
  
int Delete_Queue(SqQueue Q, Item *val)  
{  
    if(isEmpty(Q)) {  
        return 0;  
    } else {  
        *val = Q->data[Q->front];  
        Q->front = (Q->front+1) % QUEUE_SIZE;  
        return 1;  
    }  
} 


int main()
{
    queue queue;
    int count = 0;
    Item value = 'a';
    
    Init_Queue(&queue);
    
    for(count = 0; count < 8; count++) {
        Insert_Queue(&queue, value);
        value++;
    }   
    
    for(count = 0; count < 8; count++) {
        Delete_Queue(&queue, &value);
        printf("%c ", value);
    }
    printf("\n");
    
    return 0;
}