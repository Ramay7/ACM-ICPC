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

int T, cases = 0, R, C, H, V, ave;
int num[110][110], cutR[110], cutC[110];
char mat[110][110];

inline int get(int x1, int y1, int x2, int y2) {
    if (!x2 || !y2) return num[x1][y1];
    return num[x1][y1] - num[x1][y2 - 1] - num[x2 - 1][y1] + num[x2 - 1][y2 - 1];
}

bool check(vector<int> chooseRow, vector<int> chooseCol) {
    int flag = 1;
    for (int p = 1; p < chooseRow.size(); ++p) {
        for (int q = 1; q < chooseCol.size(); ++q) {
            int x1 = chooseRow[p], y1 = chooseCol[q];
            int x2 = chooseRow[p - 1], y2 = chooseCol[q - 1];
            int now = get(x1, y1, x2 + 1, y2 + 1);
            if (now != ave) return false;
        }
    }
    return true;
}

bool dfs_row(int col, int nowRow, int preRow, int cutRow, vector<int> chooseRow, vector<int> chooseCol) {
    if (cutRow > H + 1) return false;
    if (nowRow == R + 1) {

        if (preRow == R && cutRow == H + 1) {
            if(check(chooseRow, chooseCol)) return true;
        }
        return false;
    }

    int d = get(nowRow, col, preRow + 1, 1);
  
    if (d > ave) return false;
    else if (d == ave) {
        vector<int> tmp = chooseRow;
        tmp.pb(nowRow);
        bool ret = dfs_row(col, nowRow + 1, nowRow, cutRow + 1, tmp, chooseCol);
        if (ret) return true;
    }
    bool ret = dfs_row(col, nowRow + 1, preRow, cutRow, chooseRow, chooseCol);
    if (ret) return true;
    else return false;
}

bool dfs_col(int row, int nowCol, int preCol, int cutCol, vector<int> chooseCol) { // cut first row
    if (cutCol > V + 1) return false;
    if (nowCol == C + 1) {
        if (preCol == C&& cutCol == V + 1) {

            for (int nxt = row + 1; nxt <= R; ++nxt) {
                vector<int> chooseRow;
                chooseRow.pb(row);
                bool ret = dfs_row(chooseCol[0], nxt, row, 1, chooseRow, chooseCol);
                if (ret) return true;
            }
        } 
        return false;
    }

    int d = get(row, nowCol, 1, preCol + 1);
    if (d > ave) return false;
    else if (d == ave) {
        vector<int> tmp = chooseCol;
        tmp.pb(nowCol);

        bool ret = dfs_col(row, nowCol + 1, nowCol, cutCol + 1, tmp);
        if (ret) return true;
    }
    bool ret = dfs_col(row, nowCol + 1, preCol, cutCol, chooseCol);
    if (ret) return true;
    else return false;
}


int main() {    
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &R, &C, &H, &V);

        int total = 0;
        for (int i = 1; i <= R; ++i) {
            scanf("%s", mat[i] + 1);
            
            for (int j = 1; j <= C; ++j) {
                num[i][j] = num[i][j - 1] + num[i - 1][j] - num[i - 1][j - 1];
                if (mat[i][j] == '@') num[i][j]++, total++;
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

        ave = total / ((H + 1) * (V + 1));

        int ok = 0;
        for (int row = 1; row <= R; ++row) {
            vector<int> chooseCol;
            if (dfs_col(row, 1, 0, 0, chooseCol)) {
                ok = 1;
                break;
            }
        }

        if (ok) printf("Case #%d: POSSIBLE\n", ++cases);
        else printf("Case #%d: IMPOSSIBLE\n", ++cases);
    }
    return 0;
}
    
