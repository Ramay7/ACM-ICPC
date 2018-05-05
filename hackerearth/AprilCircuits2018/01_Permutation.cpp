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

unordered_map<int, int> ma;

void init(int n) {
    int x = 0;
    for (int i = 1; i <= n; ++i) x = x * 10 + i;

    int pw[10] = {1};
    for (int i = 1; i < 9; ++i) pw[i] = 10 * pw[i - 1];

    queue<pair<int, int> > que;
    ma[x] = 0;
    que.push(mp(x, 0));
    while (!que.empty()) {
        PI now = que.front(); que.pop();

        int data[10];
        for (int i = 0; i < n; ++i) {
            data[n - 1 - i] = now.fi / pw[i] % 10;
        }
        for (int i = 0; i < 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int tmp[10];
                memcpy(tmp, data, sizeof (data));

                for (int k = 0; k < (j - i + 1) / 2; ++k) swap(tmp[i + k], tmp[j - k]);
                int nxt = 0;
                for (int k = 0; k < n; ++k) nxt = nxt * 10 + tmp[k];
                //printf("now.fi = %d nxt = %d\n", now.fi, nxt);
                if (ma.find(nxt) != ma.end()) continue;
                ma[nxt] = now.se + 1;
                que.push(mp(nxt, now.se + 1));
            }
        }
    }
}

int main() {    
    int n;
    cin >> n;
    init(n);
    int val = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        val = val * 10 + t;
    }
    cout << ma[val] << endl;
    return 0;
}
    
