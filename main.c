#include <stdio.h>
#include "graph.h"

int main(void) {
    int n = 6;
    Graph g;
    InitGraph(&g, n);

    AddEdge(&g, 0, 1);
    AddEdge(&g, 1, 0);

    AddEdge(&g, 0, 3);
    AddEdge(&g, 3, 0);

    AddEdge(&g, 1, 2);
    AddEdge(&g, 2, 1);

    AddEdge(&g, 2, 3);
    AddEdge(&g, 3, 2);

    AddEdge(&g, 3, 4);
    AddEdge(&g, 4, 3);

    AddEdge(&g, 4, 5);
    AddEdge(&g, 5, 4);

    DisplayAdgList(&g);
    dfs(&g, 0);
    bfs(&g, 1);
    EmptyGraph(&g);
    return 0;
}