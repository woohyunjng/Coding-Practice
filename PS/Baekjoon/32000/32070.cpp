#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int V[MAX], uf[MAX], C[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    uf[max(X, Y)] = min(X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, ans;
    bool chk = true;

    cin >> N, ans = N;
    for (int i = 1; i <= N; i++)
        uf[i] = i;

    for (int i = 1; i <= N; i++) {
        cin >> A >> B, V[B]++;
        uni(A, B), ans -= (A == B) * 2;
    }
    for (int i = 1; i <= N; i++)
        C[find(i)] += V[i] == 2;

    for (int i = 1; i <= N; i++) {
        if (find(i) != i)
            continue;
        ans++, chk &= C[i] < 2;
    }

    if (!chk)
        ans = -1;
    cout << ans << '\n';

    return 0;
}