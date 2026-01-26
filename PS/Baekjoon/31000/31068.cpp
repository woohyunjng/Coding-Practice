#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int A[MAX], B[MAX], S[MAX],
    P[MAX][3];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, SA, SB, ans = MAX, K = 0, X;
    vector<int> compA, compB;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        compA.push_back(A[i]), compB.push_back(B[i]);
    }

    sort(compA.begin(), compA.end()), compA.erase(unique(compA.begin(), compA.end()), compA.end()), SA = compA.size();
    sort(compB.begin(), compB.end()), compB.erase(unique(compB.begin(), compB.end()), compB.end()), SB = compB.size();

    for (int i = 1; i <= SA; i++)
        P[i][1] = MAX;

    for (int i = 1; i <= N; i++) {
        A[i] = lower_bound(compA.begin(), compA.end(), A[i]) - compA.begin() + 1;
        B[i] = lower_bound(compB.begin(), compB.end(), B[i]) - compB.begin() + 1;
        P[A[i]][0] = max(P[A[i]][0], B[i]), P[A[i]][1] = min(P[A[i]][1], B[i]), P[A[i]][2]++;
    }

    for (int i = 2; i <= SA; i++)
        P[i][0] = max(P[i - 1][0], P[i][0]), P[i][2] += P[i - 1][2];
    for (int i = SA - 1; i >= 1; i--)
        P[i][1] = min(P[i + 1][1], P[i][1]);

    for (int i = 1; i < SA; i++) {
        if (P[i][0] >= P[i + 1][1])
            continue;
        K++, S[K] = P[i][2];
    }

    for (int i = 1; i < K; i++) {
        X = lower_bound(S + 1, S + K + 1, (N + S[i]) / 2) - S;
        if (X <= K)
            ans = min(ans, max({S[i], S[X] - S[i], N - S[X]}) - min({S[i], S[X] - S[i], N - S[X]}));
        if (X - 1 > i)
            ans = min(ans, max({S[i], S[X - 1] - S[i], N - S[X - 1]}) - min({S[i], S[X - 1] - S[i], N - S[X - 1]}));
    }

    cout << (ans == MAX ? -1 : ans) << '\n';

    return 0;
}