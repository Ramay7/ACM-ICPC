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

int T, cases = 0, R, C, H, V;
int num[110][110], cutR[110], cutC[110];
char mat[110][110];

inline int get(int x1, int y1, int x2, int y2) { // (x1, y1) is the right bottom, (x2, y2) is the left top
    if (!x2 || !y2) return num[x1][y1];
    return num[x1][y1] - num[x1][y2 - 1] - num[x2 - 1][y1] + num[x2 - 1][y2 - 1];
}

void relax() {
    for (int i = 1; i <= R; ++i) {
        int all = 1;
        for (int j = 1; j <= C; ++j) if (mat[i][j] != '.') {
            all = 0;
            break;
        }
        if (all) {
            for (int j = i; j < R; ++j) {
                for (int k = 1; k <= C; ++k) {
                    mat[j][k] = mat[j + 1][k];
                }
            }
            R--;
        }
    }

    for (int i = 1; i <= C; ++i) {
        int all = 1;
        for (int j = 1; j <= R; ++j) if (mat[j][i] != '.') {
            all = 0;
            break;
        }
        if (all) {
            for (int j = i; j < C; ++j) {
                for (int k = 1; k <= R; ++k) {
                    mat[k][j] = mat[k][j + 1];
                }
            }
            C--;
        }
    }
}

int main() {    
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &R, &C, &H, &V);

        for (int i = 1; i <= R; ++i) scanf("%s", mat[i] + 1);
        
        int total = 0;
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                num[i][j] = num[i - 1][j] + num[i][j - 1] - num[i - 1][j - 1];
                if (mat[i][j] == '@') {
                    total++;
                    num[i][j]++;
                }
            }
        }

        if (total == 0) {
            printf("Case #%d: POSSIBLE\n", ++cases);
            continue;
        }

        if (total % ((H + 1) * (V + 1)) != 0) {
            printf("Case #%d: IMPOSSIBLE\n", ++cases);
            continue;
        }

        int ave = total / ((H + 1) * (V + 1));
        int ave_col = total / (V + 1);
        int ave_row = total / (H + 1);
        int ok = 1;


        vector<int> cut_col;
        int pre_col = 1;
        cut_col.pb(0);
        for (int col = 1; col <= C; ++col) {
            int now = get(R, col, 1, pre_col);
            if (now > ave_col) {
                ok = 0;
                break;
            } else if (now == ave_col) {
                pre_col = col + 1;
                cut_col.pb(col);
            }
        }
        // cut_col.pb(C);

        if (!ok) {
            printf("Case #%d: IMPOSSIBLE\n", ++cases);
            continue;
        }

        vector<int> cut_row;
        cut_row.pb(0);
        int pre_row = 1;
        for (int row = 1; row <= R; ++row) {
            int now = get(row, C, pre_row, 1);
            if (now > ave_row) {
                ok = 0;
                break;
            } else if (now == ave_row) {
                pre_row = row + 1;
                cut_row.pb(row);
            }
        }
        // cut_row.pb(R);

        if (!ok) {
            printf("Case #%d: IMPOSSIBLE\n", ++cases);
            continue;
        }

        // printf("ave_row = %d ave_col = %d ave = %d\n", ave_row, ave_col, ave);
        // printf("cut_row: ");
        // for (auto x: cut_row) printf("%d ", x);
        // puts("");
        // printf("cut_col: ");
        // for (auto x: cut_col) printf("%d ", x);
        // puts("");

        assert(cut_row.size() != H + 1);
        assert(cut_col.size() != V + 1);
        for (int i = 1; i < cut_row.size(); ++i) {
            for (int j = 1; j < cut_col.size(); ++j) {
                int x1 = cut_row[i], y1 = cut_col[j];
                int x2 = cut_row[i - 1] + 1, y2 = cut_col[j - 1] + 1;
                //printf("x1 = %d y1 = %d x2 = %d y2 = %d\n", x1, y1, x2, y2);
                int now = get(x1, y1, x2, y2);
                if (now != ave) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
        }

        if (ok) printf("Case #%d: POSSIBLE\n", ++cases);
        else printf("Case #%d: IMPOSSIBLE\n", ++cases);
    }
    return 0;
}
    
