#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long ll;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define PI pair<int,int>

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = (ll)(1e9 + 7);
const int N = 100010;

int n, Min;
int s[N], w[N], vis[N], ring[N];
vector<int> G[N];
ll ans = 0;

void dfs(int u, int fa) {
    vis[u] = 1;
    int tmp = 0;
    for (auto x: G[u]) if (x != fa && !ring[x]) {
        dfs(x, u);
        tmp = max(tmp, w[x]);
    }
    for (auto x: G[u]) if (x != fa && ring[x]) {
        Min = min(Min, max(0, w[x] - tmp)); // !!! this is very very crucial
        // printf("\nu = %d x = %d\n", u, x);
        tmp = max(tmp, w[x]);
    }
    //printf("u = %d tmp = %d\n", u, tmp);
    ans -= tmp; // matain the edge which has maximum weight
}

int main() {    
    IOS;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        G[s[i]].pb(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        ans += w[i];
    }

    memset(ring, 0, sizeof (ring));

    for (int i = 1; i <= n; ++i) if (!vis[i]) {
        int j = i;
        while (1) {
            if (vis[j]) break;
            vis[j] = 1;
            j = s[j];
        } // j is on the ring

     //   printf("find j on the ring: %d\n", j);
        
        int num = 0;
        while (1) {
            if (ring[j]) break;
            ++num;
            ring[j] = 1;
            j = s[j];
        }
        if (num == n) { // all nodes are on the ring
            puts("0");
            return 0;
        }
    //    printf("number of nodes on the ring: %d\n", num);

        int k = j;
        Min = inf;
        while (1) {
            dfs(k, -1);
            k = s[k];
            if (k == j) break;
        }
    //    printf("i = %d Min = %d\n", i, Min);
        ans += Min; // plus the cost of destroying the ring
    }
    cout << ans << endl;
    return 0;
}
    
