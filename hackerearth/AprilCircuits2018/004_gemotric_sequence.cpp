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

int n;
ll data[N];
int vis[N];
vector<int> fac[N];

struct Node {
    int a, b;

    Node() {}
    Node(int _a, int _b): a(_a), b(_b) {}

    bool operator == (const Node& rhs) const {
        return a == rhs.a && b == rhs.b;
    }
    bool operator < (const Node& rhs) const {
        return a != rhs.a ? a < rhs.a : b < rhs.b;
    }
};

struct HashFunc
{
    std::size_t operator()(const Node &rhs) const 
    {
        using std::size_t;
        using std::hash;

        return ((hash<int>()(rhs.a * N)
            + (hash<int>()(rhs.b))));
    }
};

int main() {    
    IOS;

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j * j <= i; ++j) if (i % j == 0) {
            fac[i].pb(j);
            if (i / j != j) fac[i].pb(i / j);
        }
    }

    cin >> n;
    int m = 0, st = inf;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (st == inf) st = t;
        if (t != 0) data[m++] = t;
    }
    int ans = n - m;
    if (st != 0) ans++;

    n = m;

    map<Node, int> ma;
    map<int, int> show;
    // unordered_map<Node, int, HashFunc> ma;
    // unordered_map<int, int> show;
    for (int i = 0; i < n; ++i) {
        int p = data[i];
        for (int j = 0; j < fac[abs(p)].size(); ++j) {
            int q = fac[abs(p)][j];
            if (q != 1 && q % (abs(p) / q) != 0) continue;

            // printf("p = %d q = %d\n", p, q);
            if (show[q]) {
                int r = q / (p / q);
                Node now = Node(p, q), pre = Node(q, r);
                ma[now] = max(ma[now], ma[pre] + 1);
            }
            if (show[-q]) {
                int r = q / (p / q);
                Node now = Node(p, -q), pre = Node(-q, r);
                ma[now] = max(ma[now], ma[pre] + 1);
            }
        }
        show[p] = 1;
    }

    for (auto x: ma) ans = max(ans, x.se + 1);


    cout << ans << endl;
    return 0;
}
    
