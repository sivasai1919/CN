#include <stdio.h>

#define INF 999
#define MAX 10

int main() {
    int cost[MAX][MAX], dist[MAX][MAX], via[MAX][MAX];
    int n, i, j, k, flag;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix (use 999 for no direct link):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            cost[i][j] = (i == j) ? 0 : cost[i][j];
            dist[i][j] = cost[i][j];
            via[i][j] = j;
        }

    // Distance Vector Algorithm
    do {
        flag = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                for(k = 0; k < n; k++) {
                    if(dist[i][j] > cost[i][k] + dist[k][j]) {
                        dist[i][j] = cost[i][k] + dist[k][j];
                        via[i][j] = k;
                        flag = 1;
                    }
                }
            }
        }
    } while(flag);

    // Print results
    printf("\n--- Final Distance Vector Table ---\n");
    for(i = 0; i < n; i++) {
        printf("\nRouter %d:\n", i + 1);
        printf("Destination\tNext Hop\tDistance\n");
        for(j = 0; j < n; j++) {
            if(i != j)
                printf("%d\t\t%d\t\t%d\n", j + 1, via[i][j] + 1, dist[i][j]);
        }
    }

    return 0;
}
