#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX 100
#define INF 32767

void prim(int n, int start, int cost[][MAX], int dist[], int path[]) {
    int i, j, k, min, minid, sum = 0;

    // 初始化dist和path数组
    for (i = 0; i < n; i++) {
        dist[i] = cost[start][i];
        path[i] = start;
    }
    for (i = 1; i < n; i++) {
        min = INF;
        minid = -1;
        // 找出当前dist数组中最小值对应的顶点
        for (j = 0; j < n; j++) {
            if (dist[j] != 0 && dist[j] < min) {
                min = dist[j];
                minid = j;
            }
        }
        if (minid == -1) {
            printf("无法构成最小生成树\n");
            return;
        }
        // 将最小生成树的边输出
        printf("  边(%d,%d)权为:%d\n", path[minid], minid, min);
        sum += min;
        dist[minid] = 0;
        // 更新dist和path数组
        for (k = 0; k < n; k++) {
            if (dist[k] != 0 && cost[minid][k] < dist[k]) {
                dist[k] = cost[minid][k];
                path[k] = minid;
            }
        }
    }
    printf("最小生成树的代价为:%d\n", sum);
}

int main() {
    int n, start, i, j;
    int cost[MAX][MAX], dist[MAX], path[MAX];
    scanf("%d", &n);
    scanf("%d", &start);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("普里姆算法求解结果:\n");
    prim(n, start, cost, dist, path);
    return 0;
}