#include <bits/stdc++.h>
using namespace std;

const int MAX = 300001;

int N, A[MAX], tree[MAX];

void update(int n, int val) {
    while (n <= N)
        tree[n] += val, n += n & -n;
}

int query(int n) {
    int res = 0;
    while (n)
        res += tree[n], n -= n & -n;
    return res;
}

int chk(int X) {
    if (X + 2 > N || X <= 0)
        return 0;
    int V[3] = {A[X], A[X + 1], A[X + 2]};
    for (int i = 0; i < 3; i++)
        V[i] ^= query(X + i) & 1;
    return V[0] != V[1] && V[1] != V[2];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, T, L, R, ans = 0;
    string S;

    cin >> N >> S;
    for (int i = 1; i <= N; i++)
        A[i] = S[i - 1] == '>';

    for (int i = 1; i + 2 <= N; i++)
        ans += A[i] != A[i + 1] && A[i + 1] != A[i + 2];

    cin >> Q;
    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> L >> R;

            ans -= chk(L - 2) + chk(L - 1) + (L != R ? chk(R - 1) : 0) + chk(R);
            update(L, 1), update(R + 1, -1);
            ans += chk(L - 2) + chk(L - 1) + (L != R ? chk(R - 1) : 0) + chk(R);
        } else
            cout << ans << '\n';
    }

    return 0;
}