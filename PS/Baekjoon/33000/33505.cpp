#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 400001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, ans;

    cin >> T;
    while (T--) {
        cin >> N >> M, ans = INF;
        for (int i = 1; i <= N; i++)
            cin >> A[i], A[i] %= M;
        sort(A + 1, A + N + 1);

        for (int i = N + 1; i <= N << 1; i++)
            A[i] = A[i - N] + M;
        for (int i = 1; i <= N << 1; i++)
            S[i] = S[i - 1] + A[i];

        for (int i = 1; i <= N + 1; i++)
            ans = min(ans, S[i + N - 1] - S[i - 1 + (N + 1) / 2] - (S[i - 1 + N / 2] - S[i - 1]));

        cout << ans << '\n';
    }

    return 0;
}