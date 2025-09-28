#include <bits/stdc++.h>
using namespace std;

const int MAX_A = 26;
const int MAX = 200001;

int S[MAX_A][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, C, L, R;
    char _C;

    string _S;
    cin >> _S, N = _S.size();

    for (int i = 1; i <= N; i++)
        S[_S[i - 1] - 'a'][i] = 1;

    for (int i = 0; i < MAX_A; i++)
        for (int j = 1; j <= N; j++)
            S[i][j] += S[i][j - 1];

    cin >> Q;
    while (Q--) {
        cin >> _C >> L >> R, C = _C - 'a';
        cout << S[C][R + 1] - S[C][L] << '\n';
    }

    return 0;
}