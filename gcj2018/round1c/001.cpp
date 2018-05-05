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

int T, cases = 0;
int L, n;
char str[2010][30];

int main() {    
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &L);
        for (int i = 0; i < n; ++i) scanf("%s", str[i]);

        int find = -1, tp = -1, locate = -1;
        for (int i = 0; i < n; ++i) {
            for (int pos = 1; pos < L; ++pos) {
                char pre = str[i][pos - 1];

                int vis[30], all[30];
                memset(vis, 0, sizeof (vis));
                memset(all, 0, sizeof (all));

                for (int j = 0; j < n; ++j) {

                    int same = 1;
                    for (int k = 0; k < pos; ++k) if (str[i][k] != str[j][k]) same = 0;
                    if (same) vis[str[j][pos] - 'A'] = 1;
                    all[str[j][pos] - 'A'] = 1;
                }

                for (int j = 0; j < 26; ++j) {
                    if (!vis[j] && all[j]) {
                        find = i;
                        tp = j + 'A';
                        locate = pos;
                        break;
                    }
                }
                if (find != -1) break;
            }
            if (find != -1) break;
        }

        printf("Case #%d: ", ++cases);
        if (find != -1) {
            for (int i = 0; i < L; ++i) {
                if (i == locate) printf("%c", tp);
                else putchar(str[find][i]);
            }
            puts("");
        } else puts("-");
    }
    return 0;
}
    
