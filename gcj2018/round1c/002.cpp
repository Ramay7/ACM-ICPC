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

int T, cases = 0;
int n, D[210];
vector<int> show[210];
int num[210];
set<int> used;

int main() {        
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 210; ++i) show[i].clear();
        memset(num, 0, sizeof (num));
        used.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &D[i]);
            for (int j = 0; j < D[i]; ++j) {
                int t;
                scanf("%d", &t);
                show[i].pb(t);
                num[t]++;
            }

            int find = -1, Min = inf;
            for (int j = 0; j < D[i]; ++j) {
                if (used.find(show[i][j]) != used.end()) {
                    continue;
                }

                if (num[show[i][j]] < Min) {
                    Min = num[show[i][j]];
                    find = show[i][j];
                }
            }
            if (find == -1) printf("-1\n");
            else {
                printf("%d\n", find);
                used.insert(find);
            }
            fflush(stdout);
        }

    }
    return 0;
}
    
