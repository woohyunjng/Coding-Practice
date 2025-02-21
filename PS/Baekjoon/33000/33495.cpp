#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 600000;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, st, en, mid, X, cnt[3] = {0}, ans, V, K = 0;
    bool flag;
    string S;

    cin >> S, N = S.size();
    for (int i = 1; i <= N; i++) {
        if (S[i - 1] == 'K')
            A[i] = 0;
        else if (S[i - 1] == 'S')
            A[i] = 1;
        else
            A[i] = 2;
        cnt[A[i]]++;
    }

    st = 0, en = N;
    while (st <= en) {
        mid = st + en >> 1;
        flag = (mid + 2) / 3 <= cnt[0] && (mid + 1) / 3 <= cnt[1] && mid / 3 <= cnt[2];
        if (flag)
            X = mid, st = mid + 1;
        else
            en = mid - 1;
    }

    V = (X + 2) % 3;
    for (int i = N; i >= 1; i--) {
        if (A[i] == V && X > 0)
            V = (V + 2) % 3, X--;
        else
            K++;
    }
    ans = K;

    cout << ans << '\n';

    return 0;
}