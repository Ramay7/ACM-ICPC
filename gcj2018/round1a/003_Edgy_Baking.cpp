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

int T, cases = 0, n, P, W, H;

int main() {    
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &P);
        double base = 0, Max = 0, Min = 1e18;
        vector<pair<double, double> > data;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &W, &H);
            if (W > H) swap(W, H);

            base += 2 * (W + H);
            data.pb(mp(2 * W, 2 * sqrt(W * W + H * H)));
            Max += 2.0 * sqrt(W * W + H * H);
            Min = min(Min, 2.0 * W);
        }
        printf("Case #%d: ", ++cases);

        if (P >= Max + base) {
            printf("%.10f\n",  Max + base);
            continue;
        } else if (P < base + Min) {
            printf("%.10f\n", base);
            continue;
        }

        vector<pair<double, double> > have[2];
        have[0].pb(mp(0, 0));
        int now = 0;
        Max = -1;
        double pp = P - base;
        for (int i = 0; i < n; ++i) {
            now ^= 1;
            vector<pair<double, double> > tmp  = have[now ^ 1];
            for (int j = 0; j < have[now ^ 1].size(); ++j) {
                tmp.pb(mp(have[now ^ 1][j].fi + data[i].fi, have[now ^ 1][j].se + data[i].se));
            }

            have[now].clear();
            sort(tmp.begin(), tmp.end());
            double left = -1, right = -1;
            for (int j = 0; j < tmp.size(); ++j) {
                if (left < 0) left = tmp[j].fi, right = tmp[j].se;
                
                if (tmp[j].fi <= right) right = max(right, tmp[j].se);
                else {
                    have[now].pb(mp(left, right));
                    if (left <= pp) Max = max(Max, min(pp, right));
                    left = tmp[j].fi, right = tmp[j].se;
                }
            }
            if (left > 0) {
                have[now].pb(mp(left, right));
                if (left <= pp) Max = max(Max, min(pp, right));
            }
        }

        
        printf("%.10f\n", base + Max);
    }
    return 0;
}
    
