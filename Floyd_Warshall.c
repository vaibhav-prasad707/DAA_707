#include <stdio.h>
#define V 4
#define INF 99999

void printSolution(int dist[][V],int k);

void floyd_Warshall(int dist[][V])
{
	int i, j, k;

	for (k = 0; k < V; k++) {
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
		printSolution(dist,k+1);
	}
}

void printSolution(int dist[][V],int k)
{
	printf("A%d=\n",k);
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				printf("%d ", 100);
			else
				printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
}
int main()
{

	int graph[V][V] = { { 0, 3, INF,5 },
						{2, 0, INF, 4 },
						{ INF, 1, 0, INF },
						{ INF, INF, 2, 0 } };
    printf("A0 =\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]==INF) printf("%d ",100);
            else printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
	floyd_Warshall(graph);
	return 0;
}

