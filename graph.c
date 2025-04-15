#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
static Node *CreateNode(int v);

typedef struct queue {
    Node *front, *rear;
} Queue;
static bool EnQueue(Queue *pq, int v);
static int DeQueue(Queue *pq);

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

void DisplayAdgList(const Graph *pg) {
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

void dfs(const Graph *pg, int v) {
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
    putchar('\n');
}

void bfs(const Graph *pg, int v) {
    Queue *pq = (Queue *)malloc(sizeof(Queue));
    pq->front = pq->rear = NULL;
    bool *used = (bool *)calloc(pg->n, sizeof(bool));
    used[v] = true;
    EnQueue(pq, v);
    printf("BFS from %d: ", v);
    while (pq->rear != NULL) {
        int current = DeQueue(pq);
        printf("%d ", current);
        Node *temp = pg->AdjList[current];
        while (temp != NULL) {
            int v = temp->v;
            if (!used[v]) {
                used[v] = true;
                EnQueue(pq, v);
            }
            temp = temp->next;
        }
    }
    while(pq->rear != NULL)
        DeQueue(pq);
    free(pq);
    free(used);
    putchar('\n');
}

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

static bool EnQueue(Queue *pq, int v) {
    Node *temp = CreateNode(v);
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation error in EnQueue");
        return false;
    }
    if (pq->rear == NULL) {
        pq->front = pq->rear = temp;
    }
    else {
        pq->rear->next = temp;
        pq->rear = temp;
    }
    return true;
}

static int DeQueue(Queue *pq) {
    if (pq->front == NULL) 
        return -1;
    Node* temp = pq->front;
    int v = temp->v;
    pq->front = pq->front->next;
    if (pq->front == NULL)
        pq->rear = NULL;
    free(temp);
    return v;
}