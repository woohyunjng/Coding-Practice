#include <bits/stdc++.h>
#define int long long

#define MAX 1010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

struct Clock {
    int N, M;

    void calculate() {
        int K = abs(N - M), res;
        for (res = 1; res <= 1440; res++)
            if (K * res % 1440 == 0)
                break;

        K = N * res;
        int H = (res + (int)ceil(K / 60)) % 24, M = K % 60;
        printf("%02lld:%02lld\n", H, M);
    }
};

signed main() {
    int T;
    Clock X;
    cin >> T;

    while (T--) {
        scanf("%lld %lld", &X.N, &X.M);
        X.calculate();
    }

    return 0;
}