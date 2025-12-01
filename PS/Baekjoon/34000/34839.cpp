#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int P[MAX];

void alice() {
    int N, X = 0;
    string S;

    cin >> N >> S;
    for (int i = 1; i <= N; i++)
        P[i] = P[i - 1] + (S[i - 1] == '(' ? 1 : -1);

    for (int i = 1; i <= N; i++)
        if (P[i] < P[X])
            X = i;

    cout << X * (N + 1) - P[X] << '\n';
}

void bob() {
    int N, W, X = 0, A, B;
    string S;

    cin >> N >> W >> S;
    for (int i = 1; i <= N; i++)
        P[i] = P[i - 1] + (S[i - 1] == '(' ? 1 : -1);
    for (int i = 0; i <= N; i++)
        P[i] += -P[N];

    for (int i = 1; i <= N; i++)
        if (P[i] < P[X])
            X = i;

    A = W / (N + 1), B = -W % (N + 1);
    X = B <= P[X] ? A : (X + N);

    cout << X + 1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;

    cin >> T;
    if (T == 1)
        alice();
    else
        bob();

    return 0;
}