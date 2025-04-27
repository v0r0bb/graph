#ifndef _GRAPH_H_
#define _GRAPH_H_

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
void DisplayAdgList(const Graph *pg);
void dfs(const Graph *pg, int v);
void bfs(const Graph *pg, int v);
void EmptyGraph(Graph *pg);

#endif