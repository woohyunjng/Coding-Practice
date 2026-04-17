#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int fac[MAX];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X = 0;

    cin >> N >> K;

    fac[0] = 1;
    for (int i = 1; i <= 19; i++)
        fac[i] = fac[i - 1] * i;
    for (int i = 20; i <= N; i++)
        fac[i] = INF;

    for (int i = 1; i <= N - 1; i++) {
        for (int j = 1; j <= N; j++) {
            if (chk[(X + j) % N] || (X + j) % N == 0)
                continue;
            if (K > fac[N - 1 - i])
                K -= fac[N - 1 - i];
            else {
                cout << j << ' ', X = (X + j) % N, chk[X] = true;
                break;
            }
        }
    }
    cout << '\n';

    return 0;
}