#include <stdbool.h>

typedef struct node {
    int v;
    struct node *next;
} Node;

typedef struct graph {
    int n;
    Node ** AdjList;
} Graph;

bool InitGraph(Graph *pg, int n);
bool AddEdge(Graph *pg, int u, int v);
void DisplayAdgList(Graph *pg);
void dfs(Graph *pg, int v);
void bfs(Graph *pg, int v);
void EmptyGraph(Graph *pg);