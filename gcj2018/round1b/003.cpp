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
const int N = 110;

int T, n, m, cases = 0;
ll data[N], have[N], need[N];
int vis[N];
pair<int, int> require[N];

inline bool dfs(int cur) {
    if (have[cur] >= need[cur]) {
        have[cur] -= need[cur];
        need[cur] = 0;
        return true;
    }
    vis[cur] = 1;

    if (vis[require[cur].fi] || vis[require[cur].se]) return false;

    need[cur] -= have[cur];
    need[require[cur].fi] += need[cur];
    need[require[cur].se] += need[cur];

    need[cur] = have[cur] = 0;
    bool flag = dfs(require[cur].fi) && dfs(require[cur].se);
    vis[cur] = 0;
    return flag; 
}

inline bool check(ll x) {
    memset(need, 0, sizeof (need));
    memset(vis, 0, sizeof (vis));
    for (int i = 1; i <= n; ++i) have[i] = data[i];
    need[1] = x;
    return dfs(1);
}   

int main() { 
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d%d", &require[i].fi, &require[i].se);

        for (int i = 1; i <= n; ++i) scanf("%lld", &data[i]);
        ll ans = data[1], low = data[1] + 1, high = 1e11, mid;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (check(mid)) ans = mid, low = mid + 1;
            else high = mid - 1;
        }
        printf("Case #%d: %lld\n", ++cases, ans);
    } 
    return 0;
}
    
