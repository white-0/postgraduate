#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX 10
#define EdgeType int
#define VertexType int

int visited[MAX];    //访问标志数组 
typedef struct {
	VertexType vexs[MAX];   //顶点表 
	EdgeType arc[MAX][MAX];   //邻接矩阵 可看作边表   
	int numVertexes,numEdges;
	int GraphType;  //图的类型  无向0,有向1	
}MGraph;
//深度优先递归算法
void DFS(MGraph G,int i) {
	int j;
	visited[i]=1;   //被访问的标记 
	printf("%d ",G.vexs[i]);
	for(j=0;j<G.numVertexes;j++){
	  if(G.arc[i][j]==1&&!visited[j])  //边(i,j)存在且j顶点未被访问，递归 
			DFS(G,j);
	} 
}
//深度优先遍历
void DFS_traverse_Graph(MGraph G){ 
	int i;
	for(i=0;i<G.numVertexes;i++)
		visited[i]=0;
	for(i=0;i<G.numVertexes;i++)
			if(visited[i] == 0)
				DFS(G,i);		
} 

void createGraph(MGraph *G){
    int i,j,k,w;
    printf("请输入顶点数和边数：");
    scanf("%d%d", &G->numVertexes, &G->numEdges);
    //建立结点 
    for(i = 0; i < G->numVertexes; i++){
        scanf("%d", &G->vexs[i]);
    }
    //初始化边为无穷 
    for(i = 0; i < G->numVertexes; i++){
        for(j = 0; j < G->numVertexes; j++){
            G->arc[i][j] = INT32_MAX;
        }
    }
    //建立边
    printf("输入边的左右两个坐标:\n");
    for(k = 0; k < G->numEdges; k++){
        scanf("%d%d%d", &i,&j,&w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    } 
} 

typedef struct {
    int data[MAX];
    int front;
    int rear;
}Queue;

int InitQueue(Queue* Q) {
    Q->front = 0;
    Q->rear = 0;
    return 1;
}

int QueueEmpty(Queue Q) {
    if (Q.front == Q.rear) {
        return 1;
    }
    return 0;
}

int EnQueue(Queue* Q, int e) {
    if ((Q->rear + 1)%MAX == Q->front) {
        return 1;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAX;
    return 0;
}

int DeQueue(Queue* Q, int* e) {
    if (Q->front == Q->rear) {
        return 0;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX;
    return 1;
}
int getQueueTopData(Queue* Q) {
	return Q->data[Q->front];
}

/*
void BFS_traverse_Graph(MGraph G) {
    Queue Q;
    int e;
    for (int i = 0; i < G.numVertexes; i++) {
        visited[i] = 0;
    }
    InitQueue(&Q);
    for (int j = 0; j < G.numVertexes; j++) {
        if (!visited[j]) {
            visited[j] = 1;
            printf("%d ", G.vexs[j]);
            EnQueue(&Q, j);

            while (!QueueEmpty(Q))
            {
                DeQueue(&Q, &e);
                for (int k = 0; k < G.numVertexes; k++) {
                    if (G.arc[e][k] == 1 && visited[k] == 0) {
                        visited[k] = 1;
                        printf("%d ", G.vexs[k]);
                        EnQueue(&Q, k);
                    }
                }
            }
        }
    }
}
*/

void BFS(MGraph G, int j) {
	Queue Q;
    int e;
	InitQueue(&Q);
	visited[j] = 1;
    printf("%d ", G.vexs[j]);
    EnQueue(&Q, j);

    while (!QueueEmpty(Q))
    {
        DeQueue(&Q, &e);
        for (int k = 0; k < G.numVertexes; k++) {
            if (G.arc[e][k] == 1 && visited[k] == 0) {
                visited[k] = 1;
                printf("%d ", G.vexs[k]);
                EnQueue(&Q, k);
            }
        }
    }
}

void BFS_traverse_Graph(MGraph G) {
    
    for (int i = 0; i < G.numVertexes; i++) {
        visited[i] = 0;
    }
 
    for (int j = 0; j < G.numVertexes; j++) {
        if (!visited[j]) {
            BFS(G, j);
        }
    }
}





int main() {
    MGraph G;
    createGraph(&G);
    DFS_traverse_Graph(G);
    printf("\n");
    BFS_traverse_Graph(G);
	printf("\n");
    return 0;
}