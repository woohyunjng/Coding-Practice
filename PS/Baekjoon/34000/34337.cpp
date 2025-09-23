#include <bits/stdc++.h>
using namespace std;

int A[5], val;

void dfs(int n) {
    int res = 0, K;
    bool flag = true;

    if (n == 5) {
        for (int i = 1; i <= 6; i++) {
            K = 0;
            for (int j = 0; j < 5; j++)
                if (A[j] == i)
                    K += i;
            res = max(res, K);
        }
        for (int j = 1; j < 5; j++)
            flag &= A[j] == A[0];
        val += flag ? 50 : res;
        return;
    }

    for (int i = 1; i <= 6; i++)
        A[n] = i, dfs(n + 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int V[5], C, ans = 0;

    for (int i = 0; i < 5; i++)
        cin >> V[i];

    for (int i = 0; i < (1 << 5); i++) {
        C = 0;
        for (int j = 0; j < 5; j++)
            if (!(i & (1 << j)))
                A[C++] = V[j];

        val = 0, dfs(C);

        for (int j = 0; j < (5 - (int)__builtin_popcount(i)); j++)
            val *= 6;
        ans = max(ans, val);
    }

    cout << ans << '\n';

    return 0;
}