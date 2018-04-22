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


int main() {    
    int T, cases = 0;
    double A;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf", &A);
        printf("Case #%d:\n", ++cases);
       // printf("A = %.10f sqrt(2) = %.10f\n", A, sqrt(2.0));
        if (A * A > 2.0) {
            printf("0.5 0 0\n");
            printf("0.5 0 0\n");
            printf("0.5 0 0\n");
            continue;
        }
        double c = sqrt(2 - A*A);
        double ccos = (A + c) / 4, ssin = fabs((c - A) / 4);

        printf("0.5 0 0\n");
        printf("0 %.10f %.10f\n", -ccos, ssin);
        printf("0 %.10f %.10f\n", ssin, ccos);
       // printf("%.10f\n", 0.5 * sin(pi / 4));
    }
    return 0;
}
    
