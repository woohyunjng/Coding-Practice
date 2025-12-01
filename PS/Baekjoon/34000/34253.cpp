#include <bits/stdc++.h>
using namespace std;

const int MAX = 22;

bool V[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, A;
    string S;

    queue<int> q;

    cin >> N >> K;

    bool bef = false;
    for (int i = 1; i <= N; i++) {
        cin >> S, A = 0;
        if (bef)
            reverse(S.begin(), S.end());
        for (int j = 0; j < K; j++) {
            A <<= 1;
            if (S[j] == '1')
                A |= 1;
        }
        cout << (V[A] ? "WellKnown" : "AdHoc") << '\n';
        bef = (!V[A]);

        if (!V[A])
            q.push(A), V[A] = true;
        while (!q.empty()) {
            X = q.front(), q.pop();
            for (int j = 0; j < K; j++) {
                if (!(X & (1 << j)) || V[X ^ (1 << j)] != 0)
                    continue;
                q.push(X ^ (1 << j)), V[X ^ (1 << j)] = true;
            }
        }
    }

    return 0;
}
