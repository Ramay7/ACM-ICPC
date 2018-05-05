#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef unsigned long long ll;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define PI pair<int,int>

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = (ll)(1e9 + 7);
const int N = 200010;

int n, tot = 0;
ll m;
ll data[N], ans[N], show[N];
unordered_map<ll, ll> ma;
unordered_map<ll, int> id;
set<ll> s;

int main() {  
    IOS;  
    //cout << (1ull << 63) - 1 << endl;
    cin >> n >> m;
    // scanf("%d%lld", &n, &m);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
        // scanf("%ll", &data[i]);
        s.insert(data[i]);
    }
    ma[1] = 1, ans[0] = 1;
    for (auto x: s) {
        show[tot] = x;
        id[x] = tot++;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = id[data[i]]; j >= 0; --j) {
            ma[data[i]] += ma[show[j]];
            ma[data[i]] %= mod;
        }
        ans[i] = ma[data[i]];
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    // printf("%lld%c", ans[i], " \n"[i == n - 1]);
    return 0;
}
    
