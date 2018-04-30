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

int T, n, cases;
int D[N], A[N], B[N];
int X[N], Y[N];
set<PI> valid;

void solve() {
    int ans = 0, Max = 0;
    for (int i = 0; i < n; ++i) {
        if (i + Max > n) break;

        int len = 0, A = X[i], B = inf;
        for (int j = i; j < n; ++j) {
            if (A == X[j]) {
                len++;
            } else {
                if (B == inf) B = Y[j];
                if (B != Y[j]) {
                    break;
                } else len++;
            }
        }

        int len_ = 0, A_ = inf, B_ = Y[i];
        for (int j = i; j < n; ++j) {
            if (B_ == Y[j]) {
                len_++;
            } else {
                if (A_ == inf) A_ = X[j];
                if (A_ != X[j]) {
                    break;
                } else len_++;
            }
        }

        len = max(len, len_);
        if (len > Max) Max = len, ans = 1;
        else if (len == Max) ans++;
    }
    printf("%d %d\n", Max, ans);
}

int main() {    
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &D[i], &A[i], &B[i]);
            X[i] = D[i] + A[i];
            Y[i] = D[i] - B[i];
        }

        printf("Case #%d: ", ++cases);
        solve();
    }
    return 0;
}
    
