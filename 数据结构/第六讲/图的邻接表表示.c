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
void DFS_traverse_Graph(AGraph* G) {
	int v;
	for (v = 0; v < G->n; v ++ )
		visited[v] = 0;
	ArcNode* p = G->adjList[v].firstArc;
	for (v = 0; v < G->n; v ++ )
		if (visited[v] == 0) DFS(v, G);
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

void BFS_traverse_Graph(AGraph* G) {
	int i, k;
	for (k = 0; k < G->n; k ++ )
		visited[k] = 0;
	for (i = 0; i < G->n; i ++ ) {
		if (visited[i] == 0)
			BFS(i, G);
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

int main()
{
    create();
    travseTree();
    // DFS(1, graph);
	DFS_traverse_Graph(graph);
    printf("\n");
    // BFS(1, graph);
	BFS_traverse_Graph(graph);
    printf("\n");
    return  0;
}