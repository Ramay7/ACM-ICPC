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
const int N = 1010;

int T, cases = 0, R, B, C;
int used[N];

struct Roobtic {
    int M, S, P;
} roobtic[N];


bool check(ll x) {
    vector <ll> data;
    for (int i = 0; i < C; ++i) {
        data.pb(min(1ll * roobtic[i].M, (x - roobtic[i].P) / roobtic[i].S));
    }
    sort(data.begin(), data.end());
    ll sum = 0;
    for (int j = data.size() - 1; C - j <= R; --j) {
        sum += data[j];
        if (sum >= B) return true;
    }
    return false;
}

int main() {    
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &R, &B, &C);
        for (int i = 0; i < C; ++i) {
            scanf("%d%d%d", &roobtic[i].M, &roobtic[i].S, &roobtic[i].P);
        }

        ll low = 1, high = INF, ans = high;
        while (low <= high) {
            ll mid = (low + high) >> 1;
            if (check(mid)) ans = mid, high = mid - 1;
            else low = mid + 1;
        }
        printf("Case #%d: %lld\n", ++cases, ans);
    }
    return 0;
}
    
