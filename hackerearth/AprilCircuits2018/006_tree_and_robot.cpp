#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N = 50010;
const int MAX_K = 55;

int n, root, total, K;
int head[MAX_N];
ll dp[MAX_N][MAX_K];

struct Edge {
    int v, w, next;
}edge[MAX_N * 2];

void AddEdge(int u, int v, int w)
{
    edge[total].v = v;
    edge[total].w = w;
    edge[total].next = head[u];
    head[u] = total++;
}

void wyr(int u, int p)
{
    for (int id = head[u]; id != -1; id = edge[id].next) {
        int v = edge[id].v, w = edge[id].w;
        if (v == p) continue;
        wyr(v, u);
        for (int i = K; i >= 0; --i) {
            dp[u][i] += dp[v][0] + 2 * w;
            for (int j = 1; j <= i; ++j) {
                dp[u][i] = min(dp[u][i], dp[v][j] + dp[u][i - j] + j * w);
            }
        }
    }
}

int main()
{
    while (~scanf("%d%d", &n, &K)) {
        memset(head, -1, sizeof(head));
        total = 0;
        for (int i = 1; i < n; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            AddEdge(u, v, w);
            AddEdge(v, u, w);
        }
        root = 1;
        memset(dp, 0, sizeof(dp));
        wyr(root, -1);
        printf("%lld\n", dp[root][K]);
    }
    return 0;
}
