#include "graph.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  Graph *graph = NULL;
  int n;
  scanf("%d", &n);
  graph = createGraph(n);

  int u, v, size;
  int active = 1;
  char op;

  int *path = calloc(graph->maxVertices, sizeof(int));

  while (active) {
    scanf(" %c", &op);
    switch (op) {
    case '+':
      scanf("%d %d", &u, &v);
      printf("# added? %d\n", addEdge(graph, u, v));
      break;
    case '-':
      scanf("%d %d", &u, &v);
      printf("# removed? %d\n", removeEdge(graph, u, v));
      break;
    case 'p':
      printGraph(graph);
      break;
    case 'b':
      scanf("%d ", &u);
      printf("BF (%d): ", u);
      breadthFirst(graph, u);
      printf("\n");
      break;
    // dfs
    case 'd':
      scanf("%d ", &u);
      printf("DF (%d): ", u);
      depthFirst(graph, u);
      printf("\n");
      break;
    // богино зам олох
    case 's':
      scanf("%d %d", &u, &v);
      for (int i = 0; i < graph->maxVertices; i++) {
        path[i] = -1;
      }
      printf("Shortest Path (%d->%d = %d step): ", u, v, findShortestPath(graph, u, v, path));
      for (int i = 0; i < graph->maxVertices; i++) {
        if (path[i] == -1) {
          break;
        }
        printf("%d ", path[i]);
      }
      printf("\n");
      break;
    case 'm':
      // квадрат гэж үзнэ
      size = sqrt(graph->maxVertices);
      visualizeMaze(graph, size, size);
      break;
    default:
      active = 0;
      break;
    }
  }
  free(path);
  deleteGraph(graph);

  return 0;
}
