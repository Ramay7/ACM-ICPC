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
const double eps = 1e-7;

int T, n, m, cases = 0, tot;
int A[N], B[N], C[N], need[N];

struct Node {
    int value, need;

    bool operator < (const Node& rhs) const {
        return need < rhs.need;
    }
} data[N];

int main() { 
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);

        tot = 0;
        for (int i = 1; i < n; ++i) {
            int p = round(100.0 * i / n);
            if (p > i * 100 / n) {
                B[tot] = i;
                C[tot++] = p;
            }
        }

        int sum = 0, left = 0;
        for (int i = 1; i <= m; ++i) {
            int t;
            scanf("%d", &t);
            data[i].value = t;

            int id = lower_bound(B, B + tot, t) - B;
            if (id == tot || B[id] == t) {
                data[i].need = 0;
            } else {
                data[i].need = B[id] - t;
            }

            left += t;
            sum += round(t * 100.0 / n);
        }
        left = n - left;

        int ans = sum + round(100.0 * left / n);

        if (tot > 0) {
            int tmp = left / B[0] * C[0] + round((left % B[0]) * 100.0 / n);
            ans = max(ans, sum + tmp);
        }

        sort(data + 1, data + m + 1);
        for (int i = 1; i <= m; ++i) {
            if (data[i].need == 0) continue;
            if (left < data[i].need) break;
            left -= data[i].need;
            sum -= round(data[i].value * 100.0 / n);
            sum += round((data[i].need + data[i].value) * 100.0 / n) ;

            int x = round(left * 100.0 / n);
            if (tot > 0) {
                x = max(x, left / B[0] * C[0] + int(round((left % B[0]) * 100.0 / n)));
            }
            ans = max(ans, sum + x);
        }

        printf("Case #%d: %d\n", ++cases, ans);
    }   
    return 0;
}
    
