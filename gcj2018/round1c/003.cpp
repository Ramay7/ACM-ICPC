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
const int M = 50010;

int T, cases = 0;
int n, w[100010];
ll dp[100010];

int main() { 
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
        memset(dp, 0x3f, sizeof (dp));
        dp[0] = 0;

        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = min(i, 200); j >= 1; --j) {
                if (dp[j - 1] <= 1ll * w[i] * 6) {
                    dp[j] = min(dp[j], dp[j - 1] + w[i]);
                }
                if (dp[j] != INF) ans = max(ans, j);
            }
        }
        printf("Case #%d: %d\n", ++cases, ans);
    }
    return 0;
}
    
