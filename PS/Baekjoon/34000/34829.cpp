#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int A[MAX];
map<int, bool> chk;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, X;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], chk[A[i]] = true;

    sort(A + 1, A + N + 1), ans = A[N];

    for (int i = 1; i <= N; i++) {
        if (!chk[i - 1])
            break;
        if (i * 2 <= N)
            X = A[N - i + 1];
        else
            X = A[N / 2 + 1];
        ans = max(ans, i + X);
    }

    cout << ans << '\n';

    return 0;
}