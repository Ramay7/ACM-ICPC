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
const int N = 1000010;

const int dir[][2] = {{1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {0, 0}};

int T, A, cases = 0;
int vis[1010][1010];

inline int check(int x, int y) {
    for (int i = 0; i < 9; ++i) {
        if (!vis[x + dir[i][0]][y + dir[i][1]]) {
            return 0;
        }
    }
    return 1;
}

int draw(int x, int y) {
    do {
        printf("%d %d\n", x, y);
        fflush(stdout);
        int tx, ty;
        scanf("%d%d", &tx, &ty);
        assert(tx != -1);
        if (tx == 0 && ty == 0) return 2;
        vis[tx][ty] = 1;
    } while(!check(x, y));
    return 1;
}

int main() {    
    scanf("%d", &T);
    while (T--) {
        memset(vis, 0, sizeof (vis));
        scanf("%d", &A);

        for (int i = 2; i <= 206; i += 3) {
            int t = draw(2, i);
            if (t == 2) break;
        }
    }
    return 0;
}
    
