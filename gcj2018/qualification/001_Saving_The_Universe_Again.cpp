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

int T, D, len, cases = 0;
char str[33];

int get() {
    int ret = 0, bases = 1;
    for (int i = 0; i < len; ++i) {
        if (str[i] == 'C') bases *= 2;
        else ret += bases;
    }
    return ret;
}

int main() {   
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &D, str);
        int cnt = 0;
        len = strlen(str);
       // puts(str);
        while (1) {
            int val = get();
         //   printf("val = %d\n", val);
            if (val <= D) break;

            int change = 0;
            for (int i = len - 1; i >= 1; --i) {
                if (str[i] == 'S' && str[i - 1] == 'C') {
                    swap(str[i], str[i - 1]);
                    change = 1;
                    break;
                }
            }
            if (!change) {
                cnt = -1;
                break;
            } else cnt++;
        }
        if (cnt == -1) printf("Case #%d: IMPOSSIBLE\n", ++cases);
        else printf("Case #%d: %d\n", ++cases, cnt);
    }
    return 0;
}
    
