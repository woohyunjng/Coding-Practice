#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = MAX * MAX, V, C;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], A[i] %= 2;

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= N; j++)
            A[j] ^= 1;

        V = 0, C = 0;
        for (int j = 1; j <= N; j++)
            C += A[j] == 0, V += A[j] == 0 ? j - C : 0;
        ans = min(ans, V);
    }

    cout << ans << '\n';

    return 0;
}