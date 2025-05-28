#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
Graph *createGraph(int maxVertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->maxVertices = maxVertices;
    graph->adj = malloc(maxVertices * sizeof(int *));
    for (int i = 0; i < maxVertices; i++) {
        graph->adj[i] = calloc(maxVertices, sizeof(int));
    }

    return graph;

}
 
int addEdge(Graph *graph, int src, int dest) {
    if (src < 0 || dest < 0 || src >= graph->maxVertices || dest >= graph->maxVertices)
        return 0;
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // undirected graph
    return 1;

}
 
int removeEdge(Graph *graph, int src, int dest) {
    if (src < 0 || dest < 0 || src >= graph->maxVertices || dest >= graph->maxVertices)
        return 0;
    graph->adj[src][dest] = 0;
    graph->adj[dest][src] = 0;
    return 1;

}
 
void printGraph(Graph *graph) {
    printf("#Graph {\n");
    for (int i = 0; i < graph->maxVertices; i++) {
        printf("#\t%d -> ", i);
        for (int j = 0; j < graph->maxVertices; j++) {
            if (graph->adj[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    printf("#}\n");

}
 
void breadthFirst(Graph *graph, int src) {
    bool *visited = calloc(graph->maxVertices, sizeof(bool));
    int *queue = malloc(graph->maxVertices * sizeof(int));
    int front = 0, rear = 0;
    visited[src] = true;
    queue[rear++] = src;
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
        for (int i = 0; i < graph->maxVertices; i++) {
            if (graph->adj[current][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    free(queue);
    free(visited);

}
 
void dfsHelper(Graph *graph, int src, bool *visited) {
    visited[src] = true;
    printf("%d ", src);
    for (int i = 0; i < graph->maxVertices; i++) {
        if (graph->adj[src][i] && !visited[i]) {
            dfsHelper(graph, i, visited);
        }
    }
}
 
void depthFirst(Graph *graph, int src) {
    bool *visited = calloc(graph->maxVertices, sizeof(bool));
    dfsHelper(graph, src, visited);
    free(visited);

}
 
int findShortestPath(Graph *graph, int src, int dest, int *path) {
    int *prev = malloc(graph->maxVertices * sizeof(int));
    bool *visited = calloc(graph->maxVertices, sizeof(bool));
    int *queue = malloc(graph->maxVertices * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 0; i < graph->maxVertices; i++) {
        prev[i] = -1;
    }

    visited[src] = true;
    queue[rear++] = src;

    while (front < rear) {
        int current = queue[front++];
        if (current == dest) break;

        for (int i = 0; i < graph->maxVertices; i++) {
            if (graph->adj[current][i] && !visited[i]) {
                visited[i] = true;
                prev[i] = current;
                queue[rear++] = i;
            }
        }
    }

    // Reconstruct path
    int steps = 0;
    int crawl = dest;
    int temp[graph->maxVertices];
    while (crawl != -1) {
        temp[steps++] = crawl;
        crawl = prev[crawl];
    }

    // The number of steps is steps-1 (since steps counts nodes)
    int actualSteps = steps - 1;
    
    for (int i = 0; i < steps; i++) {
        path[i] = temp[steps - i - 1];
    }
    path[steps] = -1;

    free(prev);
    free(visited);
    free(queue);

    return actualSteps;  // Return steps-1 instead of steps
}
 
// visualizeMaze function already provided in your original code, unchanged
 
void visualizeMaze(Graph *graph, int rows, int cols) {
  int *openings = (int *)calloc(cols, sizeof(int));
  printf("#");
  for (int j = 0; j < cols; j++) {
    printf("+----");
    if (j == cols - 1) {
      printf("+");
    }
  }
  printf("\n");
  for (int i = 0; i < rows; i++) {
    printf("#");
    if (i > 0) {
      printf("|");
    } else {
      printf(" ");
    }
    for (int j = 0; j < cols; j++) {
      int cell = i * cols + j;
      if (cell < 10) {
        printf(" ");
      }
      printf(" %d ", cell);
      if (j < cols) {
        if (graph->adj[cell][cell + 1] || (i == rows - 1 && j == cols - 1)) {
          printf(" ");
        } else {
          printf("|");
        }
      }

      openings[j] = 0;
      if (cell + cols < graph->maxVertices) {
        openings[j] = graph->adj[cell][cell + cols];
      }
    }

    printf("\n");
    printf("#");

    for (int j = 0; j < cols; j++) {
      if (openings[j] == 1) {
        printf("+    ");
      } else {
        printf("+----");
      }
      if (j == cols - 1) {
        printf("+");
      }
    }
    printf("\n");
  }
  free(openings);
}
 
void deleteGraph(Graph *graph) {
    for (int i = 0; i < graph->maxVertices; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);

}
