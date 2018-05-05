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
const int N = 20010;

struct Trie {
    int root, tot;
    int child[N * 30][2], cnt[N * 30];

    void init() {
        root = tot = 1;
        child[1][0] = child[1][1] = 0;
        cnt[1] = 1;
    }

    void insert(const int x) {
        int* cur = &root;
        for (int i = 30; i >= 0; --i) {
            cur = &child[*cur][(x >> i) & 1];
            if (*cur == 0) {
                *cur = ++tot;
                child[tot][0] = child[tot][1] = 0;
                cnt[tot] = 0;
            }
            cnt[*cur] ++;
        }
    }

    void remove(const int x) {
        int *cur = &root;
        for (int i = 30; i >= 0; --i) {
            cur = &child[*cur][(x >> i) & 1];
            cnt[*cur]--;
        }
    }

    int query(const int x) {
        int ret = 0;
        int* cur = &root;
        for (int i = 30; i >= 0; --i) {
            int now = (x >> i) & 1, store = *cur;
            if (now == 0) {
                cur = &child[*cur][1];
                if (cnt[*cur]) ret += (1 << i);
                else cur = &child[store][0];
            } else {
                cur = &child[*cur][0];
                if (cnt[*cur]) ret += (1 << i);
                else cur = &child[store][1];
            }
        }
        return ret;
    }
} trie;

const int block = 200;

int n, m, t;
int A[N], B[N];
int prefix[block][N], suffix[block][N];

int main() {    
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &A[i]);
        B[i] = A[i];
        A[i] ^= A[i - 1];
    }
    for (int i = n - 1; i >= 1; --i) B[i] ^= B[i + 1];

    for (int i = 1; i <= n; i += block) {
        int id = (i - 1) / block, Max = 0;
        trie.init();
        for (int j = i; j <= n; ++j) {
            trie.insert(A[j - 1]);
            Max = max(Max, trie.query(A[j]));
            prefix[id][j] = Max;
        }
    }

    for (int i = block; i <= n; i += block) {
        int id = i / block - 1, Max = 0;
        trie.init();
        for (int j = i; j >= 1; --j) {
            trie.insert(B[j + 1]);
            Max = max(Max, trie.query(B[j]));
            suffix[id][j] = Max;
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        int l = (x + ans * t) % n + 1, r = (y + ans * t) % n + 1;
        if (l > r) swap(l, r);

        ans = 0;
        trie.init();
        if (r - l + 1 <= block) {
            for (int j = l; j <= r; ++j) {
                trie.insert(A[j - 1]);
                ans = max(ans, trie.query(A[j]));
            }
        } else {
            int il = (l - 1 + block - 1) / block, ir = r / block - 1;
            ans = max(prefix[il][r], suffix[ir][l]);

            for (int j = l; j <= il * block; ++j) trie.insert(A[j - 1]);
            for (int j = (ir + 1) * block + 1; j <= r; ++j) {
                ans = max(ans, trie.query(A[j]));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
    
