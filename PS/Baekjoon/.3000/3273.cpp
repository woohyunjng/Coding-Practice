#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MAX_V = 2000001;

int A[MAX], cnt[MAX_V];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ans = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], cnt[A[i]]++;

    cin >> X;
    for (int i = 1; i * 2 <= X; i++) {
        if (i == X - i)
            ans += cnt[i] * (cnt[i] - 1) / 2;
        else
            ans += cnt[i] * cnt[X - i];
    }

    cout << ans << '\n';

    return 0;
}