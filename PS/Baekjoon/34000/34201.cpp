#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200000;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, ans;

    cin >> N >> S, ans = N % 2 ? -S : S;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < (N + 1) / 2; i++)
        ans += A[N - 1 - i] << 1ll;
    for (int i = 0; i < N / 2; i++)
        ans -= A[i] << 1ll;

    cout << ans << '\n';

    return 0;
}