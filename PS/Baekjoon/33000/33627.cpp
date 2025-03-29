#include <bits/stdc++.h>

using namespace std;
typedef array<int, 2> pr;

const int MAX = 1000005;

int A[MAX], B[MAX], S[MAX], X[MAX], front[MAX][2], back[MAX][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, V = 0, P = 1, ans = 0, i, j;
    cin >> N >> M >> K;

    for (i = 1; i <= N; i++)
        cin >> A[i];

    for (i = 1; i <= K; i++)
        cin >> X[i];
    X[++K] = M + 1;

    for (i = 1; i <= K + 1; i++) {
        if (X[i] > V + 1)
            B[P++] = X[i] - V - 1;
        V = X[i];
    }
    K = P - 1;

    fill(S, S + K + 1, 0);
    for (i = 1, j = 1; i <= N; i++) {
        while (B[j] - S[j] < A[i])
            j++;
        S[j] += A[i], front[i][0] = j, front[i][1] = S[j];
    }

    fill(S, S + K + 1, 0);
    for (i = N, j = K; i >= 1; i--) {
        while (B[j] - S[j] < A[i])
            j--;
        S[j] += A[i], back[i][0] = j, back[i][1] = S[j];
    }

    for (int i = 1; i <= N; i++) {
        if (front[i][0] != back[i][0])
            continue;
        ans += max(0, front[i][1] - (B[front[i][0]] - back[i][1]));
    }

    cout << ans << '\n';

    return 0;
}