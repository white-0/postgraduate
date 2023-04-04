#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct ArcNode {
    int adjvex;
    struct ArcNode* nextarc;
}ArcNode;

typedef struct {
    int data;
    ArcNode *firstArc;
}VNode;

typedef struct {
    VNode adjList[MAX_SIZE];
    int n, e;
}AGraph;

AGraph *graph;
int visited[MAX_SIZE];


void DFS(int pos, AGraph* G){
    printf("%d ", pos);
    visited[pos] = 1;
    ArcNode* p = G->adjList[pos].firstArc;
    while (p != NULL) {
        if (visited[p->adjvex] == 0) DFS(p->adjvex, G);
        p = p->nextarc;
    }
}

void BFS(int pos, AGraph* G) {
    memset(visited, 0, sizeof(visited));
    int queue[G->n];
    int head = 0, tail = 0;
    ArcNode* p;
    queue[ ++ tail] = pos;
    visited[pos] = 1;
    while (head < tail) {
        pos = queue[ ++ head];
        printf("%d ", pos);
        p = G->adjList[pos].firstArc;
        while (p != NULL) {
            if (visited[p->adjvex] == 0) {
                queue[ ++ tail] = p->adjvex;
                visited[p->adjvex] = 1;
            }
            p = p->nextarc;
        }
    }
}

//插入链表末尾
void  insertNode(ArcNode *node, ArcNode *newNode) {
    ArcNode *p = node;
    while(p->nextarc != NULL) {
        p = p->nextarc;
    }
    p->nextarc = newNode;
}
  
void create() {
    graph = (AGraph*)malloc(sizeof(AGraph));
    printf("input node's number: ");
    scanf("%d", &graph->n);
    printf("\n");
    printf("input graph edges' number: ");
    scanf("%d", &graph->e);
  
    int u = -1, v = -1;
    for(int i = 0; i < graph->n; i++) {
        graph->adjList[i].firstArc = NULL;
    }
  
    ArcNode *node;
    for(int i = 0; i < graph->e; i++) {
        printf("input linked node A and B: ");
        scanf("%d%d", &u, &v);
        printf("\n");
        node = (ArcNode *)malloc(sizeof(ArcNode));
        node->adjvex = v;
        node->nextarc = NULL;
        graph->adjList[u].data = u;
        if(graph->adjList[u].firstArc == NULL) {
            //边
            graph->adjList[u].firstArc = node;
        } else {
            //插入边
            insertNode(graph->adjList[u].firstArc, node);
        }
    }
}
  
void  travseTree() {
    for(int i = 0; i < graph->n; i++) {
        if(graph->adjList[i].firstArc != NULL) {
            printf("linked with %d are: ", i);
            ArcNode *p = graph->adjList[i].firstArc;
            while(p != NULL) {
                printf("%d ", p->adjvex);
                p = p->nextarc;
            }
            printf("\n");
        }
    }
}
// 1、假设图采用邻接表表示，采用深度优先遍历和广度优先遍历，
// 判断结点i和结点j之间是否存在路径
// 1. i,j is or not have path
int DFSMethod01(AGraph* G, int i, int j) {
    memset(visited, 0, sizeof(visited));
    DFS(i, G);
    if (visited[j] == 0) return 0;
    else return 1;
}

int BFSMethod01(AGraph* G, int i, int j) {
    memset(visited, 0, sizeof(visited));
    BFS(i, G);
    if (visited[j] == 0) return 0;
    else return 1;
}

// 2、假设图采用邻接表表示，设计一个算法，判断无向图是否是连通图
// 2. lintongtu
int DFSMethod02(AGraph *G, int i) {
    int flag = 1;
    memset(visited, 0, sizeof(visited));
    DFS(i, G);
    int j;
    for (j = 1; j <= G->n; j ++ ) {
        if (visited[j] == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}
int BFSMethod02(AGraph *G, int i) {
    int flag = 1;
    memset(visited, 0, sizeof(visited));
    BFS(i, G);
    int j;
    for (j = 1; j <= G->n; j ++ ) {
        if (visited[j] == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

// 3、假设图采用邻接表表示，设计一个算法，求解距离结点U最远的结点V；
int maxDist(AGraph* G, int U){
    ArcNode *p;
    int queue[MAX_SIZE], front = 0, rear = 0, j, k;
    rear ++; queue[rear] = U;
    visited[U] = 1;
    int V;
    while(rear != front) {
        front = (front +1) % MAX_SIZE;
        V = queue[front];
        p = G -> adjList[V].firstArc;
        while(p != NULL) {
            j = p -> adjvex;
            if( visited[j] == 0) {
                visited[j] = 1;
                rear = (rear + 1) % MAX_SIZE;
                queue[rear] = j;
            }
            p = p->nextarc;
        }
    }
    return V;
}


int main()
{
    create();
    // int res1 = DFSMethod01(graph, 1, 3);
    // int res2 = DFSMethod01(graph, 2, 6);
    // int res3 = BFSMethod01(graph, 1, 3);
    // int res4 = BFSMethod01(graph, 2, 6);
    // printf("\n");
    // printf("%d %d %d %d\n", res1, res2, res3, res4);
    // travseTree();
    // DFS(1, graph);
    // printf("\n");
    // BFS(1, graph);
    // printf("\n");
    // int res1 = DFSMethod02(graph, 1);
    // int res2 = BFSMethod02(graph, 1);

    // printf("%d %d\n", res1, res2);
    int res = maxDist(graph, 1);
    printf("%d ",res);
    return  0;
}