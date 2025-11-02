#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
const int MAX_LOG = 19;

int A[MAX], V[1 << MAX_LOG];
bool vst[1 << MAX_LOG];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int C, N, X, Y;
    string S;

    queue<int> q;

    cin >> C >> N;
    for (int i = 0; i < N; i++) {
        cin >> S, X = 0;
        for (int j = 0; j < C; j++) {
            A[i] |= (S[j] == 'G') << j;
            X |= (S[j] == 'H') << j;
        }
        if (!vst[X])
            q.push(X), vst[X] = true;
    }

    while (!q.empty()) {
        X = q.front(), q.pop();
        for (int i = 0; i < C; i++) {
            Y = X ^ (1 << i);
            if (!vst[Y])
                V[Y] = V[X] + 1, q.push(Y), vst[Y] = true;
        }
    }

    for (int i = 0; i < N; i++)
        cout << C - V[A[i]] << '\n';

    return 0;
}