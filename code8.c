#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge edges[MAX];
};

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int u, int v) {
    int uRoot = find(u);
    int vRoot = find(v);
    parent[uRoot] = vRoot;
}

void sortEdges(struct Graph* graph) {
    for (int i = 0; i < graph->E - 1; i++) {
        for (int j = 0; j < graph->E - i - 1; j++) {
            if (graph->edges[j].weight > graph->edges[j + 1].weight) {
                struct Edge temp = graph->edges[j];
                graph->edges[j] = graph->edges[j + 1];
                graph->edges[j + 1] = temp;
            }
        }
    }
}

void kruskal(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[MAX];
    int e = 0;

    sortEdges(graph);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    for (int i = 0; i < graph->E && e < V - 1; i++) {
        struct Edge next = graph->edges[i];
        int u = find(next.src);
        int v = find(next.dest);

        if (u != v) {
            result[e++] = next;
            unionSet(u, v);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < e; i++)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    struct Graph graph;
    int i;

    printf("Enter number of vertices: ");
    scanf("%d", &graph.V);

    printf("Enter number of edges: ");
    scanf("%d", &graph.E);

    printf("Enter each edge in format: src dest weight\n");
    for (i = 0; i < graph.E; i++) {
        scanf("%d %d %d", &graph.edges[i].src, &graph.edges[i].dest, &graph.edges[i].weight);
    }

    kruskal(&graph);

    return 0;
}