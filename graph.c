#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
static Node *CreateNode(int v);

bool InitGraph(Graph *pg, int n) {
    pg->n = n;
    pg->AdjList=(Node **)calloc(n, sizeof(Node *));
    if (!pg->AdjList) {
        fprintf(stderr, "Memory allocation error in InitGraph");
        return false;
    }
    return true;
}

Node *CreateNode(int v) {
    Node *pnew = malloc(sizeof(Node));
    pnew->v = v;
    pnew->next = NULL;
    return pnew;
}

bool AddEdge(Graph *pg, int u, int v) {
    Node* pnew = CreateNode(v);
    if (!pnew) {
        fprintf(stderr, "Memory allocation error in AddEdge");
        return false;
    }
    pnew->next = pg->AdjList[u];
    pg->AdjList[u] = pnew;
    return true;
}

void DisplayAdgList(Graph *pg) {
    for (int i = 0; i < pg->n; i++) {
        printf("Vertex %d: ", i);
        Node* temp = pg->AdjList[i];
        while (temp != NULL) {
            printf("[%d]->", temp->v);
            temp = temp->next;
        }
        puts("NULL\n");
    }
}

void dfs(Graph *pg, int v) {
    bool *used = (bool *)calloc(pg->n, sizeof(bool));
    int *stack = (int *)malloc(pg->n * sizeof(int));
    int stack_size = 0;
    stack[stack_size++] = v;
    printf("DFS from %d: ", v);
    while (stack_size > 0) {
         int current = stack[--stack_size];
         if (used[current])
            continue;
         used[current] = true;
         printf("%d ", current);
         Node *pcurrent = pg->AdjList[current];
         while (pcurrent != NULL) {
            if (!used[pcurrent->v])
                stack[stack_size++] = pcurrent->v;
            pcurrent = pcurrent->next;
         }
    }
    free(used);
    free(stack);
}
void bfs(Graph *pg, int v);

void EmptyGraph(Graph *pg) {
    if (!pg)
        return;
    for (int i = 0; i < pg->n; i++) {
        Node *current = pg->AdjList[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(pg->AdjList);
}