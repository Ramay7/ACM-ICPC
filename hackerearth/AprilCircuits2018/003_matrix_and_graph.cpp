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

int n, m;
int A[300][300], B[300][300], P[300];
PI e[300 * 300];

int main() {    
    IOS;
    double st = clock();
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> A[i][j];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> B[i][j];
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> e[i].fi >> e[i].se;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) P[i] = i, ans.pb(i);

    double sumA = 0, sumB = 0;
    for (int i = 0; i < m; ++i) {
        sumA += A[P[e[i].fi]][P[e[i].se]];
        sumB += B[P[e[i].fi]][P[e[i].se]];
    }
    double Min = sumA * sumB;
    
    while (1) {
        double ed = clock();
        double cost = (ed - st) / CLOCKS_PER_SEC;
        if (cost >= 1.85) break;

        random_shuffle(P, P + n);
        sumA = sumB = 0;
        for (int i = 0; i < m; ++i) {
            sumA += A[P[e[i].fi]][P[e[i].se]];
            sumB += B[P[e[i].fi]][P[e[i].se]];
        }
        if (sumA * sumB < Min) {
            Min = sumA * sumB;
            ans.clear();
            for (int i = 0; i < n; ++i) ans.pb(P[i]);
        }
    }
    for (int i = 0; i < n; ++i) printf("%d%c", ans[i], " \n"[i == n- 1]);
    return 0;
}
    
