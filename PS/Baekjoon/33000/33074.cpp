#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

typedef array<int, 2> pr;

int S[MAX], M[MAX], dp[MAX], V[MAX];
vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T = 0, L = 1, V[2] = {MAX, MAX};
    string _S;

    cin >> N >> _S;
    for (int i = 1; i <= N; i++) {
        S[i] = _S[i - 1] - '0', M[i] = S[i] + M[i - 1];
        if (S[i] == 1) {
            for (int j = L - 1; j < i; j++)
                arr[min(2 * (i - 1) - j, (N + j) % 2 == 0 ? N : N - 1)].push_back(j);
            L = i + 1;
        }
    }

    for (int i = 2; i <= N; i++) {
        dp[i] = S[i] * S[i - 1] + dp[i - 2];

        if (S[i] == 1)
            T = 0, V[0] = V[1] = MAX;
        else
            T++, V[i & 1] = min(V[i & 1], i - T * 2 >= 0 ? dp[i - T * 2] : MAX);

        dp[i] = min(dp[i], V[i & 1]);
        for (int j : arr[i])
            dp[i] = min(dp[i], dp[j]);
    }

    cout << dp[N] << '\n';

    return 0;
}