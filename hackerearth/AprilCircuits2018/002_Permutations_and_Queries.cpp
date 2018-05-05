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
const int N = 510;
const int MK = N * N / 2;

int fac[N], dp[N][MK], C[N][N];

void init() {
    for (int i = 0; i < MK; ++i) dp[0][i] = 1;
    for (int i = 1; i < N; ++i) {
        for (int k = 0; k < MK; ++k) {
            dp[i][k] = dp[i - 1][k];
            int t = k - (i - 1);
            if (t > 0) dp[i][k] -= dp[i - 1][t - 1];
            if (dp[i][k] < 0) dp[i][k] += mod;
        }

        for (int k = 1; k < MK; ++k) dp[i][k] = (dp[i][k] + dp[i][k - 1]) % mod;
    }

    fac[0] = 1;
    for (int i = 1; i < N; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;

    C[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j < N; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
}

int main() {

    for (int i = 2; i < 20; ++i) if (miller_robain(i)) {
        cout << "i = " << i << endl;
    }
    return 0;

    IOS;
    init();
    int Q, n, K;
    cin >> Q;
    while (Q--) {
        cin >> n >> K;

        K = min(K, MK - 1);

        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += 1ll * C[n][i] * dp[i][K] % mod * (n - i + 1) % mod * fac[n - i] % mod;
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}
    
