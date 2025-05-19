#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100002;

int V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R, W;

    cin >> N >> Q;
    while (Q--) {
        cin >> L >> R >> W;
        V[L] += W, V[R + 1] -= W;
    }

    for (int i = 1; i <= N; i++)
        V[i] += V[i - 1];

    for (int i = 1; i <= N; i++)
        cout << V[i] << ' ';
    cout << '\n';

    return 0;
}