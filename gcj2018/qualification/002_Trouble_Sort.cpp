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

int T, n, cases = 0;
vector<int> data, vec[2];

int main() {    
    scanf("%d", &T);
    while (T--) {
        data.clear(); vec[0].clear(); vec[1].clear();
        scanf("%d", &n);
        int now = 0;
        for (int i = 0; i < n; ++i) {
            int t;
            scanf("%d", &t);
            vec[now].pb(t);
            now ^= 1;
        }
        sort(vec[0].begin(), vec[0].end());
        sort(vec[1].begin(), vec[1].end());
        now = 0;
        int tp[2] = {0, 0};
        for (int i = 0; i < n; ++i) {
            if (tp[now] == vec[now].size()) now ^= 1;
            data.pb(vec[now][tp[now]++]);
            now ^= 1;
        }
        int find = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (data[i] > data[i + 1]) {
                find = i;
                break;
            }
        }
        if (find == -1) printf("Case #%d: OK\n", ++cases);
        else printf("Case #%d: %d\n", ++cases, find);
    }
    return 0;
}
    
