#include <stdio.h>
#include <stdlib.h>

#define INFINITY 99999

//struct for the edges of the graph
struct Edge {
  int u;  //start vertex of the edge
  int v;  //end vertex of the edge
  int w;  //weight of the edge (u,v)
};

//Graph - it consists of edges
struct Graph {
  int V;        //total number of vertices in the graph
  int E;        //total number of edges in the graph
  struct Edge *edge;  //array of edges
};

void bellmanford(struct Graph *g, int source);
void display(int arr[], int size);

int main(void) {
  //create graph
  struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
  g->V = 6;  //total vertices
  g->E = 9;  //total edges

  //array of edges for graph
  g->edge = (struct Edge *)malloc(g->E * sizeof(struct Edge));

  

  //for A to B
    g -> edge[0].u = 0;
    g -> edge[0].v = 1;
    g -> edge[0].w = 6;
    
    //for A to C
    g -> edge[1].u = 0;
    g -> edge[1].v = 2 ;
    g -> edge[1].w = 4;
    
    //for A to D
    g -> edge[2].u = 0;
    g -> edge[2].v = 3;
    g -> edge[2].w = 5;
    
    //for C to B
    g -> edge[3].u = 2;
    g -> edge[3].v = 1;
    g -> edge[3].w = -2;
    
    //for D to C
    g -> edge[4].u = 3;
    g -> edge[4].v = 2;
    g -> edge[4].w = -2;
    
    //for C to E
    g -> edge[5].u = 2;
    g -> edge[5].v = 4;
    g -> edge[5].w = 3;
    
    //for E to F
    g -> edge[6].u = 4;
    g -> edge[6].v = 5;
    g -> edge[6].w = 3;
    
    //for D to F
    g -> edge[7].u = 3;
    g -> edge[7].v = 5;
    g -> edge[7].w = -1;
    
    //for B to E
    g -> edge[8].u = 1;
    g -> edge[8].v = 4;
    g -> edge[8].w = -1;

  bellmanford(g, 0);  //0 is the source vertex

  return 0;
}

void bellmanford(struct Graph *g, int source) {
  //variables
  int i, j, u, v, w;

  //total vertex in the graph g
  int total_Vertex = g->V;

  int total_Edge = g->E;

  int distance[total_Vertex];

  for (i = 0; i < total_Vertex; i++) {
    distance[i] = INFINITY;
  }
  distance[source] = 0;

  for (i = 1; i <= total_Vertex - 1; i++) {
    for (j = 0; j < total_Edge; j++) {
      u = g->edge[j].u;
      v = g->edge[j].v;
      w = g->edge[j].w;

      if (distance[u] != INFINITY && distance[v] > distance[u] + w) {
        distance[v] = distance[u] + w;
      }
    }
  }
  for (i = 0; i < total_Edge; i++) {
    u = g->edge[i].u;
    v = g->edge[i].v;
    w = g->edge[i].w;
    if (distance[u] != INFINITY && distance[v] > distance[u] + w) {
      printf("Negative weight cycle detected!\n");
      return;
    }
  }

  int a = 65;
    for(int i=0;i<total_Vertex;i++){
        char temp = (char)a;
        printf("%c-%d\n", temp,distance[i] );
        a++;
    }
}
