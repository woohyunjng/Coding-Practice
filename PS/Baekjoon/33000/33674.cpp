#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 101;

int S[MAX], V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, D, K, ans = 0;
    bool flag;

    cin >> N >> D >> K;
    for (int i = 1; i <= N; i++)
        cin >> S[i];

    for (int i = 1; i <= D; i++) {
        flag = false;
        for (int i = 1; i <= N; i++)
            V[i] += S[i], flag |= V[i] > K;
        if (flag) {
            ans++;
            for (int i = 1; i <= N; i++)
                V[i] = S[i];
        }
    }

    cout << ans << '\n';

    return 0;
}